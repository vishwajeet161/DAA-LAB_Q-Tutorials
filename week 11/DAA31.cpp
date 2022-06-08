//WEEK 11 Question no 01

/* I. Given a sequence of matrices, write an algorithm to find most efficient way to multiply these
matrices together. To find the optimal solution, you need to find the order in which these
matrices should be multiplied. 
Input Format: 
First line of input will take number of matrices n that you need to multiply. 
For each line i in n, take two inputs which will represent dimensions aXb of matrix i.
Output Format: 
Output will be the minimum number of operations that are required to multiply the list of
matrices
Solved Example: Consider a sequence of three matrices A of size 10X30, B of size 30X5, C of
size 5X60. Then,
(AB)C = (10*30*5) + (10*5*60) = 4500 operations
A(BC) = (30*5*60) + (10*30*60) = 27000 operations. 
Hence the ouput of the program must be 4500
*/

#include<bits/stdc++.h>
using namespace std;
void helper(vector<int>v,vector<vector<int>>&final,vector<int>ds,int temp,int sum,int idx)
{
    
    if(temp>sum)return;
    
  if(temp==sum)
  {
      final.push_back(ds);
      return;
  }
  for(int i=idx;i<v.size();i++)
  {
      ds.push_back(v[i]);
      temp+=v[i];
      helper(v,final,ds,temp,sum,i);
      temp-=v[i];
      ds.pop_back();
  }
   
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        v.push_back(val);
    }
    int sum,x=0;
    cin>>sum;
    vector<vector<int>>final;
    vector<int>ds;
    helper(v,final,ds,x,sum,0);
    cout<<final.size();

    return 0;
}
