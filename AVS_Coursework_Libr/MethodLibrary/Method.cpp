#include "Method.h"
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include <iostream>
#include <regex>
#include <string>
#include <stack>
#include <fstream>
#include <windows.h>
#include <list>
#include <math.h>
//#include "MathLibrary.h"

using namespace std;

bool CheckCorrectInput(string s, double x, vector<string>& splitedString, regex regexFunc);
vector<string> PolishNotation(vector<string> splitedString);
void GoBackByBrakets(vector<string>& reversePolishStr, stack<string>& st);
void GoBackByOperator(vector<string>& reversePolishStr, stack<string>& st, int priority);
int GetPriority(char ch);
bool IsFunc(string s);
bool IsBracket(string s);
bool IsOperator(string s);
double Calculate(vector<string> reversePolishStr, bool& flag);
double CalculateFunc(double value, string s);
double CalculateOperation(double a, double b, string s);
double AnswerMethod(vector<string> splStr, double a, double b, double eps);
double Funct(double x, vector<string> splitedString);
double DF1(double x, double eps, vector<string> splStr);
double DF2(double x, double eps, vector<string> splStr);

string funct;
double* xs;
double* ys;
double a;
double b; 
double eps;
string answersStr = "";

__declspec(dllexport)
double __stdcall Add(double a, double b) {
	return a + b;
}

__declspec(dllexport)
void __stdcall SetAttribute(double aa, double bb, double epss) {

	a = aa;
	b = bb;
	eps = epss;
}

__declspec(dllexport)
void __stdcall SetFunc(char* f, int len) {
	for (int i = 0; i < len; i++) {
		funct += f[i];
	}
}

__declspec(dllexport)
void __stdcall GetInterval(double* answs, int len)
{
	bool flag = true;
	regex regexFunc("(\\d+(\\.|,\\d+)?)|[\\+\\-\\^\\*\\/\\(\\)]|sin\\(|cos\\(|tg\\(|ctg\\(|exp\\(|log\\(|log10\\(|sqrt\\(");
	vector<string> splStr;
	list<double> lst;

	CheckCorrectInput(funct, a, splStr, regexFunc);
	for (double i = a; i < b; i = i + eps) {
		if (Funct(i, splStr) * Funct(i + eps, splStr) <= 0)
		{
			lst.push_back(AnswerMethod(splStr, i, i + eps, eps));
			flag = false;
		}
	}
	if (flag == true) {
		int j = 0;
		answs = nullptr;
	}
	else {
		int j = 0;
		for (double var : lst)
		{
			answs[j] = var;
			j++;
		}
	}
}

double AnswerMethod(vector<string> splStr, double a, double b, double eps)
{
	double x0;
	double xn;
	if (Funct(a, splStr) * DF2(a, eps, splStr) > 0)
		x0 = a;
	else
		x0 = b;

	xn = x0 - Funct(x0, splStr) / DF1(x0, eps, splStr);

	while (fabs(x0 - xn) > eps)
	{
		x0 = xn;
		xn = x0 - Funct(x0, splStr) / DF1(x0, eps, splStr);
	}
	return xn;
}

double DF1(double x, double eps, vector<string> splStr) {
	return (Funct(x + eps, splStr) - Funct(x, splStr)) / eps;
}

double DF2(double x, double eps, vector<string> splStr) {
	return 	(Funct(x + eps, splStr) - 2 * Funct(x, splStr) + Funct(x - eps, splStr)) / (eps * eps);
}

double Funct(double x, vector<string> splitedString)
{
	vector<string> reversePolishStr = PolishNotation(splitedString);
	for (int i = 0; i < reversePolishStr.size(); i++)
	{
		if (reversePolishStr[i] == "x")
			reversePolishStr[i] = to_string(x);
	}
	bool flag = true;
	double answer = Calculate(reversePolishStr, flag);
	return answer;
}

__declspec(dllexport)
void __stdcall PointsYS(double* ys, int len) {
	//int cnt = (b - a) / eps;
	int ind = 0;
	vector<string> splStr;
	regex regexFunc("(\\d+(\\.|,\\d+)?)|[\\+\\-\\^\\*\\/\\(\\)]|sin\\(|cos\\(|tg\\(|ctg\\(|exp\\(|log\\(|log10\\(|sqrt\\(");
	CheckCorrectInput(funct, a, splStr, regexFunc);
	for (double i = a; i < b; i += eps)
	{
		ys[ind] = Funct(i, splStr);
		ind++;
	}
}

bool CheckCorrectInput(string s, double x, vector<string>& splitedString, regex regexFunc)
{
	s = regex_replace(s, regex("\\."), ",");
	s = regex_replace(s, regex(" "), "");
	s = regex_replace(s, regex("\\(-"), "(0-");
	s = regex_replace(s, regex("\\+{2,}"), "+");
	s = regex_replace(s, regex("\\-{2,}"), "-");
	s = regex_replace(s, regex("\\*{2,}"), "*");
	s = regex_replace(s, regex("\\/{2,}"), "/");

	int startLength = s.length();
	int length = 0;
	smatch m;

	while (regex_search(s, m, regexFunc) == true) {

		if (s[0] == 'x')
		{
			splitedString.push_back(m.prefix());
			length += m.prefix().length();
		}
		splitedString.push_back(m[0]);
		length += m[0].length();
		s = m.suffix();
	}

	if (length != startLength)
		return false;
	return true;
}

