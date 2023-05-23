#include <bits/stdc++.h>
using namespace std;

class graph{
	

}
const int N=100;
vector<int> graph[N];
bool vis[N];

void dfs(int vertex){
	vis[vertex]=true;
	for(auto child:graph[vertex]){
		if(vis[child])continue;
		dfs(child);
             
	}
}

void bfs(int source){
    queue<int> q;
	q.push(source);
	vis[source]=true;

}
int main(){
	cout<<"Enter number of nodes"<<endl;
  cout<<"Enter number of edges"<<endl;
  int n,e;
	cin>>n>>e;
	cout<<"enter edges"<<endl;
   for(int i=0;i<e;i++){
	int u,v;cin>>u>>v;
	graph[u].push_back(v);
	graph[v].push_back(u);
	}
	int ct=0;
	for(int i=1;i<=n;i++){
     if(vis[i])continue;
      dfs(i);
	  ct++;

	}
  cout<<"No of connected components is"<<ct<<endl;

}
