#include "stdafx.h"
#include "Additional/SomeMathFunc.h"
using namespace std;

/*
Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ≤ 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 21 elements in this set.

How many elements would be contained in the set of reduced proper fractions for d ≤ 1,000,000?
================================================================================================================
Answer:
	303963552391
*/
long long proj072(long long n)
{
        long long i,result=0;
	

	for (i=2;i<=n;i++)
	{
		result+=EulerTotientFunc(i);
		if ((i%10000)==0)
			cout <<i<<endl;
	}
	return result;
}
/*
Consider the fraction, n/d, where n and d are positive integers. If nd and HCF(n,d)=1, it is called a reduced proper fraction.
If we list the set of reduced proper fractions for d  8 in ascending order of size, we get:
1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8
It can be seen that there are 3 fractions between 1/3 and 1/2.
How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d  12,000?
Note: The upper limit has been changed recently.

===================================================================================================
Answer: 7295372  
*/
long long proj073(long long n)
{
	long long i,j,result=0;
	double temp;
	for (i=1;i<n;i++)
	{
		for (j=1;j<i;j++)
		{
			if (nod(i,j)==1) {
				temp=(double)(j)/(i);
				if ((temp>(double)(1)/3)&&(temp<(double)(1)/2))
				{
					result++;
					if (result%1000000==0) cout<< "step=" << result <<endl;;
					//cout << j<<"/"<<i<<endl;
				}
			}
		}
		
	}
	return result;
}


/*


The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:

1! + 4! + 5! = 1 + 24 + 120 = 145

Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are only three such loops that exist:

169 → 363601 → 1454 → 169
871 → 45361 → 871
872 → 45362 → 872

It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,

69 → 363600 → 1454 → 169 → 363601 (→ 1454)
78 → 45360 → 871 → 45361 (→ 871)
540 → 145 (→ 145)

Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number below one million is sixty terms.

How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?


===================================================================================================
Answer:
	402
*/
long long proj074(long long n, long long counter)
{
        long long i=1,j=0,k=0,z=0, counter2, sumfact=0, fact=0, result=0, flag=0;

	int digit;

	vector<long long> tmp;
	for (i=3;i<n;i++)
	{
		z=i;
		flag=1;
		tmp.clear();
		while (flag)
		{
			j=z;
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

			for (counter2=0;counter2<tmp.size();counter2++)
			{
				if (sumfact==tmp[counter2])
				{
					flag=0;
					break;
				}
			}
			if (flag) tmp.push_back(sumfact);
			z=sumfact;
		}
		if (tmp.size()==counter)
		{
			result++;
			//cout << "Congrat!=" << i<< endl;
		}
		if (i%10000==0)
			cout << "i=" << i<< ", " << result<< endl;
	}
	return result;
}

/*
A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278, they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.
==================================================================================================================
Answer: 73162890
*/

string proj079()
{
	FILE *f;
    if ((f=fopen ("Resources/79.txt","r"))==NULL)
    {
        printf("File not found"); return (0);
    } else
	{
		long long i,k;
		int j;
		int a[3];
		set<int> digits[10];
		int dcount[10]={0,0,0,0,0,0,0,0,0,0};
		
		for (i=0;i<50;i++)
		{
			fscanf(f,"%d\n",&j);
			a[0]=j/100;
			a[1]=(j/10)%10;
			a[2]=j%10;
			
			dcount[a[0]]++;dcount[a[1]]++;dcount[a[2]]++;
			
			
			digits[a[0]].insert(a[1]);
			digits[a[0]].insert(a[2]);
			digits[a[1]].insert(a[1]);
		}
		vector<int> tmp;
		set<int>::iterator iter;
		k=0;
		for (i=0;i<10;i++)
		{
			if (dcount[i]) k++;
		}
		for (i=0;i<k;i++)
		{
			int digitmin=INT_MAX; int digitnum=0;
			for (j=0;j<10;j++)
				if (dcount[j])
				{
					if (digits[j].size()<digitmin) {
						digitmin=digits[j].size(); 
						digitnum=j;
					}
				}
			tmp.push_back(digitnum);
			dcount[digitnum]=0;
			for (j=0;j<10;j++)
			{
				iter=digits[j].find(digitnum);
				if (iter!=digits[j].end())
					digits[j].erase(iter);
			}
		}
		reverse(tmp.begin(), tmp.end());
		fclose(f);
		string result;
        //char str[19];
        string str;
		
		for (i=0;i<tmp.size();i++)
		{
                        //@QTReb
                        //_itoa(tmp[i],str,10);
            str=string_itoa(tmp[i],10);
			result+=str;
		}
		return result;
	}
}
