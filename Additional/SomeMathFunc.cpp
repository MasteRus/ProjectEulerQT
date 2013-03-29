#include "stdafx.h"
#include <list>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

std::string string_itoa(int value, int base) {

    std::string buf;

    // check that the base if valid
    if (base < 2 || base > 16) return buf;

    enum { kMaxDigits = 35 };
    buf.reserve( kMaxDigits ); // Pre-allocate enough space.

    int quotient = value;

    // Translating number to string with base:
    do {
        buf += "0123456789abcdef"[ std::abs( quotient % base ) ];
        quotient /= base;
    } while ( quotient );

    // Append the negative sign
    if ( value < 0) buf += '-';

    std::reverse( buf.begin(), buf.end() );
    return buf;
}

int chr(char ch)
{
	return ((int)(ch)-48);
}
long long nod(long long m, long long n)
{
	long long result=0;
	if ((m>=0)&&(n>=0))
	{
		while (m!=n)
		{
			if (m>n) m=m-n; else n=n-m;
		}
		result=m;
	}
	return result;
}

long long nok(long long m, long long n)
{
	long long result=0;
	if ((m>=0)&&(n>=0))
	{
		result=n*m/nod(m,n);
	}
	return result;
}

int isPrime(long n)
{
	n=abs(n);
	if (n)
	{
		long long j;
		int flag=1;
		for (j=2;j<=(long long)(sqrt(double(n)));j++)
		{
			if (n%j==0) {flag=0; break;}
		}
	return flag;
	} else return (0);
}

int isPrime2(long n)
{
	n=abs(n);
	int flag=1;
	if (n<2) flag=-1; else 
		if (n==2) flag=1;
	else 
	{
		long long j,t=(long long)(sqrt(double(n)))+1;
		
		for (j=2;j<=t;j++)
		{
			if (n%j==0) {flag=0; break;}
		}
	
	}
	return flag;
}

list<string> &split(const string &s, char delim, list<string> &elems) { 
    stringstream ss(s); 
    string item; 
    while(getline(ss, item, delim)) { 
        elems.push_back(item); 
    } 
    return elems; 
} 
 
 
list<string> split(const string &s, char delim) { 
    list<string> elems; 
    return split(s, delim, elems); 
} 
long long EulerTotientFunc(long long n)
{
	long long result;
	
	
	if (n==1) result=1; 	
	else 
	{
		if (isPrime2(n)==1)	
			result=n-1;
		else 
		{
                        long long j,k,z,flag,counter=1;
			vector<int> vector_factors;
			vector<int> vector_counts;
			int vect_size=0;
			k=n;
			j=2;
			vector_factors.clear();
			vector_counts.clear();
			while (j<=k)
			{
				if (k%j==0)
				{
					vect_size=vector_factors.size();
					flag=0;
					for (z=0;z<vect_size;z++)
					{
						if (vector_factors[z]==j)
						{
							flag=1;	
							vector_counts[z]++;
							break;
						}
					}
					if ((!flag)||(vect_size==0))
					{
						vector_factors.push_back(j);
						vector_counts.push_back(1);
					}
					k=k/j;
				}
				else j++;
			}
			vect_size=vector_factors.size();
			counter=1;
			for (z=0;z<vect_size;z++)
			{
				counter=counter*(long long)(pow((double)(vector_factors[z]),vector_counts[z]-1))*(vector_factors[z]-1);
			}
			result=counter;
		}
	}
	return result;
}


