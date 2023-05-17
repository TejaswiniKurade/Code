#include <bits/stdc++.h>
using namespace std;

void indegree(vector<vector<int>> v)
{
    int n=v[0].size();
    int ar[n]={0};
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
       {
          if(v[j][i]==1)
          { ar[i]++; }
       } 
    }
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
       if(ar[i]==0)
       {q.push(i);}
    }
    while(!q.empty())
    {
        int k=q.front();
        for(int j=0;j<n;j++)
        {
           if(v[k][j]==1)
           {
             ar[j]--;
             if(ar[j]==0)
             {  q.push(j);  }
           }
        }
    ans.push_back(k+1);
    q.pop();
}
    cout<<"The given topological order"<<endl;
    for(auto &i:ans)
    {  cout<<i<<" "; }
    cout<<endl;
}
int main()
{
    cout<<"Enter number of nodes = ";
    int n; cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++)
    {
       vector<int> vin;
       for(int j=0;j<n;j++)
       {
          int x; cin>>x;
          vin.push_back(x);
       }
       v.push_back(vin);
    }
    indegree( v);

}