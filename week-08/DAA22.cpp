// WEEK 8 Question no 01
/*
I. Assume that a project of road construction to connect some cities is given to your friend. Map of
these cities and roads which will connect them (after construction) is provided to him in the form
of a graph. Certain amount of rupees is associated with construction of each road. Your friend
has to calculate the minimum budget required for this project. The budget should be designed in
such a way that the cost of connecting the cities should be minimum and number of roads
required to connect all the cities should be minimum (if there are N cities then only N-1 roads
need to be constructed). He asks you for help. Now, you have to help your friend by designing an
algorithm which will find minimum cost required to connect these cities. (use Prim's algorithm)
Input Format: 
The first line of input takes number of vertices in the graph. 
Input will be the graph in the form of adjacency matrix or adjacency list. 
Output Format:
Output will be minimum spanning weight
*/

#include <bits/stdc++.h>
using namespace std;

void Dijkastras(vector<pair<int,int>> adj[],int n,int src)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n+1,INT_MAX);
    vector<int> parent(n+1,0);
    dist[src]=0;
    parent[src]=src;
    
    pq.push({0,src});
    
    while (!pq.empty())
    {
        int node=pq.top().second;
        pq.pop();
        
        for (auto it:adj[node])
        {
            if (dist[node]+it.second<dist[it.first])
            {
                parent[it.first]=node;
                dist[it.first]=dist[node]+it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    
    cout<<"shortest paths"<<endl;
    for (int i=1;i<n+1;i++)
    {
        cout<<i<<",";
        int j=i;
        while (parent[j]!=1)
        {
            j=parent[j];
            cout<<j<<",";
        }
        if (i!=1) cout<<1<<",";
        cout<<":"<<dist[i]<<endl;
    }
}

int main()
{
    int n,m;
    cout<<"enter the number of nodes and edges:";
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    cout<<"enter the source node,target node and weight:"<<endl;
    for (int i=0;i<m;i++)
    {
        int a,b,wt;   
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    
    Dijkastras(adj,n,1);
    return 0;
}
