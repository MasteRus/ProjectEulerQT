#include "stdafx.h"
#include "Additional/SomeMathFunc.h"
#include "Additional/Bigint.h"
using namespace std;

/*

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/

/*
Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
where each “_” is a single digit.
===================================================================================================
Answer:	1389019170
*/
long long proj206()
{
        long long i=7,j=0,k=0, step=0, result=0, flag, flag2;
	flag2=1;
	for (i=1010101010; i<=1389026623; i++)
	{
		j=i*i;
		step=10;
		flag=1;
		while (j)
		{
			k=j%10;
			
			if (k!=(step%10)) {flag=0;break;}
			else {
				j=j/100;
				step--;
			}
			
		}
		if (flag) {result=i; break;}
		if (i%10000000==0) {
			cout << "i="<< i<< endl;
		}
	}
	return result;
	
}
