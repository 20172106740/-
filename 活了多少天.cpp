#include "stdafx.h"
#include<iostream>
int F(int y, int m, int d, int a, int b, int c);
int main(void)
{
	int y, m, d, a, b, c;
	scanf_s("%d %d %d %d %d %d", &y, &m, &d, &a, &b, &c);
	printf("\n%d\n", F(y, m, d, a, b, c));
	return 0;
}
int F(int y, int m, int d, int a, int b, int c)
{
	int alive = 0, i, n, z;
	int e;
	int x[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int k[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	n = a - y;
	e = m - 1;
	z = b - m;
	if (n == 0)
	{
		if (z == 0)
			alive = c - d;
		else
		{
			if (a % 100 != 0 || a % 4 == 0)
			{
				alive = k[e] - d;
				for (i = m; i<b - 1; i++)
					alive += k[i];
				alive += c;
			}
			else
			{
				alive = k[e] - d;
				for (i = m; i<b; i++)
					alive += x[i];
				alive += c;
			}
		}
	}
	else
	{
		for (i = y + 1; i<a; i++)
		{
			if (i % 100 != 0 || i % 4 == 0)
				alive += 366;
			else
				alive += 365;
		}
		if (y % 100 != 0 || y % 4 == 0)
		{
			alive += k[e] - d;
			for (i = m; i<12; i++)
				alive += k[i];
		}
		else
		{
			alive += x[e] - d;
			for (i = m; i<12; i++)
				alive += x[i];
		}
		if (a % 100 != 0 || a % 4 == 0)
		{
			for (i = 0; i<b - 1; i++)
				alive += k[i];
		}
		else
			for (i = 0; i<b - 1; i++)
				alive += x[i];
		alive += c;
	}
	return alive;
}