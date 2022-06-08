//Week 11 Question no 03
/*
III. Given a set of elements, you have to partition the set into two subsets such that the sum of
elements in both subsets is same. Design an algorithm and implement it using a program to solve
this problem.
Input Format:
First line of input will take number of elements n present in the set. 
Second line of input will take n space-separated elements of the set.
Output Format: 
Output will be 'yes' if two such subsets found otherwise print 'no'.
Solved Example: Let set is S = {1, 5, 4, 11, 5, 14, 10}. Sum of the elements =
1+5+4+11+5+14+10 = 50. Now dividing the set into two halves such that sum of elements of
both the subsets = (50/2) = 25. Therefore, subsets are {1, 5, 5, 14} and {4, 11, 10}.
*/

#include<iostream>
#define size 30 
using namespace std;

bool isSubsetSum(int arr[], int n, int sum)
{
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	if (arr[n - 1] > sum)
		return isSubsetSum(arr, n - 1, sum);
	return isSubsetSum(arr, n - 1, sum) || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

bool findPartiion(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	if (sum % 2 != 0)
		return false;
	return isSubsetSum(arr, n, sum / 2);
}

int main()
{
    int n;
    cin>>n;
    int arr[size];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	if (findPartiion(arr, n) == true)
		cout << "yes";
	else
		cout << "no";
	return 0;
}