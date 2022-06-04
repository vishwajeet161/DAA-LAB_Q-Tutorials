// WEEK 4 QUESTION NO. 03

/*III. Given an unsorted array of integers, design an algorithm and implement it using a program to
find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))
Input Format: 
The first line contains number of test cases, T.
For each test case, there will be three input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Third line contains K.
Output Format:
The output will have T number of lines. 
For each test case, output will be the Kth smallest or largest array element.
If no Kth element is present, output should be “not present”.
*/

#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int h)
{
    int count=0;
    int i=l,j=mid+1;
    int temp[h-l+1];
    int k=0;
    
    while (i<=mid && j<=h)
    {
        if (arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            count+=mid-i+1;
        }
    }
    for (;i<=mid;)
         temp[k++]=arr[i++];
         
    for (;j<=h;)
         temp[k++]=arr[j++];
         
    for (int f=0;f<k;f++)
        arr[f+l]=temp[f];
}
void merge_sort(int arr[],int l,int h)
{
    if (l<h)
    {
        int mid=l+(h-l)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}


int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0;i<n;i++)
           cin>>arr[i];
        int k;
        cin>>k;

        merge_sort(arr,0,n-1);
        int flag=0;
        cout<<arr[k-1]<<endl;
         
    }

}