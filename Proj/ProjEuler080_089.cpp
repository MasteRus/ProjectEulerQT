#include "stdafx.h"
#include "Additional/SomeMathFunc.h"
using namespace std;




/*
In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.

	
131	673	234	103	18
201	96	342	965	150
630	803	746	422	111
537	699	497	121	956
805	732	524	37	331
	

Find the minimal path sum, in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by only moving right and down.

===================================================================================================

Answer: 427337
*/
long long proj081()
{
        long long i,result=0,m=0,n=0;
		FILE *f;
    if ((f=fopen ("Resources/81b.txt","r"))==NULL)
    {
        printf("File not found"); return (0);
    } else
    {
		fscanf(f,"%d,%d", &m,&n);
		int **arr;
		arr=new int *[m+1];       
		
		int **path;
		path=new int *[m+1];       

		for (int j=0;j<m; j++)
		{
			arr[j]=new int [n+1];  
			path[j]=new int [n+1];  
			for (i=0;i<n;i++)
			{
				fscanf(f,"%d,", &arr[j][i]);
				path[j][i]=INT_MAX;  
			}
			arr[j][n]=0;
			path[j][n]=INT_MAX;
		}
		arr[m]=new int [n+1];
		path[m]=new int [n+1];
		for (i=0;i<n+1;i++)
		{
			arr[m][i]=0;
			path[m][i]=INT_MAX;
		}
		fclose(f);

		path[0][0]=arr[0][0];
		for (int j=0;j<m; j++)
		{
			for (i=0;i<n;i++)
			{
				if (path[j][i]+arr[j][i+1]<path[j][i+1]) 
					path[j][i+1]=path[j][i]+arr[j][i+1];
				if (path[j][i]+arr[j+1][i]<path[j+1][i]) 
					path[j+1][i]=path[j][i]+arr[j+1][i];
			}
		}
		
		result=path[m-1][n-1];
		
		
		cout << "result";
		return (result);
	}

}
/*
NOTE: This problem is a more challenging version of Problem 81.

The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column, and only moving up, down, and right, is indicated in red and bold; the sum is equal to 994.

	
131	673	234	103	18
201	96	342	965	150
630	803	746	422	111
537	699	497	121	956
805	732	524	37	331
	

Find the minimal path sum, in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing a 80 by 80 matrix, from the left column to the right column.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Answer:
	260324
*/
void proj082rec(int **arr, int **path, int value, int jj, int ii,int m, int n)
{
	if (jj>1)
	{
		if (path[jj][ii]+arr[jj-1][ii]<path[jj-1][ii]) //up
		{
			path[jj-1][ii]=path[jj][ii]+arr[jj-1][ii];
			proj082rec(arr,path,path[jj-1][ii],jj-1,ii,m,n);
		}
	}
	if (ii<n)
	{
		if (path[jj][ii]+arr[jj][ii+1]<path[jj][ii+1]) //right
		{
			path[jj][ii+1]=path[jj][ii]+arr[jj][ii+1];
			proj082rec(arr,path,path[jj][ii+1],jj,ii+1,m,n);
		}
	}

	if (jj<m)
	{
		if (path[jj][ii]+arr[jj+1][ii]<path[jj+1][ii]) //down
		{
			path[jj+1][ii]=path[jj][ii]+arr[jj+1][ii];
			proj082rec(arr,path,path[jj+1][ii],jj+1,ii,m,n);
		}
	}
}

long long proj082()
{
        long long i,j,result=0,m=0,n=0;
		FILE *f;
    if ((f=fopen ("Resources/81b.txt","r"))==NULL)
    {
        printf("File not found"); return (0);
    } else
    {
		fscanf(f,"%d,%d", &m,&n);
		int **arr;
		arr=new int *[m+2];       
		
		int **path;
		path=new int *[m+2];       

		arr[0]=new int [n+2];
		path[0]=new int [n+2];



        for (j=1;j<m+1; j++)
		{
            arr[j]=new int [n+2];
            path[j]=new int [n+2];
			for (i=1;i<n+1;i++)
			{
				fscanf(f,"%d,", &arr[j][i]);
				path[j][i]=INT_MAX;  
			}

			arr[j][0]=0;
			path[j][0]=INT_MAX;

			arr[j][n+1]=0;
			path[j][n+1]=INT_MAX;
		}
		fclose(f);
        arr[m+1]=new int [n+2];
        path[m+1]=new int [n+2];
        for (i=1;i<n+2;i++)
        {
            arr[0][i]=0;
            path[0][i]=INT_MAX;

            arr[m+1][i]=0;
            path[m+1][i]=INT_MAX;
        }

		for (j=1;j<n+1;j++)
		{
			path[j][1]=arr[j][1];
		}
		for (j=1;j<n+1;j++)
		{
			proj082rec(arr,path,path[j][1],j,1,m,n);
		}
		
		result=INT_MAX;
		for (j=1;j<n+1;j++)
		{
			if (result>path[j][n]) result=path[j][n];
		}
		return (result);
	}
}

