#pragma once
#include "data.h"
#include <cassert>

template<typename T1>
T1 min(const T1*& _a, const T1*& _b);

template<typename T>
void sort( T* _mas);

template<typename T>
T sum(const T* _mas);

void minTest();

void sortTest();

void sumTest();