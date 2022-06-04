// WEEK - 01 QUESTION NO. 03
/* Given an already sorted array of positive integers, design an algorithm and implement it using a
program to find whether a given key element is present in the sorted array or not. For an array 
arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] 
and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, 
perform a linear search operation from the index 2k to find the element 
key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): 
Jump Search
Input format:
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains n space-separated integers describing array.
Third line contains the key element that need to be searched in the array.
Output format:
The output will have T number of lines. 
For each test case, output will be “Present” if the key element is found in the array, otherwise 
“Not Present”. 
Also, for each test case output the number of comparisons required to search the key. */

 

#include<iostream>
#include<math.h>
using namespace std;
void jumpsearch (int [], int ,int);
int main ()
{
    int test_case;
    cin>>test_case;
    while (test_case--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        jumpsearch(arr, key, n);
    }
}
void jumpsearch (int arr[], int key, int n)
{
    int pos=sqrt(n), comparisons=1, i=0, flag=0;
    while (arr[pos]<=key && pos<n)
    {
        comparisons++;
        i=pos;
        pos=pos+(sqrt(n));
        if (pos>n-1)
            pos=n;
    }
    for (int j=i;j<=pos;j++)
    {
        if (arr[j]==key)
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
        cout<<"Present "<<comparisons<<endl;
    else
        cout<<"Not Present "<<comparisons<<endl;
}

