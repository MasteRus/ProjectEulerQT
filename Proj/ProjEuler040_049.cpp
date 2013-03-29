#include "stdafx.h"
#include "Additional/SomeMathFunc.h"




/*
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1*d10*d100*d1000*d10000*d100000*d1000000
===================================================================================================
Answer: 210  
*/

long long proj040()
{
        long long i=0;
	char str[100];
	string temp= "";
	while (temp.length()<=1000000)
	{
            //@QTReb
            //temp.append(itoa(i,str,10));
		i++;
	}
	//cout << temp[1] << temp[10] << temp[100] << temp[1000] << temp[10000] << temp[100000] << temp[1000000] ;
	
	return chr(temp[1])*chr(temp[10])*chr(temp[100])*chr(temp[1000])*chr(temp[10000])*chr(temp[100000])*chr(temp[1000000]);
}

/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
===================================================================================================
Answer: 7652413  
*/
long long proj041()
{
	long long i,j,k,razr,flag,flag2;
	int arr[10];
	//long long arrOfPrimes[100000], countOfPrimes=1;
	//long long arrOfPrimes[100000], countOfPrimes=1;
	//arrOfPrimes[0]=2; 
	long long result=0;
	for (i=3;i<1000000000;i=i+2)
	{

		for (j=0;j<=9;j++)
		{
			arr[j]=0;
		}
		flag=1;
		/*
		long long sqrt_i=(long long)(sqrt(double(i)));
		for (j=0;j<countOfPrimes;j++)
		{
			if (arrOfPrimes[j]<sqrt_i)
			{
				if ((i%arrOfPrimes[j])==0) 
				{
					flag=0;
					break;
				}
			}
			else {
				break;
				//cout << "test" << endl;
			}
		}
		if (flag) 
		{
			arrOfPrimes[countOfPrimes]=i;
			//cout << arrOfPrimes[countOfPrimes] << endl;
			countOfPrimes++;
				
		}
		*/
		//if (flag==1) 
		//if (i==7652413
		{
			k=i;
			razr=0;
			while (k)
			{
				razr++;
				arr[k%10]++;
				k=k/10;
			}
			flag2=1;
			for (j=1;j<=razr;j++)
				if (arr[j]!=1) {flag2=0; break;}
			if (flag2==1)  
			{
				flag=1;
				for (j=3;j<=(long long)(sqrt(double(i)));j++)
				{
					if (i%j==0) {flag=0; break;}
				}
				if (flag) {
					result=i;
					cout << result << endl;
				}
			}
		}
		//if (i>1100011) 
		if (i%1000001==0) 	cout << "i=" << i<<endl;

	}
	
	return result;
}
/*
The nth term of the sequence of triangle numbers is given by, tn = (1/2)*n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?

===================================================================================================
Answer: 162  

*/

long long proj042()
{
	long long i=0,j,k=0,result=0;
	int tn[100];
	for (i=1;i<100;i++)
	{
		tn[i]=i*(i+1)/2;
	}

	
	string str;
	string tmp;
	char ch;
    ifstream in("Resources/42.txt", ios::in);
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
		
		str=arr.front();
		arr.pop_front();
		k=0;
		for (j=0;j<str.size();j++)
		{
			k+=str[j]-64;
		}
		i=1;
		while ((tn[i]<k)&&(i<100))
		{
			i++;
		}
		if (i==100) cout << "Exception";
		if (k==tn[i]) {result++; cout << result << endl;}
		
	}
	in.close();
	return result;
}


