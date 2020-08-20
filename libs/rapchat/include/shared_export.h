#if defined(_WIN32)
    #if defined(RAPCHAT_LIBRARY)
        #define RAPCHAT_SHARED_EXPORT __declspec(dllexport)
    #else
        #define RAPCHAT_SHARED_EXPORT __declspec(dllimport)
    #endif
#else
    #define RAPCHAT_SHARED_EXPORT
#endif