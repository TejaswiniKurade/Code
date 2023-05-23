#include <bits/stdc++.h>
using namespace std;

#define V 5

int minimum_v(vector<int> &distance, vector<bool> &visited)
{
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < V; ++i)
    {
        if (visited[i] == false && distance[i] < minimum)
        {
            vertex = i;
            minimum = distance[i];
        }
    }
    return vertex;
}

void prims(int graph[V][V])
{
    int parent[V];
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);
    parent[0] = -1;
    distance[0] = 0;
    for (int i = 0; i < V - 1; ++i)
    {

        int U = minimum_v(distance, visited);
        visited[U] = true;
        for (int j = 0; j < V; ++j)
        {
            if (graph[U][j] && visited[j] == false && graph[U][j] < distance[j])
            {
                distance[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        cout << parent[i] << "->" << i << "  wt = " << graph[i][parent[i]] << "\n";
}

void initialize(int graph[][V]){
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++){
            graph[i][j]=0;
        }
    }
}

int main()
{
    
    int graph[V][V];
    initialize(graph);

    cout<<"Enter edges = ";
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
       int x,y,z;
       cin>>x>>y>>z;
       graph[x][y]=z;
       graph[y][x]=z;
    }

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    prims(graph);
    return 0;
}