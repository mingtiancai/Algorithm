#include "chapter1.h"
#include <assert.h>
#include <iostream>
#include <bitset>


using namespace std;

int Gcd(int p, int q)
{
	if (q == 0)
		return p;
	else
	{
		int tmp = p % q;
		return Gcd(q, tmp);
	}
}

void TransposeTwoArray(int* IndataPtr, size_t width, size_t height)
{
	size_t n = width * height;
	bool* flagPtrIn = new bool[width * height]{};

	size_t currentIndex = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int Ini = i;
			int Inj = j;
			size_t srcIndex = Ini * width + Inj;
			size_t dstIndex = Inj * height + Ini;
			
			int preValue= IndataPtr[srcIndex];

			while (flagPtrIn[dstIndex] == false && currentIndex < width * height)
			{
				flagPtrIn[dstIndex] = true;
				int tmp = IndataPtr[dstIndex];
				IndataPtr[dstIndex] = preValue;
				Ini = dstIndex / width;
				Inj = dstIndex % width;
				srcIndex = Ini * width + Inj;
				dstIndex = Inj * height + Ini;
				preValue = tmp;
			}
			currentIndex++;
		}
	}

	delete []flagPtrIn;    //回收动态数组
}

