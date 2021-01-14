#include "chapter1.h"
#include <assert.h>

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


