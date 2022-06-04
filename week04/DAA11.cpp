// WEEK 4 QUESTION NO. 02

/*II. Given an unsorted array of integers, design an algorithm and implement it using a program to
sort an array of elements by partitioning the array into two subarrays based on a pivot element
such that one of the sub array holds values smaller than the pivot element while another sub
array holds values greater than the pivot element. Pivot element should be selected randomly
from the array. Your program should also find number of comparisons and swaps required for
sorting the array.
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

#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int comp=0,swaps=0;
void quick_sort(int arr[],int lb,int ub)
{
    if (lb>=ub)
       return ;
    else{
        int pivot=arr[lb];
        int i=lb,j=ub;
      
        while (i<j)
        {
            comp++;
            while (pivot>=arr[i] && i<j)
                  i++;
            while (pivot<arr[j])
                  j--;
            if (i<j)
             swap(&arr[i],&arr[j]);
        }
        swaps++;
        swap(&arr[lb],&arr[j]);
        quick_sort(arr,lb,j-1);
        quick_sort(arr,j+1,ub);
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
        
        quick_sort(arr,0,n-1);

        for (int i=0;i<n;i++)
           cout<<arr[i]<<" ";

        cout<<endl<<"Swaps:"<<swaps<<endl;
        cout<<"Comparisions:"<<comp<<endl;
        swaps=0;
        comp=0;
    }
    return 0;
}