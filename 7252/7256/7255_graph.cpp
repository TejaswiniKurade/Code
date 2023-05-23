#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex,vector<int> &graph,vector<bool> &vis){
	if(vis[vertex]) return;

	vis[vertex] = true;
	cout<<vertex<<' ';
	for(auto child:graph[vertex]){
		dfs(child,graph,vis);
	}
	 
}

void bfs(int vertex,vector<int> &graph,vector<bool> &vis){
	
	queue<int> q;
	q.push(vertex);
	while(!q.empty()){
		int curr = q.front();
		vis[curr] = true;
		for(auto child:graph[curr]){
			if(!vis[child])q.push(child);
		}
	}
	
}

int main(){
	int n,e;
	cout<<"Enter Number of Nodes of Tree: ";
	cout<<"Enter Number of Edges: ";
	cin>>n>>e;
	vector<int> graph[n];
	vector<bool> vis(n);

	int cp_ct = 0;

	for(int i=0;i<e;i++){
		int v1,v2;cin>>v1>>v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,graph,vis);
			cout<<endl;
			cp_ct++;
		}
	}

	for(int i=0;i<n;i++){
		vis[i] = false;
 	}

	for(int i=0;i<n;i++){
		if(!vis[i]){
			bfs(i,graph,vis);
			cout<<endl;
		}
	}

	cout<<"Connected Componenets: "<<cp_ct<<endl;

	

	

}
