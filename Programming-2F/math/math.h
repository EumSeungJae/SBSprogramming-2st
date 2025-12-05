#pragma once

#ifdef MATHLIBRATY_EXPORT
#define MATH_API __declspec(dllexport)
#else 
#define MATH_API __declspec(dllexport)
#endif // DEBUG

extern "C" MATH_API int Add(int a, int b);

extern "C" MATH_API int Minus(int a, int b);
