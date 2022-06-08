// WEEK 11 Question no 02
/*
II. Given a set of available types of coins. Let suppose you have infinite supply of each type of coin.
For a given value N, you have to Design an algorithm and implement it using a program to find
number of ways in which these coins can be added to make sum value equals to N.
Input Format: 
First line of input will take number of coins that are available. 
Second line of input will take the value of each coin. 
Third line of input will take the value N for which you need to find sum.
Output Format: 
Output will be the number of ways.
Solved Example: Let coin value set is C = {2,3,6,5} and the value N = 10. There are five
solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. Hence the output is 5.
*/

#include<iostream>
#define size 30 
using namespace std;

int count(int S[], int m, int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
		return 0;
	if (m <= 0 && n >= 1)
		return 0;
	return count(S, m - 1, n) +
		count(S, m, n - S[m - 1]);
}

int main()
{
	int n,m;
    cin>>n;
    int arr[size];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>m;
	cout << " " << count(arr, n, m);
	return 0;
}