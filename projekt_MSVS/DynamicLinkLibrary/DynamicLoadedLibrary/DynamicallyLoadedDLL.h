#ifdef DYNAMICALLYLOADEDDLL_EXPORTS
#define DYNAMICALLYLOADEDDLL_API __declspec(dllexport) 
#else
#define DYNAMICALLYLOADEDDLL_API __declspec(dllimport) 
#endif

#pragma once
#include <string>

namespace DynamicallyLoaded {
	#ifdef __cplusplus
	extern "C" 
	#endif
		DYNAMICALLYLOADEDDLL_API unsigned int stringLength(std::string _string);
}