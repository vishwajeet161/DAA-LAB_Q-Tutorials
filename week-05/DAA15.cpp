// WEEK 5 QUESTION NO. 03

/*III. You have been given two sorted integer arrays of size m and n. Design an algorithm and
implement it using a program to find list of elements which are common to both. (Time
Complexity = O(m+n))
Input Format: 
First line contains m (the size of first array).
Second line contains m space-separated integers describing first array.
Third line contains n (the size of second array).
Fourth line contains n space-separated integers describing second array.
Output Format:
Output will be the list of elements which are common to both.
*/

#include<iostream>
#include<limits.h>
using namespace std;

void intersection(int arr1[],int n1,int arr2[],int n2)
{
    int maxi1=INT_MIN;
    for (int i=0;i<n1;i++)
    {
        if (arr1[i]>maxi1)
           maxi1=arr1[i];
    }
    int temp1[maxi1+1]={0};
    for (int i=0;i<n1;i++)
        temp1[arr1[i]]++;
        
    int maxi2=INT_MIN;
    for (int i=0;i<n2;i++)
    {
        if (arr2[i]>maxi2)
           maxi2=arr2[i];
    }
    int temp2[maxi2+1]={0};
    for (int i=0;i<n2;i++)
        temp2[arr2[i]]++;
        
    for (int i=0;i<n1;i++)
    {
        if (temp1[arr1[i]]!=0 && temp2[arr1[i]]!=0)
           cout<<arr1[i]<<" ";
    }   
}

int main()
{
    int n1;
    cin>>n1;
    int arr1[n1];
    for (int i=0;i<n1;i++)
      cin>>arr1[i];
     
    int n2;
    cin>>n2;
    int arr2[n2];
    for (int i=0;i<n2;i++)
      cin>>arr2[i];
    
    intersection(arr1,n1,arr2,n2);
    return 0;
}
