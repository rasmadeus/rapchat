#pragma once

#if defined(_WIN32)
#if defined(RAP_LIBRARY)
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif
#else
#define DECLSPEC
#endif
