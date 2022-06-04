// WEEK 5 QUESTION NO. 01

/*I. Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n)) (Hint: Use counting sort)
Input Format: 
The first line contains number of test cases, T.
For each test case, there will be two input lines.
First line contains n (the size of array).
Second line contains space-separated integers describing array.
Output:
The output will have T number of lines. 
For each test case, output will be the array element which has maximum occurrences and its total
number of occurrences. 
If no duplicates are present (i.e. all the elements occur only once), output should be “No
Duplicates Present”.
*/

#include <iostream>
#include<limits.h>
using namespace std;

void count_sort(char arr[],int n)
{
    int temp[26]={0};
    for (int i=0;i<n;i++)
       temp[arr[i]-97]++;
       
    int maxi=0;
    char res='$';
    for (int i=0;i<26;i++)
    {
        if (temp[i]>maxi)
        {
            maxi=temp[i];
            res=i+97;
        }
    }
    if (maxi==1)
      cout<<"No Duplicate Found"<<endl;
     else
    cout<<res<<" - "<<maxi<<endl;
     
}

int main()
{
    
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        char arr[n];
        for (int i=0;i<n;i++)
            cin>>arr[i];
        count_sort(arr,n);
    }
    return 0;
}
