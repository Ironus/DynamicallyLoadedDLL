#include "DynamicallyLoadedDLL.h"

namespace DynamicallyLoaded {
	#ifdef __cplusplus
	extern "C" {
	#endif
		unsigned int stringLength(std::string _string) {
			return _string.length();
		}
	}
}