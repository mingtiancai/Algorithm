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
			//cout << std::stod(InString[i]) << endl;
			result += std::stod(InString[i]) * pow(10, int(indexPoint) - i);
		}
	}
	return result;
}

OperatorSet::OperatorSet(const std::vector<std::string>& operatorVector)
{
	for (auto x : operatorVector)
	{
		OperatorMap.insert(pair<string, size_t>(x, x.size()));
		if (x.size() > maxOperatorName)
			maxOperatorName = x.size();
	}
}

size_t OperatorSet::getMaxOperatorNameLength()
{
	return maxOperatorName;
}

bool OperatorSet::haveItem(std::string item)
{
	if (OperatorMap.count(item))
		return true;
	else
		return false;
}

std::string removeSpacing(std::string Indata)
{
	string result;
	for (size_t i = 0; i < Indata.size(); i++)
	{
		string tmp = string(1, Indata[i]);
		if (tmp != " ")
			result += tmp;
	}
	return result;
}


double ComputeArithmeticExpression(std::string ArithmeticExpression)
{
	//初始化支持的算术运算
	vector<string> OperatorVector;
	OperatorVector.push_back("+");
	OperatorVector.push_back("-");
	OperatorVector.push_back("*");
	OperatorVector.push_back("/");
	OperatorVector.push_back("sqrt");
	OperatorVector.push_back("cos");

	set<string> NumberAndPointSet;
	NumberAndPointSet.insert("0");
	NumberAndPointSet.insert("1");
	NumberAndPointSet.insert("2");
	NumberAndPointSet.insert("3");
	NumberAndPointSet.insert("4");
	NumberAndPointSet.insert("5");
	NumberAndPointSet.insert("6");
	NumberAndPointSet.insert("7");
	NumberAndPointSet.insert("8");
	NumberAndPointSet.insert("9");
	NumberAndPointSet.insert(".");

	OperatorSet OperatorSetIns(OperatorVector);

	size_t indexRemovedArithmeticExpression = 0;
	double result=0.0;

	stack<double> numberStack;
	stack<string> operatorStack;
	double currentValue=0.0;

	string removedArithmeticExpression = removeSpacing(ArithmeticExpression);

	while (indexRemovedArithmeticExpression < removedArithmeticExpression.size())
	{
		string tmp = string(1, removedArithmeticExpression[indexRemovedArithmeticExpression]);
		if (NumberAndPointSet.count(tmp))
		{
			vector<string> numberVector;
			numberVector.push_back(tmp);
			indexRemovedArithmeticExpression++;
			string numstr = string(1, removedArithmeticExpression[indexRemovedArithmeticExpression]);
			while (NumberAndPointSet.count(numstr))
			{
				numberVector.push_back(numstr);
				indexRemovedArithmeticExpression++;
				numstr = string(1, removedArithmeticExpression[indexRemovedArithmeticExpression]);
			}

			double tmpNumber = StringParseToDouble(numberVector);
			if (numstr == ")")
			{
				currentValue = tmpNumber;
			}
			else
			{
				numberStack.push(tmpNumber);
			}
		}
		else if (tmp == ")")
		{
			if (operatorStack.empty())
				return result;

			string op = operatorStack.top();
			operatorStack.pop();

			if (op == "+")
			{
				double preValue = numberStack.top();
				numberStack.pop();
				result = preValue + currentValue;
				numberStack.push(result);
				indexRemovedArithmeticExpression++;
			}
			else if (op == "-")
			{
				double preValue = numberStack.top();
				numberStack.pop();
				result = preValue - currentValue;
				numberStack.push(result);
				indexRemovedArithmeticExpression++;
			}
			else if (op == "*")
			{
				double preValue = numberStack.top();
				numberStack.pop();
				result = preValue * currentValue;
				numberStack.push(result);
				indexRemovedArithmeticExpression++;
			}
			else if (op == "/")
			{
				double preValue = numberStack.top();
				numberStack.pop();
				result = preValue / currentValue;
				numberStack.push(result);
				indexRemovedArithmeticExpression++;
			}
			else if (op == "sqrt")
			{
				result = sqrt(currentValue);
				numberStack.push(currentValue);
				indexRemovedArithmeticExpression++;
			}
			else if (op == "cos")
			{
				result = cos(currentValue);
				numberStack.push(currentValue);
				indexRemovedArithmeticExpression++;
			}
		}
		else if (tmp == "(")
		{
			indexRemovedArithmeticExpression++;
			continue;
		}
		else
		{
			string tmpString = "";

			bool flagFoundOperator = false;
			for (size_t i = 0; i < OperatorSetIns.getMaxOperatorNameLength(); i++)
			{
				tmpString += string(1, removedArithmeticExpression[indexRemovedArithmeticExpression+i]);

				if (OperatorSetIns.haveItem(tmpString))
				{
					operatorStack.push(tmpString);
					indexRemovedArithmeticExpression += i;
					indexRemovedArithmeticExpression++;
					break;
				}
			}

			//cerr << "please input right expression" << endl;
		}

	}
	return result;
}
