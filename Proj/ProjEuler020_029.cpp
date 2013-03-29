#include "stdafx.h"
#include "Additional/SomeMathFunc.h"
#include "Additional/Bigint.h"
using namespace std;

/*


n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
===================================================================================================
Answer:
	648
*/

long long proj020(long long n)
{
	long long i;
	BigInt tmp("1");
	
	for (i=2;i<=n;i++)
		tmp=tmp*i;

	return tmp.SumOfDigit();
}

/*
Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
===================================================================================================
Answer: 31626  
*/
long long proj021(long long n)
{
	long long i,j,k;
	long long result=0,counter;
	long long arr[10000];
	for (i=1; i<n;i++)
	{
		counter=0;
		for (j=1; j<=(i/2); j++)
			if (i%j==0) counter+=j;
		arr[i]=counter;
	}
	for (i=1;i<n;i++)
	{
		if (arr[i]<n)
		{
			k=arr[i];
			if ((arr[k]==i)&&(k!=i))
			{
				result+=arr[k]+arr[i];
				arr[k]=0;arr[i]=0;
			}

		}
	}
	return result;
}

/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938  53 = 49714.

What is the total of all the name scores in the file?
===================================================================================================
Answer: 871198282  
*/ 


long long proj022()
{
	long long i=0,j,k=0,result=0;

	
	string str;
	string tmp;
	char ch;
    ifstream in("Resources/22.txt", ios::in);
	if (!in)
	{
		cout << "Can't open file!\n";
	}
	list<string> namelist;
	while (in)
    {
		in.get(ch);
		if (ch!='"') tmp+=ch;
	}
	list<string> arr=split(tmp,',');
	arr.sort();
	i=0;
	while (arr.size()!=0)
	{
		i++;
		str=arr.front();
		arr.pop_front();
		k=0;
		for (j=0;j<str.size();j++)
		{
			k+=str[j]-64;
		}
		result+=k*i;
	}
	in.close();
	return result;
}

/*


A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
=======================================================================================================================
Answer:
	2783915460
*/

string proj024(int n1)
{
	long long i=1,j=0,z=0, step=0, flag=0, flag2=0;
        int k=0;
	string tmp;
	char chr_symb;
	int main_size=0, add_size=0, tmp_size=0;

	vector<string> mainset;
	vector<string> additionalset;
	vector<string> resultset;

	for (chr_symb='0';chr_symb<='9';chr_symb++)
	{
		tmp=chr_symb;
		additionalset.push_back(tmp);
	}
	tmp='0';
	mainset.push_back(tmp);
	tmp='1';
	mainset.push_back(tmp);
	tmp='2';
	mainset.push_back(tmp);
	for (i=1;i<10;i++)
	{
		main_size=mainset.size();
		add_size=additionalset.size();
		step=0;
		for (j= 0; j< main_size;j++)
		{
			for (k = 0; k<add_size;k++)
			{
				flag=1;
				tmp=mainset[j]+additionalset[k];
				tmp_size=tmp.size();
				for (z=0;z<tmp_size-1;z++)
				{
					
					if (tmp[z]==tmp[tmp_size-1]) 
					{
						flag=0;break;
					}
				}
				if (flag) 
				{
					resultset.push_back(tmp);
					step++;
					if ((step==n1)&&(i==9))
					{
						flag2=1;
						break;
					}
				}
			}
			if (flag2)
				break;
		}
		if (flag2)
			break;
		mainset=resultset;
		resultset.clear();
	}
	return resultset[resultset.size()-1];
}


/*


The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
///////////////////////////////////////////////////////////////////////////////////////////////
Answer:	4782
*/

long long proj025(int n)
{
        long long i=2,j;
	BigInt an_1("1"),an_2("1");
	BigInt an("1");
	j=1;
	
	while (j<n)
	{
		an_2=an_1;
		an_1=an;
		an=an_1+an_2
			;
		i++;
		j=an.Value.size();
		if (i%100==0) 
			cout << i << " contains " << j << endl;
		//an.Print();
	} 
	//if (an_1==an_2) cout << "Yes"; else cout << "no";
	return i;
}


/*


A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Answer:
	983
*/
long long proj026(int n)
{
	int i,j,z,k=0, result=0, flag=1, flag2=1, counter=0;
	vector<int> tmp;
	for (i=1;i<=n;i++)
	{
		k=1;j=1;
		tmp.clear();

		flag=1;
		while ((k/i)==0)
		{	k*=10;}
		while ((k)&&(flag))
		{
			counter=0;
			while ((k/i)==0)
			{
				if (counter) tmp.push_back(0);
				counter++;
				
				k*=10;
			}
			k=k%i;
			if (tmp.size()!=0)
			{
				flag2=1;
				for (z=0;z<tmp.size();z++)
					if (tmp[z]==k)
					{
						if (result<tmp.size()-z) result=tmp.size()-z;
						flag=0;

						break;
					}
				if (flag2) tmp.push_back(k);
			} else tmp.push_back(k);
			
		}
	}
	return (result);
}


/*
Euler published the remarkable quadratic formula:

n² + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly divisible by 41.

Using computers, the incredible formula  n²  79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, 79 and 1601, is 126479.

Considering quadratics of the form:

n² + an + b, where |a|  1000 and |b|  1000


where |n| is the modulus/absolute value of n
e.g. |11| = 11 and |4| = 4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
===================================================================================================
Answer: -59231  
*/

long long proj027(long long n)
{
	long long i,j;
	long long result=0, temp=0;
	int counter=0, maxCounter=0;
	int flag;
	for (i=(-1)*n;i<=n;i++)
	{
		for (j=(-1)*n;j<=n;j++)
		{
			flag=1;
			counter=0;
			while (flag)
			{
				temp=counter*counter+counter*i+j;
				if (!(isPrime(temp))) flag=0;
				counter++;
			}
			if (counter>maxCounter) {maxCounter=counter; result=i*j;
			}
		}
	}
	return (result);
}
/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
===================================================================================================
Answer: 669171001  
*/
long long proj028(long long n)
{
	long long i;
        long long result=0;
	long long a0=1, b0=1, c0=1,d0=1;
	long long a,b,c,d;
	for (i=1;i<=n;i++)
	{
		a=a0+2+8*(i-1);
		result+=a;
		a0=a;

		b=b0+4+8*(i-1);
		result+=b;
		b0=b;

		c=c0+6+8*(i-1);
		result+=c;
		c0=c;

		d=d0+8+8*(i-1);
		result+=d;
		d0=d;
	}
	return (result+1);
}



/*


Consider all integer combinations of ab for 2 ≤ a ≤ 5 and 2 ≤ b ≤ 5:

    22=4, 23=8, 24=16, 25=32
    32=9, 33=27, 34=81, 35=243
    42=16, 43=64, 44=256, 45=1024
    52=25, 53=125, 54=625, 55=3125

If they are then placed in numerical order, with any repeats removed, we get the following sequence of 15 distinct terms:

4, 8, 9, 16, 25, 27, 32, 64, 81, 125, 243, 256, 625, 1024, 3125

How many distinct terms are in the sequence generated by ab for 2 ≤ a ≤ 100 and 2 ≤ b ≤ 100?

===================================================================================================
Answer:
	9183
*/
long long proj029(int n)
{
	long long i,j,k=0;
	int sqrt2_N=(long long)(sqrt((double)(n)))+1;
	for (i=2;i<n;i++)
	{
		j=i*i;
		while (j<n)
		{
			j*=i;
			k++;
		}
	}
	return (n-1)*(n-1)-k;
}
