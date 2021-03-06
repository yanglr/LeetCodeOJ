// Lintcode77-LCS.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <string>
using namespace std;
static const int N = 1000;

class Solution {
public:
	int longestCommonSubsequence(string &A, string &B) {
		int c[N + 1][N + 1];
		int m = A.size();
		int n = B.size();
		int max1 = 0;
		A = ' ' + A;
		B = ' ' + B;
		for (size_t i = 1; i <= m; i++)
			c[i][0] = 0;
		for (size_t j = 1; j <= n; j++)
			c[0][j] = 0;

		for (size_t i = 1; i <= m; i++)
		{
			for (size_t j = 0; j <= n; j++)
			{
				if (A[i] == B[j])
				{
					c[i][j] = c[i - 1][j - 1] + 1;
				}
				else
					c[i][j] = max(c[i][j - 1], c[i - 1][j]);
				max1 = max(max1, c[i][j]);
			}
		}
	}
};

int main()
{
    return 0;
}

