// WEEK - 02 QUESTION NO. 02
/* Given a sorted array of positive integers, design an algorithm and implement it using a program 
to find three indices i, j, k such that arr[i] + arr[j] = arr[k]. 
Input format: The first line contains number of test cases, T. For each test case, there will be two 
input lines. First line contains n (the size of array). Second line contains space-separated integers 
describing array.
Output: The output will have T number of lines. For each test case T, print the value of i, j and k, if 
found else print “No sequence found”. */


#include<iostream>
#define max 100
using namespace std;

int main()
{
    int t,n,arr[max];
    cin>>t;
    while(t)
    {
        t--;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int f=0;
        for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
        for(int k=i+1;k<n;k++)
        {
            if(arr[i]+arr[j]==arr[k])
            {
                f=1;
                cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
            }
        }
        if(f==0)
        cout<<"No sequence found"<<endl;
    }
}

