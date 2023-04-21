// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "MathLibrary.h"

double sin_funct(double value) {
	double y;
	__asm {
		finit
		fld value
		fsin
		fstp y
	}
	return y;
}
double cos_funct(double value) {
	double y;
	__asm {
		finit
		fld value
		fcos
		fstp y
	}
	return y;
}
double tg_funct(double value) {
	double y;
	__asm {
		finit
		fld value
		fptan
		fxch st(1)
		fstp y
	}
	return y;
}
double ctg_funct(double value) {
	double y;
	__asm {
		finit
		fld value
		fptan
		fdiv
		fstp y
	}
	return y;
}
double sqrt_funct(double value) {
	double y;
	__asm {
		finit
		fld value
		fsqrt
		fstp y
	}
	return y;
}

//-----//

double mul_funct(double a, double b) {
	double y;
	__asm {
		finit
		fld a
		fmul b
		fstp y
	}
	return y;
}
double div_funct(double a, double b) {
	double y;
	__asm {
		finit
		fld a
		fdiv b
		fstp y
	}
	return y;
}
double add_funct(double a, double b) {
	double y;
	__asm {
		finit
		fld a
		fadd b
		fstp y
	}
	return y;
}
double sub_funct(double a, double b) {
	double y;
	__asm {
		finit
		fld a
		fsub b
		fstp y
	}
	return y;
}

double pow_funct(double a, double b) {
	double y;
	__asm {
		finit
		fld a
		fld b
		fxch st(1)
		fldln2
		fxch st(1)
		fyl2x
		fmulp st(1), st(0)
		fldl2e
		fmul
		fld st
		frndint
		fsub st(1), st
		fxch st(1)
		f2xm1
		fld1
		fadd
		fscale
		fstp st(1)
		fstp y
	}
	return y;
}