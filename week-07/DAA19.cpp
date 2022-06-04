// WEEEK 07 Question no 01
/*
I. After end term examination, Akshay wants to party with his friends. All his friends are living as
paying guest and it has been decided to first gather at Akshay’s house and then move towards
party location. The problem is that no one knows the exact address of his house in the city.
Akshay as a computer science wizard knows how to apply his theory subjects in his real life and
came up with an amazing idea to help his friends. He draws a graph by looking in to location of
his house and his friends’ location (as a node in the graph) on a map. He wishes to find out
shortest distance and path covering that distance from each of his friend’s location to his house
and then whatsapp them this path so that they can reach his house in minimum time. Akshay has
developed the program that implements Dijkstra’s algorithm but not sure about correctness of
results. Can you also implement the same algorithm and verify the correctness of Akshay’s
results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)
Output Format: 
Output will contain V lines.
Each line will represent the whole path from destination vertex number to source vertex number
along with minimum path weigth.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int N,m;
	cin >> N >> m;
	vector<pair<int,int> > adj[N]; 

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));
		adj[b].push_back(make_pair(a,wt));
	}	
	
	int parent[N]; 
      
    int key[N]; 
      
    bool mstSet[N]; 
  
    for (int i = 0; i < N; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0; 
    parent[0] = -1; 
    pq.push({0, 0});
    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop(); 
        
        mstSet[u] = true; 
        
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v])
            { 
                parent[v] = u;
		        key[v] = weight; 
                pq.push({key[v], v});    
            }
        }
            
    } 
    int ans=0;
    for (int i=0;i<N;i++)
      {
        if (key[i]!=INT_MAX)
            ans+=key[i];            
      }
	
    cout<<ans<<endl;
}
