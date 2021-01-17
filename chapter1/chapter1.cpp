#include "chapter1.h"



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

unsigned int ComputePowBase2(unsigned int exponent)
{
	unsigned int result = 1;

	if (exponent == 0)
	{
		result = 1;
		return result;
	}
	else
	{
		for (unsigned int i = 0; i < exponent; i++)
			result = result * 2;
		return result;
	}
}



unsigned int LessMaxIntegerLog2(unsigned int N)
{
	assert(N > 0);

	vector<int> Indata;
	for (int i = 0; i < N+1; i++)
		Indata.push_back(i);

	size_t minIndex = 0;
	size_t maxIndex = Indata.size() - 1;
	size_t index = (minIndex + maxIndex) / 2;

	size_t tmpIndex = 0;
	unsigned int tmpValue = 1;

	while (minIndex != maxIndex-1)
	{
		if (ComputePowBase2(Indata[index]) <= N)
		{
			tmpIndex = index;
			tmpValue = ComputePowBase2(Indata[index]);
			minIndex = index + 1;
		}
		else
		{
			if (index == minIndex + 1)
				break;
			else
				maxIndex = index - 1;
		}
		index = (minIndex + maxIndex) / 2;
	}

	unsigned int currentMinIndexValue = ComputePowBase2(Indata[minIndex]);
	unsigned int currentMaxIndexValue = ComputePowBase2(Indata[maxIndex]);
	if (currentMaxIndexValue <= N)
		return maxIndex;
	else if (tmpValue <= N && currentMinIndexValue > N)
		return tmpIndex;
	else
		return minIndex;
}

double RecurveComputeIn(unsigned int N)
{
	if (N == 1)
		return 0;
	else
		return log(N) + RecurveComputeIn(N - 1);
}

void ComprimeArrayIndex(bool* Indata, size_t Width, size_t Height)
{
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			if (i * j == 0 || Gcd(i, j) == 1)
				*(Indata + i * Width + j) = true;
			else
				*(Indata + i * Width + j) = false;
		}
	}
}

double StringParseToDouble(std::vector<string> InString)
{
	bool flagPoint = false;
	size_t indexPoint;
	double result=0;

	for (int i=0;i<InString.size();i++)
	{
		if (InString[i] == ".")
		{
			flagPoint = true;
			indexPoint = i;
		}
	}

	if (!flagPoint)
	{
		for (int i = InString.size()-1; i >= 0; i--)
		{
			result += std::stod(InString[i]) * pow(10, InString.size() - i - 1);
		}
	}
	else
	{
		for(int i=indexPoint-1;i>=0;i--)
			result += std::stod(InString[i]) * pow(10, indexPoint - 1 - i );
		for (int i = indexPoint + 1; i < InString.size(); i++)
		{
			cout << std::stod(InString[i]) << endl;
			result += std::stod(InString[i]) * pow(10, int(indexPoint) - i);
		}
	}
	return result;
}

OperatorSet::OperatorSet()
{

}


double ComputeArithmeticExpression(std::string ArithmeticExpression)
{
	set<string> SymbolSet;
	SymbolSet.insert("+");
	SymbolSet.insert("-");
	SymbolSet.insert("*");
	SymbolSet.insert("/");
	SymbolSet.insert("sqrt");

	stack<double> OperatorNumber;
	stack<string> Operator;

	size_t indexStringIndex = 0;
	double currentValue;

	while (indexStringIndex < ArithmeticExpression.size())
	{
		//string tmp = string(1, ArithmeticExpression[indexStringIndex]);
		//if (tmp == " " || tmp == "(")
		//{
		//	indexStringIndex++;
		//	continue;
		//}
		//else if (SymbolSet.count(tmp)  || tmp=="s")
		//{
		//	Operator.push(tmp);
		//}
		//else if (tmp == ")")
		//{
		//	string op = Operator.top();
		//	Operator.pop();
		//	double preValue = OperatorNumber.top();
		//	OperatorNumber.pop();
		//	double tmpValue;

		//	if (op == "+")
		//	{
		//		tmpValue = preValue + currentValue;
		//		OperatorNumber.push(tmpValue);
		//	}
		//	else if(op=="-")
		//	{
		//		tmpValue = preValue - currentValue;
		//		OperatorNumber.push(tmpValue);
		//	}
		//	else if (op=="*")
		//	{
		//		tmpValue = preValue * currentValue;
		//		OperatorNumber.push(tmpValue);
		//	}
		//	else if(op=="/")
		//	{
		//		tmpValue = preValue / currentValue;
		//		OperatorNumber.push(tmpValue);
		//	}
		//	else if(op=="s")
		//	{
		//		string StringSqrt = string(1, ArithmeticExpression[indexStringIndex]) +
		//			string(1, ArithmeticExpression[indexStringIndex + 1]) +
		//			string(1, ArithmeticExpression[indexStringIndex + 2]) +
		//			string(1, ArithmeticExpression[indexStringIndex+3]);
		//		if(StringSqrt=="sqrt")
		//		tmpValue = sqrt(currentValue);
		//		OperatorNumber.push(tmpValue);
		//	}
		//	else if()
		}




	return 0.0;
}
