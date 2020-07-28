
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
static const FUID MyProcessorUID (0xfc9079e7, 0x6c6c33c2, 0x7af85b48, 0x4cb4961d);
static const FUID MyControllerUID (0x7c9d007d, 0x25eac6cb, 0x12a7b1ba, 0x33449123);

//------------------------------------------------------------------------
} // namespace HelloWorld
} // namespace Steinberg
