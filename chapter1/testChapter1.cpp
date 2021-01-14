#include "chapter1.h"
#include <vector>
#include <iostream>

using namespace std;

void testGcd()
{
	vector<int> pVector{4,5,5,5};
	vector<int> qVector{2,1,2,0};


	for (int i = 0; i < pVector.size(); i++)
	{
		cout << "the p: " << pVector[i]
			<< " the q: " << qVector[i] << " the gcd is: "
			<< Gcd(pVector[i], qVector[i]) << endl;
	}
}

void testBinarySearch()
{
	int target = 4;
	vector<int> testData1 = { 1,2,3,4 };
	cout << BinarySearch<int>(testData1, target) << endl;

	vector<int> testData2 = { 1,2,3 };
	cout << BinarySearch<int>(testData2, target) << endl;

	vector<int> testData3 = {  };
	cout << BinarySearch<int>(testData3, target) << endl;
}



void test()
{
	//testGcd();
	//testBinarySearch();

}