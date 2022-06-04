// WEEK 09 Question no 02
/*II. Given a knapsack of maximum capacity w. N items are provided, each having its own value and weight.
You have to Design an algorithm and implement it using a program to find the list of the selected items 
such that the final selected content has weight w and has maximum value. You can take fractions of items,
i.e. the items can be broken into smaller pieces so that you have to carry only a fraction x of item i, 
where 0 ≤x≤ 1.
Input Format:
First input line will take number of items N which are provided. Second input line will contain N 
space-separated array containing weights of all N items. Third input line will contain N space-separated 
array containing values of all N items. Last line of the input will take the maximum capacity w of knapsack.
Output Format:
First output line will give maximum value that can be achieved. Next Line of output will give list of 
items selected along with their fraction of amount which has been taken.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> items(n);
    vector<double> val(n);
    vector<vector<double>> job;
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        job.push_back({val[i] / items[i], items[i], (double)(i + 1)});
    }
    double k;
    cin >> k;
    sort(job.rbegin(), job.rend());
    vector<pair<double, double>> ls;
    float profit = 0;
    for (int i = 0; i < n; i++) {
        if (job[i][1] >= k) {
            profit += k * job[i][0];
            ls.push_back(make_pair(k, job[i][2]));
            break;
        } else {
            profit += job[i][1] * job[i][0];
        }
        ls.push_back(make_pair(job[i][1], job[i][2]));
        k = k - job[i][1];
    }
    cout << "Maximum Value : " << profit << endl;
    cout << "Item - Weight" << endl;
    for (auto it : ls)
        cout << it.second << " - " << it.first << endl;
    return 0;
}