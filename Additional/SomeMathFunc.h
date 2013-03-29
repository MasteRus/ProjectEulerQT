#include "stdafx.h"
#include <list>
#include <string>
#include <sstream>

using namespace std;

long long nod(long long m, long long n);
long long nok(long long m, long long n);
int chr(char ch);
int isPrime(long n);
int isPrime2(long n);
list<string> &split(const string &s, char delim, list<string> &elems); 
list<string> split(const string &s, char delim);
long long EulerTotientFunc(long long n);

std::string string_itoa(int value, int base);
template<class T>
T min2(T arg1, T arg2)
{
    T min;
    if (arg1<=arg2) min=arg1; else min=arg2;
    return min;
}


template<class T>
T min3(T arg1, T arg2, T arg3)
{
    T min;
    if (arg1 <= min2(arg2,arg3))
        min = arg1;
    else if (arg2 <= min2(arg1,arg3))
        min = arg2;
    else
        min = arg3;
    return min;
}
template <typename T>
string NumberToString ( T Number )
{
    stringstream ss;
    ss << Number;
    return ss.str();
}

template <typename T>
T StringToNumber ( const string &Text )//Text not by const reference so that the function can be used with a
{                               //character array as argument
    stringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
