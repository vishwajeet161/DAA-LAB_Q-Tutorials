// WEEK - 03 QUESTION NO. 02
/*
II. Given an unsorted array of integers, design an algorithm and implement a program to sort this
array using selection sort. Your program should also find number of comparisons and number of
swaps required.
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
Third line will give total number of swaps required.
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>v1;
    int n,t,min,temp,j=0,s=0,c=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int key;
            cin>>key;
            v1.push_back(key);
        }
        for(int i=0;i<n;i++)
        {
            min = i;
            for(j = i+1;j<n;j++)
            {
                c++;
                if(v1[j]<v1[min])
                   min = j;
            }
            s++;
            temp = v1[i];
            v1[i] = v1[min];
            v1[min] = temp;
        }
        for(int i=0;i<n;i++)
        {
            cout<<v1[i]<<" ";
        }
        cout<<endl;
        cout<<"comparision="<<c<<"\n"<<"swaps="<<s-1<<endl;
    }
}