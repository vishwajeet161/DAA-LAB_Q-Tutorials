// WEEK - 1 QUESTION NO. 02

/* Given an already sorted array of positive integers, desine an algo and implement it using program to find weather
 given key element is present in the array or not and also find the no. of comparasion for each */ 

 #include<iostream>
 using namespace std;
 #define max 100


 void binarySearch(int arr[], int l, int h, int key)
 {
     int m,f=0;
     while(l<=h)
     {    
        m = (h+l)/2;
        if(arr[m]==key)
         {
            f =1;
            break;
         }
         else if(arr[m]<key)
          l = m+1;
        else 
          h = m-1;
     }
     if(f==0)
     cout<<"not present "<<key;
     else
     cout<<"present "<<key;
 }


 int main()
 {
    int t,arr[max],n,low=0,high;
    cin>>t;
    while(t--)
    {
        int key;
        cin>>n;
        high = n-1;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cin>>key;
        binarySearch(arr,low,high,key);
    }
     
 }