#include "func.h"

template <typename T>
bool comparemas(const T* _mas1, const T* _mas2) {
	for (int i = 0; i < N; i++)
	{
		if (_mas1[i] != _mas2[i]) return false;
	}
	return true;
}

template<typename T1>
inline T1 min(const T1*& _a, const T1*& _b)
{
	if (_a < _b) return _a;
	else return _b;
}

template<typename T>
void sort(T* _mas)
{
	T temp = _mas[0];
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		k = i;
		for (int j = 0; j<i; j++)
		{
			if (_mas[j] > _mas[k]) k = j;
		}
		if (i != k) {
			temp = _mas[k];
			_mas[k] = _mas[i];
			_mas[i] = temp;
		}
	}

}

template<typename T>
T sum(const T* _mas)
{
	T* temp = new T;
	*temp = _mas[0] - _mas[0];
	for (int i = 0; i < N; i++)
	{
		if (_mas[i] >= (T)0)*temp += _mas[i];
	}
	return *temp;
}

void minTest()
{
	assert(min(100,200) == 100, "min1");
	assert(min("AAA","BBB") == "BBB", "min2");
	assert(min(3.3,1.13) == 1.13, "min3");
}

void sortTest()
{
	int* nums = new int[N]{ 2,1,3 };
	int* numsrez = new int[N]{ 1, 2, 3 };
	char* str = new char[N]{ 'C','A','B' };
	char* strrez = new char[N]{ 'A','B','C' };
	float* f = new float[N] { 1.1,3.3,2.2 };
	float* frez = new float[N] { 1.1, 2.2, 3.3 };
	sort(nums);
	sort(str);
	sort(f);
	assert(comparemas(nums,numsrez) == true, "sort1");
	assert(comparemas(str,strrez) == true, "sort2");
	assert(comparemas(f,frez) == true, "sort3");
}

void sumTest()
{
	int* nums = new int[N]{ 2,1,3 };
	double* f = new double[N] { 2.2, -3.3, 1.1 };
	assert(sum(nums) == 6, "sum1");
	assert(sum(f) == 3.3, "sum2");
}