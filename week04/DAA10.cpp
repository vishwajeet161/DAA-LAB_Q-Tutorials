// WEEK 4 QUESTION NO. 01

/*Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by dividing the array into two subarrays and combining these subarrays
after sorting each one of them. Your program should also find number of comparisons and
inversions during sorting the array.
Input Format: 
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output Format:
The output will have T number of lines. 
For each test case T, there will be three output lines.
First line will give the sorted array.
Second line will give total number of comparisons.
Third line will give total number of inversions required.
*/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&v1,int l,int mid,int r)
{
    vector<int>v2,v3;
    int n1,n2;
    n1 = mid-l+1;
    n2 = r-mid;
    for(int i=0;i<n1;i++)
    {
        v2.push_back(v1.at(i+l));
    }
    for(int i=0;i<n2;i++)
    {
        v3.push_back(v1.at(mid+1+i));
    }
    int i=0,j=0,k=l;
    while(i<v2.size()&&j<v3.size())
    {
        if(v2.at(i)<v3.at(j))
        {
            v1[k] = v2[i];
            i++;
        }
        else
        {
            v1[k] = v3[j];
            j++;
        }
        k++;
    }

    while(i<v2.size())
    {
        v1[k] = v2[i];
        i++;
        k++;
    }
    while(j<v3.size())
    {
        v1[k] = v3[j];
        j++;
        k++;
    }
}

void mergesort(vector<int>&v1,int l,int r)
{ 
    if(l<r)
    {
    int mid = (l+r)/2;
    mergesort(v1,l,mid);
    mergesort(v1,mid+1,r);
    merge(v1,l,mid,r);
    }
}


int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>v1;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int key;
            cin>>key;
            v1.push_back(key);
        }
        mergesort(v1,0,n-1);
        for(int i=0;i<n;i++)
        cout<<v1.at(i)<<" ";
        cout<<endl;
    }
}
