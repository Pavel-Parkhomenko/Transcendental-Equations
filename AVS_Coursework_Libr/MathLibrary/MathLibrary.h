#pragma once
#include <string>
// MathLibrary.h - Contains declarations of math functions
#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

//-----MY FUNCT-------//
extern "C" MATHLIBRARY_API double sin_funct(double value);
extern "C" MATHLIBRARY_API double cos_funct(double value);
extern "C" MATHLIBRARY_API double tg_funct(double value);
extern "C" MATHLIBRARY_API double ctg_funct(double value);
extern "C" MATHLIBRARY_API double sqrt_funct(double value);

extern "C" MATHLIBRARY_API double mul_funct(double a, double b);
extern "C" MATHLIBRARY_API double div_funct(double a, double b);
extern "C" MATHLIBRARY_API double add_funct(double a, double b);
extern "C" MATHLIBRARY_API double sub_funct(double a, double b);
extern "C" MATHLIBRARY_API double pow_funct(double a, double b);