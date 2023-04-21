#pragma once
#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

#include <stdexcept>
using namespace std;

extern "C" __declspec(dllexport) void __stdcall GetInterval(double* answs, int len);

extern "C" __declspec(dllexport) void __stdcall SetFunc(char* f, int len);

extern "C" __declspec(dllexport) double __stdcall Add(double a, double b);

extern "C" __declspec(dllexport) void __stdcall PointsYS(double* ys, int len);

//extern "C" __declspec(dllexport) void __stdcall GetArr(double* arr, int len);

extern "C" __declspec(dllexport) void __stdcall SetAttribute(double aa, double bb, double epss);

//extern "C" __declspec(dllexport) void __stdcall GetAnswer(char answers[]);