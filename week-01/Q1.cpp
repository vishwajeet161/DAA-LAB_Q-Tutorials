// WEEK - 1 QUESTION NO. 01

/* Given an array of non negative element design a linear algorithm and implement it using a programm to find whether the given element is 
present in the array or not also find total no. of comparisiom for each input case. */

#include<iostream>
using namespace std;
#define max 100

int main()
{
    int t,c=0;int arr[max],n;
    cin>>t;
   
    while(c<t)
    {
        c++;
        
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int key;
        cin>>key;
        int k=0,l=0;
        for(int j=0;j<n;j++)
        {
            l++;
            if(arr[j]==key)
            {  
                k = j+1;
                break;
            }
        }
        if(k==0)
        cout<<"Not Present "<<l<<endl;
        else
        cout<<"Present "<<k<<endl;
    }
}
