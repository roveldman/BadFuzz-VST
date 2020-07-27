
#pragma once

namespace Steinberg {
namespace BadFuzz {

// HERE are defined the parameter Ids which are exported to the host
enum HelloWorldParams : Vst::ParamID
{
	kBypassId = 100,

	kParamVolId = 102,
	kParamOnId = 1000

};


// HERE you have to define new unique class ids: for processor and for controller
// you can use GUID creator tools like https://www.guidgenerator.com/
static const FUID MyProcessorUID (0xBD58B550, 0xF9E5634E, 0x9D2EFF39, 0xEA0927B1);
static const FUID MyControllerUID (0xA0B1A6F4, 0x005D9B47, 0x967177E3, 0x7A671891);

//------------------------------------------------------------------------
} // namespace HelloWorld
} // namespace Steinberg
