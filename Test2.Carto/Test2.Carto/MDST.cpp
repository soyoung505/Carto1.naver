#include "stdafx.h"

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>

#pragma warning(disable:4996)

using namespace std;

int maxL;
int first = 1;

char * answer;

int Digit ( int  n)
{
	int i = 1;
	while(1)
	{
		if(n/pow(10,i)<1)
			return i;
		i++;
	}
}

int Multiply2 ( int n )
{
	return (n*2)%(int)(pow(10,7));
}

int Divide2 ( int n )
{
	return n/2;
}

int Sort ( int n )
{
	int d = Digit(n);

	int nums[7];
	for( int i=0; i<d; i++)
		nums[i] = (int)(n/pow(10,i))%10;

	sort(nums, nums+d);

	int result = 0;
	for( int i=0; i<d; i++)
		result += nums[d-1-i]*pow(10, i);
			
	return result;
}

int Tros ( int n )
{
	int d = Digit(n);

	int nums[7];
	for( int i=0; i<d; i++)
		nums[i] = (int)(n/pow(10,i))%10;

	sort(nums, nums+d);

	int result = 0;
	for( int i=0; i<d; i++)
		result += nums[i]*pow(10, i);
			
	return result;
}

char * StrCon( const char * str, const char * m)
{
	char * con = (char *)malloc(strlen(str)+2);
	strcpy(con, str);
	strcat(con, m);

	return con;
}

void MDST( int n, int level, const char * str)
{
	if(level > maxL)
		return;
	if(n==1)
	{

		if(first)
		{
			answer = (char * )malloc(strlen(str)+1);
			strcpy(answer, str);
			first = 0;
		}
		else
		{
			if(level<maxL)
				strcpy(answer, str);
			else
			{
				if(strcmp(answer, str) == 1)
					strcpy(answer, str);
			}
			
		}
		maxL = level;
		return;
	}
	if(n==2 || n==3)
	{
		MDST( Divide2(n), level+1, StrCon(str, "D"));
		return;
	}
	if(n== pow(10,Digit(n)-1))
	{
		MDST( Sort(n), level+1, StrCon(str, "S"));
		return;
	}

	MDST( Divide2(n), level+1, StrCon(str, "D"));
	if(str[level-1]!='S')
		MDST( Sort(n), level+1, StrCon(str, "S"));
	if(str[level-1]!='T')
		MDST( Tros(n), level+1, StrCon(str,"T"));
	MDST( Multiply2(n), level+1, StrCon(str, "M"));

}

int main()
{

	int n; // input number
	scanf("%d", &n);

	maxL = (int)log2(n);

	MDST(n, 0, "");

	printf("%s\n", answer);

	return 0;
}