#include "../include/plugcontroller.h"
#include "../include/plugids.h"

#include "base/source/fstreamer.h"
#include "pluginterfaces/base/ibstream.h"

using namespace VSTGUI;

namespace Steinberg {
	namespace BadFuzz {

		//-----------------------------------------------------------------------------
		tresult PLUGIN_API PlugController::initialize(FUnknown* context)
		{
			tresult result = EditController::initialize(context);
			if (result == kResultTrue)
			{
				//---Create Parameters------------
				parameters.addParameter(STR16("Bypass"), 0, 1, 0,
					Vst::ParameterInfo::kCanAutomate | Vst::ParameterInfo::kIsBypass,
					HelloWorldParams::kBypassId);

				parameters.addParameter(STR16("Parameter 1"), STR16("dB"), 0, .5,
					Vst::ParameterInfo::kCanAutomate, HelloWorldParams::kParamVolId, 0,
					STR16("Param1"));
			}
			return kResultTrue;
		}

		//------------------------------------------------------------------------
		IPlugView* PLUGIN_API PlugController::createView(const char* name)
		{
			if (name && strcmp(name, "editor") == 0)
			{
				auto* view = new VST3Editor(this, "view", "plug.uidesc");
				return view;
			}
			return nullptr;
		}

		//------------------------------------------------------------------------
		tresult PLUGIN_API PlugController::setComponentState(IBStream* state)
		{
			if (!state)
				return kResultFalse;

			IBStreamer streamer(state, kLittleEndian);

			float savedParam1 = 0.f;
			if (streamer.readFloat(savedParam1) == false)
				return kResultFalse;
			setParamNormalized(HelloWorldParams::kParamVolId, savedParam1);

			// read the bypass
			int32 bypassState;
			if (streamer.readInt32(bypassState) == false)
				return kResultFalse;
			setParamNormalized(kBypassId, bypassState ? 1 : 0);

			return kResultOk;
		}

		//------------------------------------------------------------------------
	} // namespace
} // namespace Steinberg
