#include <bits/stdc++.h>
using namespace std;

class graph
{
  vector<int> v[20];
  public:
     void insert(int m,int n);
     void insertnode(int m);
     void bfs();
     void display();
     void dfs(int k);
     void remove_edge(int m,int n);
     bool connected();
};

void graph::insert(int m,int n)
{
   v[m].push_back(n);
   v[n].push_back(m);
}

void graph::display()
{
   vector<int> ele;
   int j=0;
   for(auto &ele:v)
   {
    if(ele.size()!=0)
       {
          j++;
         cout<<j<<" -> ";
         for(auto &i:ele)
         { 
           cout<<i<<"  ";
         }
          cout<<endl;
       }
   }
}

void graph::bfs()
{
   queue<int> q;
   int k;
   int ar[20]={0};
   for(int i=1;i<=20;i++)
   {
     if(v[i].size()!=0)
     {
        k=i;
        ar[i]=i;
        break;
     }
   }
   q.push(k);
   vector<int> bfs;
   while(!q.empty())
   {
      bfs.push_back(q.front());
      for(int i=0;i<v[q.front()].size();i++)
      {
        if(ar[v[q.front()][i]]==0  && v[q.front()].size()!=0)
        {
            q.push(v[q.front()][i]);
            ar[v[q.front()][i]]=v[q.front()][i];
        }
      }
      q.pop();
   }
   for(auto &i:bfs)
   {
     cout<<i<<"  ";
   }
}


void graph::dfs(int k)
{
       stack<int> st;
       int ar[20]={0};
       ar[k]=1;
        st.push(k);
        vector<int> dfs;
        int a;
        while(!st.empty())
        {
            dfs.push_back(st.top());
            a=st.top();
            st.pop();
            for(int i=0;i<v[a].size();i++)
              {
                  if(ar[v[a][i]]==0)
                  {
                     st.push(v[a][i]);
                     ar[v[a][i]]=v[a][i];
                  }
              }
        }
        for(auto &i:dfs)
           {
             cout<<i<<"  ";
           }
}

bool graph::connected()
{
   vector<int> vec;
   for(int i=0;i<20;i++)
   {
        if(!v[i].size())
        {
          vec.push_back(i);
        }
   }
   for(int i=0;i<vec.size();i++)
   {
      
   }



}

void graph::remove_edge(int m,int n)
{
    int k;
    for(int i=0;i<20;i++)
    {
       if(v[m][i]==n)
       {
         k=i;
         break;
       }
    }
    v[m].erase(v[m].begin()+k);
    for(int i=0;i<20;i++)
    {
       if(v[n][i]==m)
       {
         k=i;
         break;
       }
    }
    v[n].erase(v[n].begin()+k);
}

int main()
{
  graph g;
  g.insert(1,2);
  g.insert(1,4);
  g.insert(1,3);
  g.insert(2,4);
  g.insert(4,3);
  //g.display();
//   g.bfs();
  g.dfs(1);
 //g.remove_edge(1,4);
// cout<<endl;
      //g.display();

 

}