/*
NOTE: This problem is a significantly more challenging version of Problem 81.

In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by moving left, right, up, and down, is indicated in bold red and is equal to 2297.

	
131	673	234	103	18
201	96	342	965	150
630	803	746	422	111
537	699	497	121	956
805	732	524	37	331
	

Find the minimal path sum, in matrix.txt (right click and 'Save Link/Target As...'), a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by moving left, right, up, and down.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Answer:
	425185
*/

void proj083rec(int **arr, int **path, int value, int jj, int ii,int m, int n)
{
	if (jj>1)
	{
		if (path[jj][ii]+arr[jj-1][ii]<path[jj-1][ii]) //up
		{
			path[jj-1][ii]=path[jj][ii]+arr[jj-1][ii];
			proj083rec(arr,path,path[jj-1][ii],jj-1,ii,m,n);
		}
	}
	if (ii<n)
	{
		if (path[jj][ii]+arr[jj][ii+1]<path[jj][ii+1]) //right
		{
			path[jj][ii+1]=path[jj][ii]+arr[jj][ii+1];
			proj083rec(arr,path,path[jj][ii+1],jj,ii+1,m,n);
		}
	}
	if (jj<m)
	{
		if (path[jj][ii]+arr[jj+1][ii]<path[jj+1][ii]) //down
		{
			path[jj+1][ii]=path[jj][ii]+arr[jj+1][ii];
			proj083rec(arr,path,path[jj+1][ii],jj+1,ii,m,n);
		}
	}
	if (ii>1)
	{
		if (path[jj][ii]+arr[jj][ii-1]<path[jj][ii-1]) //left
		{
			path[jj][ii-1]=path[jj][ii]+arr[jj][ii-1];
			proj083rec(arr,path,path[jj][ii-1],jj,ii-1,m,n);
		}
	}
}



long long proj083()
{
        long long i,result=0,m=0,n=0;
	FILE *f;
    if ((f=fopen ("Resources/81b.txt","r"))==NULL)
    {
        printf("File not found"); return (0);
    } else
    {
		fscanf(f,"%d,%d", &m,&n);
		int **arr;
		arr=new int *[m+2];       
		int **path;
		path=new int *[m+2];       

		arr[0]=new int [n+2];
		path[0]=new int [n+2];



		for (int j=1;j<m+1; j++)
		{
            arr[j]=new int [n+2];
            path[j]=new int [n+2];
			for (i=1;i<n+1;i++)
			{
				fscanf(f,"%d,", &arr[j][i]);
				path[j][i]=INT_MAX;  
			}
			arr[j][0]=0;
			path[j][0]=INT_MAX;
			arr[j][n+1]=0;
			path[j][n+1]=INT_MAX;
		}
        arr[m+1]=new int [n+2];
        path[m+1]=new int [n+2];
        for (i=1;i<n+2;i++)
        {
            arr[0][i]=0;
            path[0][i]=INT_MAX;
            arr[m+1][i]=0;
            path[m+1][i]=INT_MAX;
        }
        fclose(f);

		path[1][1]=arr[1][1];
		proj083rec(arr,path,path[1][1],1,1,m,n);
		result=path[m][n];
		return (result);
	}
}




/*
The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact, there are exactly four numbers below fifty that can be expressed in such a way:

28 = 2^2 + 2^3 + 2^4
33 = 3^2 + 2^3 + 2^4
49 = 5^2 + 2^3 + 2^4
47 = 2^2 + 3^3 + 2^4

How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
=====================================================================================================================
Answer:
	1097343
*/
long long proj087(long long n)
{
        long long i=1,j=0,k=0,z=0, result=0;
	set<int> tmp;
	
    long long a=(long long)(pow((double)(n),(double)(1)/2))+1;
    long long b=(long long)(pow((double)(n),(double)(1)/3))+1;
    long long c=(long long)(pow((double)(n),(double)(1)/4))+1;

	
	for (i=2;i<a;i++)
	{
		if (isPrime2(i)&&((n-i*i)>0)){
			for (j=2;j<b;j++)
			{
				if (isPrime2(j)&&((n-i*i-j*j*j)>0)){
					for (k=2;k<c;k++)
					{
					if (isPrime2(k))
						{
							z=i*i+j*j*j+k*k*k*k;
							if (z<n) 
							{
								tmp.insert(z); 
								
							}
							else break;
							//if (z==49999927) 
							//	cout << "i=" <<i << ", j=" <<j << ", k="<<k <<endl;
							if (tmp.size()%10000==0) 
								cout << "i=" <<i << ", j=" <<j << ", k="<<k <<endl;
						}
					}
				} 
			}
		}
	}	
	result=tmp.size();
	cout << "result=" <<result <<endl;
	tmp.clear();

	return result;
}
