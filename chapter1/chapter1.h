#include "../base.h"

//工具函数
unsigned int ComputePowBase2(unsigned int exponent);

double StringParseToDouble(std::vector<std::string> InString);

class OperatorSet {
public:
	OperatorSet(const std::vector<std::string>& operatorVector);
	size_t getMaxOperatorNameLength();
	bool haveItem(std::string item);
private:
	size_t maxOperatorName=0;
	std::map<std::string, size_t> OperatorMap;
};

std::string removeSpacing(std::string Indata);

std::string oneCountTransfer(std::string Indata,size_t index);

std::string multiCountTransfer(std::string Indata, int recount,size_t index);

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

	while (minIndex<=maxIndex)
	{
		size_t index = (minIndex + maxIndex) / 2;
		if (Indata[index] < TargetNum)
			minIndex = index + 1;
		else if (Indata[index] > TargetNum)
			maxIndex = index - 1;
		else
			return index;
	}
	return -1;
}

//1.1.13 solution
void TransposeTwoArray(int* IndataPtr, size_t width, size_t height);

//1.1.14 solution
unsigned int LessMaxIntegerLog2(unsigned int N);

//1.1.20
double RecurveComputeIn(unsigned int N);

//1.1.29
template <typename T>
std::pair<int, int> EqualKey(const std::vector<T>& Indata, T TargetNum)
{
	assert(Indata.size() > 0);
	size_t minIndex = 0;
	size_t maxIndex = Indata.size() - 1;
	size_t index ;
	bool flagGetTartget = false;

	unsigned int count;
	unsigned int lessNumber;

	while (minIndex <= maxIndex)
	{
		index = (minIndex + maxIndex) / 2;
		if (Indata[index] < TargetNum)
			minIndex = index + 1;
		else if (Indata[index] > TargetNum)
			maxIndex = index - 1;
		else
		{
			flagGetTartget = true;
			break;
		}
	}

	size_t minEqualTargetIndex;
	size_t maxEqualTargetIndex;

	if (flagGetTartget == false)
		count = 0;
	else
	{
		for (int i = index; i >= 0; i--)
		{
			if (Indata[i] == TargetNum)
				minEqualTargetIndex = i;
			else
				break;
		}

		for (int i = index; i <Indata.size(); i++)
		{
			if (Indata[i] == TargetNum)
				maxEqualTargetIndex = i;
			else
				break;
		}
		count = maxEqualTargetIndex - minEqualTargetIndex+1;
	}

	for (int i = index; i >= 0; i--)
	{
		if (Indata[index] >= TargetNum)
			index--;
	}

	lessNumber = index + 1;
	if (index == 0)
	{
		if (Indata[index] >= TargetNum)
			lessNumber = 0;
		else
			lessNumber = 1;
	}
		
	return std::make_pair(lessNumber, count);
}

//1.1.30 solution
void ComprimeArrayIndex(bool* Indata,size_t Width,size_t Height);

double ComputeArithmeticExpression(std::string ArithmeticExpression);

//1.3.4 solution
bool Parentheses(std::string Indata);

//1.3.9 solution
std::string ComplementArithmeticExpression(std::string ArithmeticExpression);


//测试
void test();

void testGcd();

void testBinarySearch();

void testTransposeTwoArray();

void testComputePowBase2();

void testLessMaxIntegerLog2();

void testRecurveComputeIn();

void testEqualKey();

void testStringParseToDouble();

void testComputeArithmeticExpression();

void testParentheses();

void testmultiCountTransfer();

void testoneCountTransfer();

void testComplementArithmeticExpression();