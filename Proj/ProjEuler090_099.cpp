#include "stdafx.h"
#include "Additional/SomeMathFunc.h"
using namespace std;

/*
A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44  32  13  10  1  1
85  89  145  42  20  4  16  37  58  89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?
===================================================================================================
Answer: 8581146  
*/
long long proj092(long long n)
{
	long long i,j,k,temp,result=0;
	for (i=2;i<n;i++)
	{
		j=i;
		while ((j!=89)&&(j!=1))
		{
			k=j; 
			temp=0;
			while (k)
			{
				temp+=(k%10)*(k%10);
				k=k/10;
			}
			j=temp;
		}
		if (j==89) result++;
		if (i%100000==0) cout << i <<" = " << i <<endl;
	}
	return result;
}


/*


Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear, but credit must be attributed to Leonhard Euler who invented a similar, and much more difficult, puzzle idea called Latin Squares. The objective of Su Doku puzzles, however, is to replace the blanks (or zeros) in a 9 by 9 grid in such that each row, column, and 3 by 3 box contains each of the digits 1 to 9. Below is an example of a typical starting puzzle grid and its solution grid.
0 0 3
9 0 0
0 0 1 	0 2 0
3 0 5
8 0 6 	6 0 0
0 0 1
4 0 0
0 0 8
7 0 0
0 0 6 	1 0 2
0 0 0
7 0 8 	9 0 0
0 0 8
2 0 0
0 0 2
8 0 0
0 0 5 	6 0 9
2 0 3
0 1 0 	5 0 0
0 0 9
3 0 0
	
	
4 8 3
9 6 7
2 5 1 	9 2 1
3 4 5
8 7 6 	6 5 7
8 2 1
4 9 3
5 4 8
7 2 9
1 3 6 	1 3 2
5 6 4
7 9 8 	9 7 6
1 3 8
2 4 5
3 7 2
8 1 4
6 9 5 	6 8 9
2 5 3
4 1 7 	5 1 4
7 6 9
3 8 2

A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be necessary to employ "guess and test" methods in order to eliminate options (there is much contested opinion over this). The complexity of the search determines the difficulty of the puzzle; the example above is considered easy because it can be solved by straight forward direct deduction.

The 6K text file, sudoku.txt (right click and 'Save Link/Target As...'), contains fifty different Su Doku puzzles ranging in difficulty, but all with unique solutions (the first puzzle in the file is the example above).

By solving all fifty puzzles find the sum of the 3-digit numbers found in the top left corner of each solution grid; for example, 483 is the 3-digit number found in the top left corner of the solution grid above.

Answer:
	24702
*/


