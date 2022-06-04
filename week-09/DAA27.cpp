// WEEK 09 Question no 03
/*III. Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and 
a program to merge all these files into single file with minimum computation. For given two files A and B 
with sizes m and n, computation cost of merging them is O(m+n). (Hint: use greedy approach)
Input Format:
First line will take the size n of the array. Second line will take array s an input.
Output Format:
Output will be the minimum computation cost required to merge all the elements of the array.

Sample I/O Problem III:
Input:
Output: 960
10 105 100 50 20 155 20 100 10
first of all merge first two files (having 10 and 5 file size). Cost of Imerging will be 10+5=15.

Solved example: Consider arr[5] = { 10, 5, 100, 50, 20, 15). As per the brute force approach, Similarly, 
again merging first two files (i.e. having 15 and 100 file size). Cost of merging will be = 15+100-115. 
List will become (115, 50, 20, 15).
List will become (15, 100, 50, 20, 15)
For the subsequent steps the list becomes, (165, 20, 15), (185, 15) and (200).
Therefore total cost of merging = 15+115+165+185+200 680.
But this is not minimum computation cost. To find minimum cost, 
consider the order arr[5] = (5, 10, 15, 20, 50, 100) By applying the same approach, 
the total cost of merging = 15+30+50+100+200=395.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int>> minheap;
    for (int i = 0; i < n; i++) {
        minheap.push(a[i]);
    }
    int ans = 0;
    while (minheap.size() >1) {
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();
        ans += e1 + e2;
        minheap.push(e1 + e2);
    }
    cout << ans;
    return 0;
}