#include "stdafx.h"
#include "Additional/SomeMathFunc.h"
//#include "Additional/BigInt.h"
using namespace std;

/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
===================================================================================================
Answer: 443839  
*/
long long proj030()
{
        int i,j,digit,sum;
	long long result=0;
	int n=6*60000;
	//int n=150;
	for (i=10;i<n;i++)
	{
		j=i;
		sum=0;
		while (j)
		{
			 digit=j%10;
			 ;
			 sum+=digit*digit*digit*digit*digit;
			 j=j/10;
		}
		if (sum==i) {result+=i;
		cout << i <<endl; 
		}
	}
	
	return result;
}

/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?
------------------------------------------------------------------------------------------------------------------
Answer: 73682
*/
long long proj031(int n, int start, int mas[], int mas_size)
{
        long long i=start,k=0,result=0;
	if (n>=0) {
		if (mas[start]==1) 
		{
	//		cout << "max depth+1"<<endl;
			result++; 

		}
		else
		{
			if (n>=mas[start])
			{
				k=n/mas[start];
				for (i=k;i>=0;i--)
				{
	//				cout <<start<< ": n="<<n<<", ost="<<n-i*mas[start]<<", mas["<<start<<"]="<<mas[start]<<endl;
					result+=proj031(n-i*mas[start], start+1, mas, mas_size);

				}
			}
			else 
			{	
	//			cout <<start<< ": n="<<n<<", mas["<<start<<"]="<<mas[start]<<endl;
				result+=proj031(n, start+1, mas, mas_size);
			}
		}
		
	}; 
	//cout <<"start="<<start<<", result="<<result<< endl;
	return result;
}


/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
Find the sum of all numbers which are equal to the sum of the factorial of their digits.
Note: as 1! = 1 and 2! = 2 are not sums they are not included.
===================================================================================================
Answer: 40730 
*/
long long proj034()
{
	int i,j,k,digit,fact,sumfact;
	long long result=0;
	int n=6*9*9*9*9*9*9;
	//int n=150;
	for (i=10;i<n;i++)
	{
		j=i;
		sumfact=0;
		while (j)
		{
			 digit=j%10;
			 fact=1;
			 if (digit>1)
			 {
				for (k=1;k<=digit;k++)
				{
					fact*=k;
				}
			 }
			 sumfact+=fact;
			 j=j/10;
		}
		if (sumfact==i) {result+=i;
		cout << i <<endl; 
		}
	}
	
	return result;
}

/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
==================================================================================================================
Answer:
	55
*/

long long proj035(int n)
{
        long long i=1,j=0,k=0,z=0, step=0, result=0, flag=0;
	vector<int> tmp;

	list<int> mainvect;

        int digit;
	mainvect.push_back(2);
	mainvect.push_back(3);
	mainvect.push_back(5);
	mainvect.push_back(7);
	for (i=11;i<n;i=i+2)
	{
		if (isPrime2(i)==1)
		{
			j=i;
			step=0;
			while (j)
			{
				step++;
				j=j/10;
			}

			j=i;
			flag=1;
			tmp.clear();
			tmp.push_back(j);
			for (k=0;k<step;k++)
			{
				digit=j%10;
				for (z=0;z<step-1;z++)
				{
					digit*=10;
				}
				j=(j/10)+digit;

				if (isPrime2(j)==0)
				{
					flag=0;
					break;
				}
				tmp.push_back(j);
			}

			if (flag)
			{
				for (k=0;k<tmp.size();k++)
					mainvect.push_back(tmp[k]);
				//cout << "i=" <<i<<", Added to vector" << endl;
			}
		}
	}

	mainvect.sort();
	mainvect.unique();
	result=mainvect.size();
	return result;
}

/*
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
(Please note that the palindromic number, in either base, may not include leading zeros.)
===================================================================================================
Answer: 872187  

*/

long long proj036(long long n)
{
	long long i;
	long long result=0;
	int temp1=0, temp2=0;
    //char str10[32];
    string str10, str2, revstr;
    //char str2[32];
	for (i=1;i<n;i++)
	{
            //@QTReb
                //itoa(i,str10,10);

                //itoa(i,str2,2);



                //temp1=_stricmp(str10, _strrev( _strdup( str10) ) );
                //temp2=_stricmp(str2, _strrev( _strdup( str2) ) );

        str10=string_itoa(i,10);
        str2=string_itoa(i,2);
        revstr=str10;
        reverse(revstr.begin(),revstr.end());
        if (revstr==str10) temp1=0; else temp1=1;

        revstr=str2;
        reverse(revstr.begin(),revstr.end());
        if (revstr==str2) temp2=0; else temp2=1;

		if ((temp1==0)&&(temp2==0))	result+=i;
	}
	return (result);
}

/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
=======================================================================================================================
Answer: 748317
*/

long long proj037()
{
        long long i=11,j=0,k=0, step=0, result=0, flag=0;
	int counter=0;
	while (step!=11)
	{
		if (isPrime2(i)) 
		{
			j=i;
			counter=1;
			flag=1;
			k=10;
			while ((flag)&&(j>k))
			{
				
				
				long long t=isPrime2(j%k);
				long long p=isPrime2(j/k);
				if (!((t==1)&&(p==1)))
					flag=0;
				counter++;
				k=(long long) (pow((double)(10),counter));
			}
			if (flag) {result+=i; step++;
			cout << "step==" << step <<", i="<<i<<endl;
			}
			
		}
		
//		if (i%100000==1) cout << i <<endl;
		i=i+2;
	}
	return result;
}


/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.
{20,48,52}, {24,45,51}, {30,40,50}
For which value of p  1000, is the number of solutions maximised?
===================================================================================================
Answer: 840  

*/
long long proj039(int n)
{
	
        int counter,countermax=0, p, pmax=0;
	int i,j,k;

	
	int arr[1000];
	for (i=0;i<1000;i++)
	{
		arr[i]=i*i;
	}

	for (p=1;p<n;p++)
	{
		counter=0;
		for (i=1;i<p;i++)
		{
			for (j=i;j<=p-i;j++)
			{
				
				k=p-i-j;
				if ((arr[i]+arr[j])==arr[k])
				{
					//cout << p <<", " << i << "+" << j << "="<<k << endl;
					counter++;
				}
				
			}

		}

		if (counter>countermax) {countermax=counter; pmax=p;
		cout << p <<", " << countermax << endl;
		}
	}
	
	return pmax;
}


/*

===================================================================================================

*/


/*

===================================================================================================

*/