int simple_way_proj096(int mas[9][9], int depth)
{
	int i,j,k,oldcounter=0,newcounter=0,result=0;
	int a,b;
	int debugflag=0;

	set<int> notincluded[9][9];
	set<int> included;

	set<int> normalset;
	for (j=1;j<=9;j++)
		normalset.insert(j);
	newcounter=0;
	for (j=0;j<9;j++)
	{
		for (i=0;i<9;i++)
		{
			if (mas[j][i]!=0)
			{
				newcounter++;
				//Find lines
				for (k=0;k<9;k++)
				{
					if (!mas[k][i]) 
					{
						notincluded[k][i].insert(mas[j][i]);
					}
					if (!mas[j][k]) 
					{
						notincluded[j][k].insert(mas[j][i]);
					}
				}
				//Find squaremates
				a=(j/3)*3;
				b=(i/3)*3;
				for (k=0;k<3;k++)
				{
					if (!mas[a+k][b]) 
					{
						notincluded[a+k][b].insert(mas[j][i]);
					}
					if (!mas[a+k][b+1]) 
					{
						notincluded[a+k][b+1].insert(mas[j][i]);
					}
					if (!mas[a+k][b+2]) 
					{
						notincluded[a+k][b+2].insert(mas[j][i]);
					}
				}
			}
		}
	}


	// Check counter (new digits found) and check flag o
	int flag=1;
	//if flag=0 then there is no solve, return to previous layer
	while ((flag)&&(newcounter<81))
	{
		if (oldcounter==newcounter)
			//cycle, no new values
		{
			int max_j=-1,max_i=-1;	int max_size=0;
			if (debugflag) cout <<"Tupic, DEPTH="<<depth<<endl;
			for (j=0;j<9;j++)
			{
				for (i=0;i<9;i++)
				{
					if (debugflag) cout <<mas[j][i];
					if ((mas[j][i]==0)&&(notincluded[j][i].size()>max_size))
					{
						max_j=j;max_i=i;max_size=notincluded[j][i].size();
					}
				}
				if (debugflag) cout << endl;
			}
			if (debugflag) cout << endl;
			//check correctness
			if (max_size==9) //incorrect matrix
			{
				result=0;
				flag=0;
				break;
			} else 
			{//correct matrix, try to choose right value
				included.clear();
				//search possible values with minimum alternatives
				std::set_difference(normalset.begin(),normalset.end(),
					notincluded[max_j][max_i].begin(),notincluded[max_j][max_i].end(),
					inserter(included, included.begin()));
				int val_arr[9][9];

				set<int>::iterator Iter;
				
				for (Iter=included.begin(); Iter!= included.end(); Iter++)
				{
					for (j=0;j<9;j++)
					{
						for (i=0;i<9;i++)
						{
							val_arr[j][i]=mas[j][i];
						}
					}
					val_arr[max_j][max_i]=*Iter;
					if (debugflag) cout <<"val_arr["<<max_j<<"]["<<max_i<<"]="<<val_arr[max_j][max_i]<<endl;
					//If find best
					int retval=0;
					retval=simple_way_proj096(val_arr,depth+1);
					if (retval==1)
					{
						for (j=0;j<9;j++)
						{
							for (i=0;i<9;i++)
							{
								mas[j][i]=val_arr[j][i];
							}
						}
						newcounter=81;
						break;
					}
					else 
						if (debugflag) 
							cout << "Back to level "<< depth<< endl;
				}
				// in one cell there is no solving digits, so all matrix is wrong
				result=0;
				flag=0;
			}


		}
		else
		{// We found new digits in matrix, continue solving
			oldcounter=newcounter;
			for (j=0;j<9;j++)
			{
				for (i=0;i<9;i++)
				{
					if (mas[j][i]==0)
					{
						included.clear();
						std::set_difference(normalset.begin(),normalset.end(),
							notincluded[j][i].begin(),notincluded[j][i].end(),inserter(included, included.begin()));
						if (included.size()==1)
						{
							//cout << "mas["<<j<<"]["<<i<<"]="<<*included.begin()<<endl;
							mas[j][i]=*included.begin();
							
							newcounter++;
							//Find lines
							for (k=0;k<9;k++)
							{
								if (!mas[k][i]) 
								{
									notincluded[k][i].insert(*included.begin());
								}
								if (!mas[j][k]) 
								{
									notincluded[j][k].insert(*included.begin());
								}
							}
							//Find squaremates
							a=(j/3)*3;
							b=(i/3)*3;
							for (k=0;k<3;k++)
							{
								if (!mas[a+k][b]) 
								{
									notincluded[a+k][b].insert(*included.begin());
								}
								if (!mas[a+k][b+1]) 
								{
									notincluded[a+k][b+1].insert(*included.begin());
								}
								if (!mas[a+k][b+2]) 
								{
									notincluded[a+k][b+2].insert(*included.begin());
								}
							}
						}
					}
				}
			}
		}

	}
	if (newcounter==81) result=1;
	return result;

}

long long proj096()
{
        int i,j,oldcounter=0,result=0;
        int a;

	string str;
	string tmp;

	int matr[9][9];
	


    ifstream in("Resources/96.txt", ios::in);
	if (!in)
	{
		cout << "Can't open file!\n";
	}
	while ( getline(in, str))
    {
		oldcounter++;
		cout << "Grid No"<< oldcounter<< endl;
		for (j=0;j<9;j++)
		{
			getline(in, str);
			for (i=0;i<9;i++)
			{
				matr[j][i]=chr(str[i]);
				//notincluded[j][i].clear();
				cout <<matr[j][i]<<" ";
			}
			cout << endl;
		}
	
		a=simple_way_proj096(matr,0);		
		if (a!=1) cout <<"ERROR";
		cout << endl;
		for (j=0;j<9;j++)
		{
			//getline(in, str);
			for (i=0;i<9;i++)
			{
			//	matr[j][i]=chr(str[i]);
			//	notincluded[j][i].clear();
				cout <<matr[j][i]<<" ";
			}
			cout << endl;
		}
		cout << endl;
		result+=matr[0][0]*100+matr[0][1]*10+matr[0][2];
	}


	in.close();

	return result;
}

/*
The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^69725931; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2p1, have been found which contain more digits.

However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433*2^7830457+1.

Find the last ten digits of this prime number.
===================================================================================================
Answer: 8739992577  
*/
long long proj097()
{
	long long n=7830457, p=28433;
        long long i=0;
	long long result=0,sum=2;;

	for (i=1;i<n;i++)
	{
		sum=(sum*2)%10000000000;
	}
	result=(sum*p+1)%10000000000;
	//cout <<endl;
	return (result);
}
/*
Comparing two numbers written in index form like 211 and 37 is not difficult, as any calculator would confirm that 211 = 2048 < 37 = 2187.

However, confirming that 632382^518061 > 519432^525806 would be much more difficult, as both numbers contain over three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.

===================================================================================================
Answer:
	709
*/

long long proj099()
{
        int i; int a,b; double maxsize=0; long long result=-1;
	double mas;

	FILE *f;
    if ((f=fopen ("Resources/99.txt","r"))==NULL)
    {
        printf("File not found"); 
    } else
    {
		for (i=1;i<=1000;i++)
		{
			fscanf(f,"%d,%d\n", &a,&b);
			mas=b*log(double(a));
			if (mas>maxsize) {maxsize=mas;result=i;}
		}
		fclose(f);
	}
	return result;
}
