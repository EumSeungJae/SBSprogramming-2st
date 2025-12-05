// math.cpp : 정적 라이브러리를 위한 함수를 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "math.h"
// TODO: 라이브러리 함수의 예제입니다.
void fnmath()
{
}

extern "C" MATH_API int Add(int a, int b)
{
	return a + b;
}
extern "C" MATH_API int Minus(int a, int b)
{
	return a - b;
}