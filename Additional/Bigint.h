#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class BigInt
{
private:


public:
	//int sign;
	vector<int> Value;	
	BigInt(void);
	~BigInt(void);

	BigInt(int mas[], int n, int zn=1);
	
	BigInt(char str[] );
	BigInt(int val);
	BigInt(long val);
	BigInt(long long val);


	void Print();
	vector<int>& GetValue();

	BigInt& operator=(const BigInt& MyBigInt);
	BigInt& operator=(const int val);
	BigInt& operator=(const long long val);
	BigInt operator+(BigInt MyBigInt) const;
	BigInt operator*(int factor) const;
	int operator==(BigInt Num);
	int operator!=(BigInt Num);
	long long SumOfDigit();


	bool operator>(BigInt val);
	bool operator>(long long val);

	bool operator>=(BigInt val);
	bool operator>=(long long val);

	bool operator<(BigInt val);
	bool operator<(long long val);

	bool operator<=(BigInt val);
	bool operator<=(long long val);

	void LeadingNulls();
};
