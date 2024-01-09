#pragma once

#include <vector>
#include <string>


namespace tl
{
    inline const char* version()
    {
        return "1.0.0"; 
    }
}

#ifdef _WIN32
  #define TRAININGLIB_EXPORT __declspec(dllexport)
#else
  #define TRAININGLIB_EXPORT
#endif

TRAININGLIB_EXPORT void trainingLib();
TRAININGLIB_EXPORT void trainingLib_print_vector(const std::vector<std::string> &strings);
