#include "stdafx.h"
#include "Additional/SomeMathFunc.h"
#include "Additional/Bigint.h"
using namespace std;

/*
Three distinct points are plotted at random on a Cartesian plane, for which -1000 ≤ x, y ≤ 1000, such that a triangle is formed.

Consider the following two triangles:

A(-340,495), B(-153,-910), C(835,-947)
X(-175,41), Y(-421,-714), Z(574,-645)

It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not.

Using triangles.txt (right click and 'Save Link/Target As...'), a 27K text file containing the co-ordinates of one thousand "random" triangles, find the number of triangles for which the interior contains the origin.

NOTE: The first two examples in the file represent the triangles in the example given above.
======================================================================================================================
Answer:	228
*/
long long proj102()
{
        long long i,result=0;
	int x1,y1,x2,y2,x3,y3,a,b,c;
	
	FILE *f;
    if ((f=fopen ("Resources/102.txt","r"))==NULL)
    {
        printf("File not found"); return (0);
    } else
	{
		for (i=0;i<1000;i++)
		{
                        fscanf(f, "%d,%d,%d,%d,%d,%d\n",&x1,&y1,&x2,&y2,&x3,&y3);
			a = x1 * (y2 - y1) - (x2 - x1) * y1 ;
            b = x2 * (y3 - y2) - (x3 - x2) * y2;
            c = x3 * (y1 - y3) - (x1 - x3) * y3;
			if ((a==0)||(b==0)||(c==0)) cout <<a << ","<< b<<","<<c<<endl;
			if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)) 
				result++;
		}
		fclose(f);
	}
	return result;
}

/*
@ToRefactor
@BadPerfomance

The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

It turns out that F541, which contains 113 digits, is the first Fibonacci number for which the last nine digits are 1-9 pandigital (contain all the digits 1 to 9, but not necessarily in order). And F2749, which contains 575 digits, is the first Fibonacci number for which the first nine digits are 1-9 pandigital.

Given that Fk is the first Fibonacci number for which the first nine digits AND the last nine digits are 1-9 pandigital, find k.
===============================================================================================================================
Answer:
	329468
*/
long long proj104()
{
	long long i=2,j,k;
	int flag1=0,flag2=0;
        BigInt an_1("1");
        BigInt an_2("1");
	BigInt an("1");
	j=1;
	
	vector<int> tmp1;
	vector<int> tmp2;
	vector<int> tmp;
	tmp.push_back(0);
	for (j=0;j<9;j++)
	{
		tmp.push_back(1);
	}
	while (!flag1)
	{
		flag1=0;flag2=0;
		tmp1.clear();
		tmp2.clear();
		tmp1.resize(10);
		tmp2.resize(10);
		
		an_2=an_1;
		an_1=an;
		an=an_1+an_2
			;
		i++;
		an.GetValue().size();
		k=an.GetValue().size();
		if (i%1000==0) 
			cout << i << " contains " << k << endl;
		
		if (k>17)
		{
			for (j=0;j<9;j++)
			{
				tmp1[an.GetValue()[j]]++;
				tmp2[an.GetValue()[j+k-9]]++;
			}
			//if ((tmp1==tmp)) cout << "hurra 1.i=" << i<<endl;
			//if ((tmp2==tmp)) cout << "hurra 2.i=" << i<<endl;
			if ((tmp1==tmp2)&&(tmp1==tmp))
			{
				flag1=1;
			}
			//an.Print();
		}
	} 
	//if (an_1==an_2) cout << "Yes"; else cout << "no";
	return i;
}
/*


The following undirected network consists of seven vertices and twelve edges with a total weight of 243.

The same network can be represented by the matrix below.
    	A	B	C	D	E	F	G
A	-	16	12	21	-	-	-
B	16	-	-	17	20	-	-
C	12	-	-	28	-	31	-
D	21	17	28	-	18	19	23
E	-	20	-	18	-	-	11
F	-	-	31	19	-	-	27
G	-	-	-	23	11	27	-

However, it is possible to optimise the network by removing some edges and still ensure that all points on the network remain connected. The network which achieves the maximum saving is shown below. It has a weight of 93, representing a saving of 243 − 93 = 150 from the original network.

Using network.txt (right click and 'Save Link/Target As...'), a 6K text file containing a network with forty vertices, and given in matrix form, find the maximum saving which can be achieved by removing redundant edges whilst ensuring that the network remains connected.

Answer:
	259679
*/

long long proj107()
{
        long long i,j,k,result=0;


	string str;
	string tmp;
	//char ch;

	int matr[40][40];
	int vertex[40];
	for (j=0;j<40;j++)
		vertex[j]=0;

	list<string> namelist;
    ifstream in("Resources/107b.txt", ios::in);
	if (!in)
	{
		cout << "Can't open file!\n";
	}
	while ( getline(in, str))
    {
		tmp+=str;
		tmp+=',';
	}
	list<string> arr=split(tmp,',');
	i=0;
	int sum=0;
	while (arr.size()!=0)
	{
		str=arr.front();
		arr.pop_front();
		matr[i/40][i%40]=atoi(str.data());
		sum+=matr[i/40][i%40];
		i++;
	}	
	sum/=2;
	in.close();
	arr.clear();
	
	/*
	Algorhytm Prima
	*/
	int minlegth=INT_MAX; int min_i,min_j;
	k=1;
	vertex[0]=1;
	while (k<40)
	{
		minlegth=INT_MAX;
		for (j=0;j<40;j++)
		{
			if (vertex[j])
			{
				for (i=0;i<40;i++)
				{
					if ((vertex[i]==0)&&
						(matr[j][i])&&
						(matr[j][i]<minlegth)
					   )
					{
						minlegth=matr[j][i];
						min_i=i;min_j=j;
					}
				}
			}
		}

		if (
			(minlegth!=INT_MAX)
			&&(
			((vertex[min_i])&&(!vertex[min_j]))
				||
				((!vertex[min_i])&&(vertex[min_j]))
			)
		   ) 
		{
			result+=minlegth;
			vertex[min_i]++;
			vertex[min_j]++;
			//break;
		}
		k++;
	}

	result=sum-result;
	return result;
}

/*
Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.

Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.

We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.

Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy. In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.

Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.

Find the least number for which the proportion of bouncy numbers is exactly 99%.
===================================================================================================
Answer: 1587000
*/
long long proj112()
{
        long long i=10,j,k,result=0,flag1, flag2, step=0;
	double ratio=0;


    //char str[100];
    string str;

	while (ratio!=0.99)
	{
		i++;
		j=i;
		k=10;
		step=0;
		flag1=1;
		flag2=1;
		//desc

                str=string_itoa(i,10);
                //_itoa(i,str,10);
                for (j=0;j<str.size()-1;j++)
                {
                    if (str[j]<str[j+1]) flag1=0;
                    if (str[j]>str[j+1]) flag2=0;
                }
		if (!((flag1)||(flag2))) result++;
		ratio=(double)(result)/(i);
		//if (i%300==0) cin  >> k;
        if (i%1000==0)
            cout << i <<" = " << result << "/" << i<<" = " << ratio <<endl;
	}
	cout << i <<" = " << result << "/" << i<<" = " << ratio <<endl;
    return i;
}
