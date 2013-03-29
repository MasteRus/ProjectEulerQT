#include "stdafx.h"
#include "Additional/SomeMathFunc.h"
#include "Additional/Bigint.h"
using namespace std;

/*
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
////////////////////////////////////////////////////////////////////////////////////////////////////////
Answer: 997651  
*/ 


long long proj050(long long n)
{
        long long i,j,k,flag;
	long long arrOfPrimes[100000], countOfPrimes=1;
	arrOfPrimes[0]=2; 
	long long result=0;
	for (i=3;i<n;i=i+2)
	{
		flag=1;
		for (j=0;j<countOfPrimes;j++)
		{
			if ((i%arrOfPrimes[j])==0) 
			{
				flag=0;
				break;
			}
		}
		if (flag) 
		{
			
			arrOfPrimes[countOfPrimes]=i;
				countOfPrimes++;
		}
		if (i%10001==0) 	cout << "i=" << i<<endl;
	}
	long long sum=0;
	long long result_length=0;
	for (i=0;i<countOfPrimes;i++)
	{
		sum=0;
		for (k=i;k<countOfPrimes;k++)
		{
			sum+=arrOfPrimes[k];
			if (sum>n) break;
			flag=1;	

			for (j=i;j<countOfPrimes;j++)
			{
				if (sum==arrOfPrimes[j]){flag=0; break;}
			}
			if ((!flag)&&((k-i+1)>result_length))
			{
				result=sum;
				result_length=k-i+1;
				cout  << "SUM=" << sum << ", LEngth=" << result_length << endl;
			}
		}
	}
	return result;
}
/*

There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,
nCr = 	
n!
r!(n−r)!
	,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?
======================================================================================================================
Answer:
	4075
*/

long long proj053(long long n, long long val)
{
        long long i,j,result=0;
	
	BigInt **path;
	path=new BigInt *[n+1];       

	for (j=0;j<=n; j++)
	{
		path[j]=new BigInt [n+1];  
		for (i=0;i<=n;i++)
		{
			path[j][i]=0;  
		}
		path[j][j]=1;
		path[j][0]=1;
	}
	for (j=1;j<=n; j++)
	{
		for (i=1;i<j;i++)
		{
			path[j][i]=path[j-1][i]+path[j-1][i-1];
			if (path[j][i]>val) result++;
		}
	}
	return (result);
}

/*
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ? 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
////////////////////////////////////////////////////////////////////////////////////////////////////////
Answer: 26241
*/ 
long long proj058()
{
        long long i=1;
        long long temp1=0,temp2=0;

        long long a=1,b=1,c=1;
	double ratio=1;
	while (ratio>=(0.1))
	{
		a=a+2+8*(i-1);
		b=b+4+8*(i-1);
		c=c+6+8*(i-1);
		//d=d+8+8*(i-1);

		if (isPrime(a)) temp1++;
		if (isPrime(b)) temp1++;
		if (isPrime(c)) temp1++;
		temp2=(4*i+1);
		ratio=(double)(temp1)/(temp2);
		if (i%100000==0) cout << i <<" = " << temp1 << "/" << temp2<<" = " << ratio <<endl;
		i++;
	}
	return (2*(i)-1);
}
