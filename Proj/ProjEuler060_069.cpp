#include "stdafx.h"
#include "Additional/SomeMathFunc.h"
using namespace std;



/*
Project Euler67
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
////////////////////////////////////////////////////////////////////////////////////////////////////////
Answer: 7273  
See ProjectEuler Problem - 18
 */


/*
Euler's Totient function, φ(n) [sometimes called the phi function], is used to determine the number of numbers less than n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, φ(9)=6.
n 	Relatively Prime 	φ(n) 	n/φ(n)
2 	1 					1		2
3 	1,2 				2 		1.5
4 	1,3 				2 		2
5 	1,2,3,4 			4 		1.25
6 	1,5 				2 		3
7 	1,2,3,4,5,6 		6 		1.1666...
8 	1,3,5,7 			4 		2
9 	1,2,4,5,7,8 		6 		1.5
10 	1,3,7,9 			4 		2.5

It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
==============================================================================================================================
Answer:	510510
*/
long long proj069(long long n)
{
	long long i,result=0;

	double value,maxvalue=0;;

	for (i=2;i<=n;i++)
	{
		value=double(i)/EulerTotientFunc(i);
		if (value>maxvalue) {
			maxvalue=value;
			result=i;
		}
		if ((i%10000)==0)
			cout <<i<<endl;
	}
	return result;
}
