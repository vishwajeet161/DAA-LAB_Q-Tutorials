// WEEK - 02 QUESTION NO. 03
/* . Given an array of nonnegative integers, design an algorithm and a program to count the number 
of pairs of integers such that their difference is equal to a given key, K. 
Input format: The first line contains number of test cases, T. For each test case, there will be three 
input lines. First line contains n (the size of array). Second line contains space-separated integers 
describing array. Third line contains the key element.
Output format: The output will have T number of lines. For each test case T, output will be the total 
count i.e. number of times such pair exists */

#include<iostream>
#define max 100
using namespace std;

int main()
{
    int arr[max],n,t;
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int key,c=0;
        cin>>key;
        for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]-arr[j]==key||arr[j]-arr[i]==key)
            {
                c++;
            }
        }
        cout<<c;
    }
}