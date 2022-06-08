// WEEK 10 Question no 03
/*III. Given an unsorted array of elements, design an algorithm and implement it using a program to
find whether majority element exists or not. Also find median of the array. A majority element is
an element that appears more than n/2 times, where n is the size of array.
Input Format: 
First line of input will give size n of array. 
Second line of input will take n space-separated elements of array.
Output Format: 
First line of output will be 'yes' if majority element exists, otherwise print 'no'. 
Second line of output will print median of the array.

*/
#include<iostream> 
#include<vector> 
#include<map> 
#include<algorithm> 
using namespace std; 
bool majority(vector<int> arr){ 
    map<int,int> m; 
    for(int i=0;i<arr.size();i++) 
    m[arr[i]]++; 
    for(auto& i:m){ 
        if(i.second>=(arr.size()/2)) 
        return true; 
    } 
    return false;
} 
int median(vector<int> arr){ 
    if(arr.size()%2==0) 
        return(arr[(arr.size()/2)]+arr[(arr.size()/2)-1])/2; 
    else 
        return arr[(arr.size()/2)]; 
     
  
} 
int main(){ 
    int n; 
    cin>>n; 
    vector<int>arr; 
    for(int i=0;i<n;i++){ 
        int temp; 
        cin>>temp; 
        arr.push_back(temp); 
    } 
    if(majority(arr)) 
        cout<<"\nYES\n"; 
    else 
        cout<<"\nNO\n"; 
    cout<<median(arr); 
}