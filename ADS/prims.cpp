#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


class graph
{
  vector<pair<int,int>> v[10];
  public:
     void insert(int m,int dest,int w);
     void prims();
     void display();

};

void graph::insert(int m,int dest,int w)
{
   v[m].push_back(make_pair(dest,w));
   v[dest].push_back(make_pair(m,w));
 
}


void graph::display()
{
    for (int i = 0; i < 10; i++)
    {
        if (v[i].size())
        {
            cout << "Node " << i << " is connected to:" << endl;
            for (int j = 0; j < v[i].size(); j++)
            {
                cout << "  " << v[i][j].first << "   " << v[i][j].second << endl;
            }
        }
    }
}


int minimum_v(int *distance,bool *visited,int n)
{
  int minimum = MAX;
  int k;
   for(int i=1;i<n;++i)
   {
      if(distance[i]<minimum && visited[i]==false )
      {
           minimum=distance[i];
           k=i;
      }
   }
   return k;
}

 void graph:: prims()
 {
    int n=10;
    cout<<n<<endl;
    bool visited[n]={false};
    int distance[n]={MAX};
    distance[0]=0;
    int parent[n];
    parent[0]=-1;
    for(int i=1;i<n;i++)
    {
       int h=minimum_v(distance,visited,n);
       visited[h]=true;
       if(v[i].size())
       {for(int j=0;j<v[i].size();j++)
       {
          if(visited[v[i][j].first]==false && v[i][j].second<distance[v[i][j].first])  
          {
              distance[v[i][j].first]=v[i][j].second;
              parent[v[i][j].first]=h;
          }
       }}
    }
    for (int i = 1; i < n; i++) // output the minimum spanning tree
    {
        cout << "Node " << i << " is connected to node " << parent[i] << endl;
    }

 }


int main()
{
  graph g;
g.insert(5, 4, 5);   
g.insert(5, 1, 3);   
g.insert(1, 2, 3);   
g.insert(1, 4, 7);   
g.insert(2, 5, 11);  
g.insert(6, 4, 1);   
g.insert(5, 6, 7);   
g.insert(3, 1, 3);   
g.insert(3, 2, 7); 
  //g.display(); 
  g.prims();
}