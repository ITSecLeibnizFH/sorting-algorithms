// This code has been copied from:
// https://stackoverflow.com/questions/2349776/how-can-i-benchmark-c-code-easily

#ifdef WIN32

#include <windows.h>
double get_time()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart/(double)f.QuadPart;
}

#else

#include <sys/time.h>
#include <sys/resource.h>
double get_time()
{
    struct timeval t;
    struct timezone *tzp;
    // We don't care about *tzp because we only need the delta between two subsequent calls to this function.
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

#endif
