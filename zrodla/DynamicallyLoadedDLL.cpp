#include "DynamicallyLoadedDLL.h"

namespace DynamicallyLoaded {
	extern "C" {
		unsigned int stringLength(std::string _string) {
			return _string.length();
		}
	}
}