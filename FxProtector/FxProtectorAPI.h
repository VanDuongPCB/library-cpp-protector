#pragma once

#ifdef FxProtector_EXPORTS
#define FX_PROTECTOR_API __declspec(dllexport)
#else
#define FX_PROTECTOR_API __declspec(dllimport)
#endif // FxCommonUI_EXPORTS