int GetPriority(char ch)
{
	switch (ch)
	{
	case '(':
	case ')': return 0;
	case '+': return 1;
	case '-': return 2;
	case '*':
	case '/': return 3;
	case '^': return 4;
	default: return 0;
	}
}

vector<string> PolishNotation(vector<string> splitedString)
{
	stack<string> stackStr;
	vector<string> reversePolishStr;

	for (int i = 0; i < splitedString.size(); i++)
	{
		if (IsFunc(splitedString[i]))
		{
			stackStr.push(splitedString[i]);
			continue;
		}

		if (i == splitedString.size() - 1 && stackStr.top() == "^")
		{
			string tmp = stackStr.top();
			stackStr.pop();
			reversePolishStr.push_back(tmp);
		}

		if (IsBracket(splitedString[i]))
		{
			if (splitedString[i] == ")")
			{
				GoBackByBrakets(reversePolishStr, stackStr);
			}
			else stackStr.push(splitedString[i]);

			continue;
		}

		if (IsOperator(splitedString[i]))
		{
			if (GetPriority(splitedString[i].c_str()[0]) < GetPriority(stackStr.top().c_str()[0]))
			{
				GoBackByOperator(reversePolishStr, stackStr, GetPriority(splitedString[i].c_str()[0]));
			}
			else if (stackStr.top() == "/" || stackStr.top() == "^")
			{
				string tmp = stackStr.top();
				stackStr.pop();
				reversePolishStr.push_back(tmp);
			}
			stackStr.push(splitedString[i]);
			continue;
		}

		reversePolishStr.push_back(splitedString[i]);
	}
	return reversePolishStr;
}


double Calculate(vector<string> reversePolishStr, bool& flag)
{
	stack<double> stackDouble;

	for (int i = 0; i < reversePolishStr.size(); i++)
	{
		if (IsFunc(reversePolishStr[i]))
		{
			double value = stackDouble.top();
			stackDouble.pop();

			stackDouble.push(CalculateFunc(value, reversePolishStr[i]));

			continue;
		}

		if (IsOperator(reversePolishStr[i]))
		{
			double b = stackDouble.top();
			stackDouble.pop();
			double a = stackDouble.top();
			stackDouble.pop();

			stackDouble.push(CalculateOperation(a, b, reversePolishStr[i]));

			continue;
		}
		double q = atof(reversePolishStr[i].c_str());
		stackDouble.push(q);
	}
	return stackDouble.top();
}

double CalculateFunc(double value, string s)
{
	double y = 0;
	if (s == "sin(")
		__asm {
		finit
		fld value
		fsin
		fstp y
	}
	else if (s == "cos(")
		__asm {
		finit
		fld value
		fcos
		fstp y
	}
	else if (s == "tg(")
		__asm {
		finit
		fld value
		fptan
		fxch st(1)
		fstp y
	}
	else if (s == "ctg(")
		__asm {
		finit
		fld value
		fptan
		fdiv
		fstp y
	}

	else if (s == "sqrt(")
		__asm {
		finit
		fld value
		fsqrt
		fstp y
	}
	return y;

	throw invalid_argument("");
}

double CalculateOperation(double a, double b, string s)
{
	double y = 0;
	if (s == "*") {
		__asm {
			finit
			fld a;
			fmul b;
			fstp y;
		}
	}
	if (s == "/") {
		__asm {
			finit
			fld a;
			fdiv b;
			fstp y;
		}
	}
	if (s == "+") {
		__asm {
			finit
			fld a;
			fadd b;
			fstp y;
		}
	}
	if (s == "-") {
		__asm {
			finit
			fld a;
			fsub b;
			fstp y;
		}
	}

	if (s == "^") {
		;
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
	}
	return y;
	throw invalid_argument("");
}
//---------------------------

bool IsFunc(string s)
{
	if (s == "sin(" || s == "cos(" || s == "tg(" || s == "ctg(" ||
		s == "acos(" || s == "asin(" || s == "atan(" ||
		s == "sinh(" || s == "cosh(" || s == "tanh(" ||
		s == "exp(" || s == "log(" || s == "log10(" || s == "sqrt(")
		return true;
	return false;
}
bool IsBracket(string s)
{
	if (s == "(" || s == ")")
		return true;

	return false;
}
bool IsOperator(string s)
{
	if (s == "*" || s == "/" || s == "+" || s == "-" || s == "^")
		return true;
	return false;
}

void GoBackByBrakets(vector<string>& reversePolishStr, stack<string>& st)
{
	int pos = st.top().find('(', 0);
	while (pos < 0)
	{
		reversePolishStr.push_back(st.top());
		st.pop();
		pos = st.top().find('(', 0);
	}

	if (IsFunc(st.top())) reversePolishStr.push_back(st.top());
	st.pop();
}

void GoBackByOperator(vector<string>& reversePolishStr, stack<string>& st, int priority)
{
	while (GetPriority(st.top().c_str()[0]) > priority)
	{
		reversePolishStr.push_back(st.top());
		st.pop();
	}
}
