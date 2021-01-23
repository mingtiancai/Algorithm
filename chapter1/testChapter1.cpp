#include "chapter1.h"

using namespace std;

void testGcd()
{
	vector<int> pVector{4,5,5,5,105};
	vector<int> qVector{2,1,2,0,24};

	for (int i = 0; i < pVector.size(); i++)
	{
		cout << "the p: " << pVector[i]
			<< " the q: " << qVector[i] << " the gcd is: "
			<< Gcd(pVector[i], qVector[i]) << endl;
	}
}

void testBinarySearch()
{
	int target = 1;
	vector<int> testData1 = { 1,2,3,4,5,5,6,9,12 };
	cout << BinarySearch<int>(testData1, target) << endl;

	vector<int> testData2 = { 1,2,3 };
	cout << BinarySearch<int>(testData2, target) << endl;

	/*vector<int> testData3 = {  };
	cout << BinarySearch<int>(testData3, target) << endl;*/
}

void testTransposeTwoArray()
{
	/*int dataArray[3][4]= { 1,2,3,4,5,6,7,8,9,10,11,12 };*/

	int dataArray[3][1] = { 1,2,3 };

	const int oldWidth = 3;
	const int oldHeight = 1;
	const int newWidth = 1;
	const int newHeight = 3;

	//打印原来数组
	for (int i = 0; i < oldHeight; i++)
	{
		for (int j = 0; j < oldWidth; j++)
			cout << "   " << dataArray[i][j];
		cout << endl;
	}

	TransposeTwoArray((int*)dataArray, oldWidth, oldHeight);

	for (int i = 0; i < newHeight; i++)
	{
		for (int j = 0; j < newWidth; j++)
			cout << "   " << *((int*)dataArray + i * newWidth + j);
		cout << endl;
	}
}

void testComputePowBase2()
{
	cout << ComputePowBase2(0) << endl;
	cout << ComputePowBase2(1) << endl;
	cout << ComputePowBase2(10) << endl;
}

void testLessMaxIntegerLog2()
{
	cout << LessMaxIntegerLog2(8) << endl;
	cout << LessMaxIntegerLog2(9) << endl;
	cout << LessMaxIntegerLog2(1) << endl;  
	cout << LessMaxIntegerLog2(4) << endl;
	cout << LessMaxIntegerLog2(5) << endl;
	cout << LessMaxIntegerLog2(12) << endl;
	cout << LessMaxIntegerLog2(16) << endl;
	cout << LessMaxIntegerLog2(17) << endl;
	cout << LessMaxIntegerLog2(22) << endl;
}

void testRecurveComputeIn()
{
	cout << RecurveComputeIn(5) << endl;
}

void testEqualKey()
{
	vector<int> testData1 = { 1,2,3,4,5,5,6,9,12 };
	vector<int> targetVector = {1,4,5,6,7,9,11,12,13};

	for (auto x : targetVector)
	{
		pair<int, int> result;
		result = EqualKey<int>(testData1, x);

		cout << "the rank is: " << result.first << " the count is: " <<result.second<< endl;
	}
}

void testComprimeArrayIndex()
{
	bool testData[4][4];

	ComprimeArrayIndex((bool*)testData, 4, 4);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << testData[i][j] << "   ";
		}
		cout << endl;
	}
}

void testStringParseToDouble()
{
	string s = "100.23";
	//string s = "0.23";
	vector<string> p;
	for (int i = 0; i < s.size(); i++)
		p.push_back(string(1,s[i]));
	double r;
	r = StringParseToDouble(p);
	cout << r << endl;
}

void testComputeArithmeticExpression()
{
	string expression1 = "(sqrt(2))";
	string expression2 = " ( (100+10)-11)";
	string expression3 = " ( cos(3.1415926/3))";
	double result;
	result = ComputeArithmeticExpression(expression1);
	cout << result << endl;
	result=ComputeArithmeticExpression(expression2);
	cout << result<<endl;
	result = ComputeArithmeticExpression(expression3);
	cout << result << endl;
}