/*
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2 
d3d4d5=063 is divisible by 3 
d4d5d6=635 is divisible by 5 
d5d6d7=357 is divisible by 7 
d6d7d8=572 is divisible by 11 
d7d8d9=728 is divisible by 13 
d8d9d10=289 is divisible by 17 
Find the sum of all 0 to 9 pandigital numbers with this property.

===================================================================================================
Answer: 16695334890  
*/
long long proj043()
{
	long long i,j,k,razr,flag,flag2;
	int arr[10];
	//long long arrOfPrimes[100000], countOfPrimes=1;
	//long long arrOfPrimes[100000], countOfPrimes=1;
	//arrOfPrimes[0]=2; 
	long long result=0;
	int by2=0,
		by3=0,
		by5=0,
		by7=0,
		by11=0,
		by13=0,
		by17=0
		; 
	for (i=1000000000;i<9876543210;i++)
	{
		//i=1406357289;
		for (j=0;j<=9;j++)
		{
			arr[j]=0;
		}
		flag=1;
		{
			k=i;
			razr=0;
			while (k)
			{
				razr++;
				arr[k%10]++;
				k=k/10;
			}
			flag2=1;
			for (j=1;j<razr;j++)
				if (arr[j]!=1) {
					flag2=0; break;}
			if (flag2==1)  
			{
				
				by2=0;by3=0;by5=0;by7=0;
				by11=0;by13=0;by17=0;
				
				by2=((i%1000000000)/1000000)%2;
				by3=((i%100000000)/100000)%3;
				by5=((i%10000000)/10000)%5;
				by7=((i%1000000)/1000)%7;
				by11=((i%100000)/100)%11;
				by13=((i%10000)/10)%13;
				by17=((i%1000))%17;
				flag=0;
				flag=by17+by13+by11+by7+by5+by3+by2;
				if (!flag) {
					result+=i;
					cout << result << endl;
				}
			}
		}
		//if (i>1100011) 
		if (i%1000001==0) 	cout << "i=" << i<<endl;
	}
	return result;
}
/*
Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

Triangle   Tn=n(n+1)/2   1, 3, 6, 10, 15, ... 
Pentagonal   Pn=n(3n1)/2   1, 5, 12, 22, 35, ... 
Hexagonal   Hn=n(2n1)   1, 6, 15, 28, 45, ... 

It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.
===================================================================================================
Answer: 1533776805  
*/
long long proj045(long long n)
{
	long long i=0, j=0,k=0;
	long long tn=0,pn=0,hn=0;
	while (!((tn==pn)&&(pn==hn))||(tn<=n))
	{
		if (tn==min3(tn,pn,hn))
		{
			i++; tn=i*(i+1)/2;		
		} else 
		{
			if (pn==min3(tn,pn,hn)) 
			{
				j++; pn=j*(3*j-1)/2;
			} else
			{
				k++; hn=k*(2*k-1);
			}
		}
		/*
		cout << "i=" << i<< ", j=" << j << ", k="<<k;
		cout << "||| tn=" << tn<< ", pn=" << pn << ", hn="<<hn;
		cout <<endl;
		*/
	}
	//cout <<endl;
	return (tn);
}

/*


It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?

===================================================================================================
Answer:	5777
*/
long long proj046()
{
        long long i=7,j=0,k=0,result=0, flag, flag2;
	flag2=1;
	//cout << isPrime(9) <<endl;
	while (flag2)
	{
		i+=2;
		if (!(isPrime(i)))
		{
			k=(long long)(sqrt(double(i)/2));
			flag=0;
			for (j=1; j<=k;j++)
			{
				result=i-2*j*j;
				if (isPrime(result)) {flag=1;break;}
			}
			if (!flag) flag2=0;
		}
	if (i%100000==1) cout << i << endl;
	}
	return i;
}

/*
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct primes factors. What is the first of these numbers?
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Answer: 134043
*/
long long proj047( int ncounter, int numbern)
{
        long long i=9,j=0,k=0, step=0,  flag=0;
	list<int> temp;
	
	while (flag==0)
	{
		
		k=i;
		//while (k>1)
		temp.clear();
		{
			for (j=2;j<=(long long)(k);j++)
			{
				if (k%j==0) {temp.push_back(j); k=k/j; j=1; }
			}
		}
			temp.unique();
		if (temp.size()==ncounter)
		{
			step++;
		} else step=0;
		if (i%10000==0) {
			cout << "i="<< i<< endl;
		}
		i++;
		if (step==numbern) flag=1;

	}

	return (i-ncounter);
};
/*
The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.
===================================================================================================
Answer: 9110846700  
*/


long long proj048(long long n)
{
	long long i=0, j=0,k=0;
	long long result=0,sum=0;;
	for (i=1;i<=n;i++)
	{
		sum=i;
		for (j=1;j<i;j++)
		{
			sum=(sum*i)%10000000000;
		}
		result+=sum;
	}
	//cout <<endl;
	return (result);
}

/*

===================================================================================================

*/
