#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int n;cin>>n;
  int array[n][n];
 cout<<"Enter the adjacency matrix "<<endl;
  for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
            cin>>array[i][j];
    }
  }
  vector<int>indegree;                                                                                                 
  queue<int>que;
  for(int i=0;i<n;i++){
     int cnt=0;
     for(int j=0;j<n;j++){
           if(array[j][i]==1){
           cnt++;}
    }
    indegree.push_back(cnt);
  }
  
  //for(int i=0;i<indegree.size();i++){
    //cout<<indegree[i]<<endl;}
  
  for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){que.push(i);}
  }
  
  vector<int>vec;
  while(!que.empty()){
  	int x=que.front();
  	//cout<<x<<endl;
   
            for(int j=0;j<n;j++){
                if(array[x][j]==1){
                    indegree[j]=indegree[j]-1;
                        if(indegree[j]==0){que.push(j);}
                }
          }
          cout<<x+1<<" ";
             que.pop();
  }
}
