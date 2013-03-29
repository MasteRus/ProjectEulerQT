#include "../stdafx.h"
#include "Bigint.h"

BigInt::BigInt(void)
{
}

BigInt::~BigInt(void)
{
}


// Forward leading order
BigInt::BigInt(int mas[], int n, int zn)
{
	int i;
	for (i=0;i<n;i++)
	{
		//Value.push_back(mas[i]);	
		Value.insert(Value.begin(),mas[i]);
	}
	this->LeadingNulls();
}

BigInt::BigInt(char str[] )
{
	int i;
	//sign=((str[0]=='-') ? -1:1);
	for (i=0;i<strlen(str);i++)
	{
		//if (isdigit(str[i])) Value.push_back(str[i]-48);	
		if (isdigit(str[i])) Value.insert(Value.begin(),str[i]-48);	
	}
	LeadingNulls();
	if (Value.size()==0) Value.push_back(0);
		
}

BigInt::BigInt(int val)
{
	long long i=val;
	int k;
	if (!(val)) Value.push_back(0);
	else 
		while (i)
		{
			k=i%10;
			Value.push_back(k);
			i=i/10;
		}
}
BigInt::BigInt(long val)
{
	long long i=val;
	int k;
	if (!(val)) Value.push_back(0);
	else 
		while (i)
		{
			k=i%10;
			Value.push_back(k);
			i=i/10;
		}
}
BigInt::BigInt(long long val)
{
	long long i=val;
	int k;
	if (!(val)) Value.push_back(0);
	else 
		while (i)
		{
			k=i%10;
			Value.push_back(k);
			i=i/10;
		}
}
void BigInt::Print()
{
	long long i;
	for (i=Value.size()-1;i>=0;i--)
	{
		cout << Value[i] ;
	}
	//cout << endl;
}

vector<int>& BigInt::GetValue()
{
	return Value;
}

void BigInt::LeadingNulls()
{
	while ((Value.back()==0)&&(Value.size()>1))
	{
		Value.pop_back();
	}
}

int BigInt::operator==(BigInt Num)
{
	//return (((Value==Num.Value)&&(sign==Num.sign)) ? 1:0);
	return ((Value==Num.Value) ? 1:0);
};

int BigInt::operator!=(BigInt Num)
{
	//return (((Value!=Num.Value)||(sign!=Num.sign)) ? 1:0);
	return ((Value!=Num.Value) ? 1:0);
}


BigInt& BigInt::operator=(const BigInt& MyBigInt)
{
	Value=MyBigInt.Value;
	//sign=MyBigInt.sign;
	return *this;
}
//@TODO Refactoring
BigInt& BigInt::operator=(const int val)
{
	Value.clear();
	long long i=val;
	int k;
	if (!(val)) Value.push_back(0);
	else 
		while (i)
		{
			k=i%10;
			Value.push_back(k);
			i=i/10;
		}
	return *this;
}
BigInt& BigInt::operator=(const long long val)
{
Value.clear();
	long long i=val;
	int k;
	if (!(val)) Value.push_back(0);
	else 
		while (i)
		{
			k=i%10;
			Value.push_back(k);
			i=i/10;
		}
	return *this;
}

BigInt BigInt::operator+(BigInt MyBigInt) const
{
        long long i;
	long long buf=0,val=0;
	long long val_size=Value.size(),val2_size=MyBigInt.Value.size();
	int size=max(val_size, val2_size);
	BigInt retval("0");//=*this;
	BigInt addedval("0");//=MyBigInt;
	if (val_size>val2_size) 
	{
		retval=*this;
		addedval=MyBigInt;
		for (i=0;i<val_size-val2_size;i++)
			addedval.GetValue().push_back(0);
	} else{
		retval=MyBigInt;
		addedval=*this;
		for (i=0;i<val2_size-val_size;i++)
			addedval.GetValue().push_back(0);
	}
	
	for (i=0;i<size;i++)
	{
		val=(retval.Value[i]+addedval.Value[i]+buf)%10;
		buf=(retval.Value[i]+addedval.Value[i]+buf)/10;
		retval.Value[i]=val;
	}
	

	if (buf!=0)
	{
		while (buf!=0)
		{
			val=(buf)%10;
			buf=(buf)/10;
			retval.Value.push_back(val);

			i++;
		}
	}
	retval.LeadingNulls();
	return retval;
}


BigInt BigInt::operator*(int factor) const
{
	BigInt retval("0");//=*this;
	retval=*this;
	long long i;
	long long buf=0,val=0;

	long long size=Value.size();
	for (i=0;i<size;i++)
	{
		val=(retval.Value[i]*factor+buf)%10;
		buf=(retval.Value[i]*factor+buf)/10;
		retval.Value[i]=val;
	}


	if (buf!=0)
	{
		while (buf!=0)
		{
			val=(buf)%10;
			buf=(buf)/10;
			retval.Value.push_back(val);

			i++;
		}
	}
	retval.LeadingNulls();
	return retval;
}

bool BigInt::operator>(BigInt val)
{
	int result=-1;
	if (Value.size()>val.GetValue().size()) result=1;
	else 
		if (Value.size()<val.GetValue().size()) result=0;
		else
		{
			int valsize=Value.size();
                        int i;
			
			for (i=(valsize-1);i>=0;i--)
			{
				if (Value[i]<val.GetValue()[i] )
				{result=0;break;}
				else 
					if (Value[i]>val.GetValue()[i] )
						{result=1;break;}
			}
			if (result==-1) result=1;
		}
	return result;
}

bool BigInt::operator>(long long val)
{
	BigInt k(val);
	
	return (*this>k);
}

bool BigInt::operator>=(BigInt val)
{
	//if (Value>val.Value) return 0;
	int result=-1;
	if (Value.size()>val.GetValue().size()) result=1;
	else 
		if (Value.size()<val.GetValue().size()) result=0;
		else
		{
			int valsize=Value.size();
                        int i;
			
			for (i=(valsize-1);i>=0;i--)
			{
				if (Value[i]<val.GetValue()[i] )
				{result=0;break;}
				else 
					if (Value[i]>val.GetValue()[i] )
						{result=1;break;}
			}
			if (result==-1) result=1;
		}
	return result;
}

bool BigInt::operator>=(long long val)
{
	BigInt k(val);
	
	return (*this>=k);
}


bool BigInt::operator<(BigInt val)
{
	bool res=(!(*this>=val));
	//return (!(*this>=val));
	return res;
}

bool BigInt::operator<(long long val)
{
	BigInt k(val);
	
	return (!(*this>=k));
}
bool BigInt::operator<=(BigInt val)
{
	return (!(*this>val));
}

bool BigInt::operator<=(long long val)
{
	BigInt k(val);
	
	return (!(*this>k));
}


long long BigInt::SumOfDigit()
{
	long long val=0,i=0;
	for (i=0;i<Value.size();i++)
		val+=Value[i];

	
	return val;
}

