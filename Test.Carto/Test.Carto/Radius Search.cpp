// Radius Search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

typedef pair<double, double> POI;

#define READFILE 0 // 0 for stdin/stdout, 1 for test
#pragma warning(disable:4996)

int main()
{
	int n; // number of POIs
	int m; // number of centers
	double x, y;
	vector<POI> POIs;

	switch( READFILE )
	{
	case 0:
		scanf("%d", &n);		
		for( int i=0; i<n; i++)
		{		
			scanf("%lf %lf", &x, &y);		
			POIs.push_back(POI(x,y));
		}

		scanf("%d", &m);				
		// check if a POI is within the radius.
		for( int i=0; i<m; i++)
		{
			int count = 0;
			double cx, cy, r;
			scanf("%lf %lf %lf", &cx, &cy, &r);

			for( int j=0; j<n; j++)
			{
				if( pow(POIs[j].first-cx, 2)+pow(POIs[j].second-cy,2) <= pow(r,2) )
					count++;
			}
			printf("%d\n", count);
		}

		break;

	case 1:
		
		FILE * fIN = fopen("TestCases/Radius_Search/1.inp", "r");
		FILE * fOUT = fopen("TestCases/Radius_Search/1.out", "r");
		if(!fIN){  printf("cannot open the input file.\n");	 return 1; }
		if(!fOUT){ printf("cannot opne the output file.\n"); return 1; }
			
		fscanf(fIN, "%d", &n);
		for( int i=0; i<n; i++)
		{		
			fscanf(fIN, "%lf %lf", &x, &y);
			POIs.push_back(POI(x,y));
		}

		fscanf(fIN, "%d", &m);
		// check if a POI is within the radius.
		int correct = 1;
		for( int i=0; i<m; i++)
		{
			int count = 0;
			double cx, cy, r;
			fscanf(fIN, "%lf %lf %lf", &cx, &cy, &r);

			for( int j=0; j<n; j++)
			{
				if( pow(POIs[j].first-cx, 2)+pow(POIs[j].second-cy,2) <= pow(r,2) )
					count++;
			}

			int answer;
			fscanf(fOUT, "%d", &answer);
			if( count != answer) correct *=0;
		}

		if(correct)	printf("Correct answer.\n");
		else		printf("Wrong answer.\n");

		fclose(fIN);
		fclose(fOUT);

		break;
	}

	POIs.clear();
	return 0;
}


