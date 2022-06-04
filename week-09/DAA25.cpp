// WEEK 09 Question no 01

/*I. Given a graph, Design an algorithm and implement it using a program to implement Floyd-Warshall all pair shortest path algorithm.
Input Format: 
The first line of input takes number of vertices in the graph. 
Input will be the graph in the form of adjacency matrix or adjacency list. If a direct edge is not
present between any pair of vertex (u,v), then this entry is shown as AdjM[u,v] = INF.
Output Format: 
Output will be shortest distance matrix in the form of V X V matrix, where each entry (u,v)
represents shortest distance between vertex u and vertex v.

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, i, j, k, w;
    cin >> n;
    int graph[n][n];
    string temp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> temp;
            if (temp != "INF") {
                graph[i][j] = stoi(temp);
            } else {
                graph[i][j] = 1e8;
            }
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    cout << "The shortest path matrix: " << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if(graph[i][j] >= 1e8) cout << "INF";
            else cout << graph[i][j];
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
