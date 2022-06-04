// WEEK - 2 OUESTION NO. 01


/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm 
and implement it using a program to find whether the given key element is present in the array or 
not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))
Input format: The first line contains number of test cases, T. For each test case, there will be three 
input lines. First line contains n (the size of array). Second line contains space-separated integers 
describing array. Third line contains the key element that need to be searched in the array.
Output format: The output will have T number of lines. For each test case T, output will be the key 
element and its number of copies in the array if the key element is present in the array otherwise 
print “ Key not present”.*/

#include<iostream>
#define max 100
using namespace std;


void binary_search(int arr[], int l, int h,int key,int c)
{
    int m;
    if(l>h){
        if(c==0)
        cout<<"Key not present\n";
        return;
    }
    m = (h+l)/2;
    if(key==arr[m])
    {
        for(int i=m;i>=l;i--){
        if(arr[i]==key)
        c++;
        }
        for(int i=m+1;i<=h;i++){
        if(arr[i]==key)
        c++;
        } 
         cout<<key<<"-"<<c;
        return;
    }
    else if(key<arr[m])
    binary_search(arr,l,m-1,key,c);
    else
    binary_search(arr,m+1,h,key,c);
    
}

int main()
{
    int arr[max],n,key,c=0,t;
    cin>>t;
    while(t){
    t--;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cin>>key;
    binary_search(arr,0,n-1,key,c);
    }
}