void testParentheses()
{
	string test1 = "[[[]]]{}()";
	string test2 = "{ss}";
	string test3 = "{(}";

	cout << Parentheses(test1) << endl;
	cout << Parentheses(test2) << endl;
	cout << Parentheses(test3) << endl;
}

void testoneCountTransfer()
{
	string testString1 = "3+4)";
	cout << oneCountTransfer(testString1,3) << endl;

	string testString2 = "(4+5)*3+4))";
	testString2 = oneCountTransfer(testString2, 9);
	cout << testString2 << endl;
	cout << multiCountTransfer(testString2,2,11) << endl;
}

void testmultiCountTransfer()
{
	string testString = "(3-4)*(5-6))";
	cout << multiCountTransfer(testString, 2, 11);
}

void testComplementArithmeticExpression()
{
	string result;
	string testString1 = "1+2)*3-4)*5-6)))";
	result = ComplementArithmeticExpression(testString1);
	cout << result << endl;

	string testString2 = "1+2)";
	result = ComplementArithmeticExpression(testString2);
	cout << result << endl;

	string testString3 = "1+2)+4+3))";
	result = ComplementArithmeticExpression(testString3);
	cout << result << endl;
}

void testInfixToPostfix()
{
	string test1 = "((2*3)/(2-1)+(3*(4-1)))";
	//string test1 = "((1+2)*((3-4)*(5-6)))";
	cout << InfixToPostfix(test1) << endl;
}

void testComputePostfix()
{
	vector<string> expressionVector = { "3","4","+","5","*","6","-" };

	vector<bool> flag = { false,false,true,false,true,false,true };

	double result;
	result = ComputePostfix(expressionVector, flag);
	cout << result << endl;
}

void testResizeingArrayQueue()
{
	ResizeingArrayQueue<int> queueL;

	
	queueL.enqueue(4);
	cout << queueL.size() << endl;
	cout << queueL.dequeue() << endl;
	cout << queueL.size() << endl;

	queueL.enqueue(4);
	cout << queueL.size() << endl;
	queueL.enqueue(5);
	cout << queueL.size() << endl;
	queueL.enqueue(6);
	cout << queueL.size() << endl;

	while (!queueL.isEmpty())
		cout << queueL.dequeue() << endl;
}

void testLinkList()
{
	LinkList<int> l;
	l.addNode(10);
	l.addNode(12);

	cout << l.getFirstItem() << endl;
	cout << l.getLastItem() << endl;

	l.removeLast();

	//cout << l.getFirstItem() << endl;
	//cout << l.getLastItem() << endl;
}

void testLinkListRemoveKrdItem()
{
	LinkList<int> l;

	l.addNode(1);
	l.addNode(2);
	l.addNode(3);
	l.addNode(4);
	l.addNode(5);

	cout << l.getFirstItem() << endl;
	cout << l.getLastItem() << endl;
	l.removeKrdItem(1);
	cout << l.getFirstItem() << endl;
	l.removeKrdItem(4) ;
	cout << l.getLastItem() << endl;
}

void testLinkListReverse()
{
	LinkList<int> l;

	l.addNode(1);
	l.addNode(2);
	l.addNode(3);
	l.addNode(4);
	l.addNode(5);

	l.printAllItems();

	l.reverse();

	l.printAllItems();
}



void test()
{
	//testGcd();
	//testBinarySearch();
	//testTransposeTwoArray();
	//testComputePowBase2();
	//testLessMaxIntegerLog2();
	//testRecurveComputeIn();
	//testEqualKey();
	//testComprimeArrayIndex();
	//testStringParseToDouble();
	//testComputeArithmeticExpression();
	//testParentheses();
	//testmultiCountTransfer();
	//testoneCountTransfer();
	//testComplementArithmeticExpression();
	//testInfixToPostfix();
	//testComputePostfix();
	//testResizeingArrayQueue();
	//testLinkList();
	//testLinkListRemoveKrdItem();
	testLinkListReverse();


}