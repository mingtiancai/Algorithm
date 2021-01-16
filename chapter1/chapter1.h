#include <vector>
#include <assert.h>

//算法

//计算两个数最大公约数
int Gcd(int p, int q);

//二分查找排序好的递增的容器中元素的位置，返回索引
template <typename T>
int BinarySearch(const std::vector<T>& Indata, T TargetNum)
{
	assert(Indata.size() > 0);
	size_t minIndex = 0;
	size_t maxIndex = Indata.size() - 1;

	size_t index = (minIndex + maxIndex)/2;

	while (minIndex != maxIndex)
	{
		if (Indata[index] == TargetNum)
			return index;
		else if (Indata[index] < TargetNum)
			minIndex = index + 1;
		else
			maxIndex = index - 1;
		index = (minIndex + maxIndex) / 2;
	}

	if (Indata[index] == TargetNum)
		return minIndex;
	else
		return -1;
}

//工具函数
unsigned int ComputePowBase2(unsigned int exponent);




//1.1.13 solution
void TransposeTwoArray(int* IndataPtr, size_t width, size_t height);

//1.1.14 solution
unsigned int LessMaxIntegerLog2(unsigned int N);


//测试
void test();

void testGcd();

void testBinarySearch();

void testTransposeTwoArray();

void testComputePowBase2();

void testLessMaxIntegerLog2();

