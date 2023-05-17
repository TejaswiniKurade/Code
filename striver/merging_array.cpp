#include <bits/stdc++.h>
using namespace std;

 int main()
 {
    
    vector<vector<int>> mat;
    vector<int> r1={1,4};
    vector<int> r2={4,5};
    mat.push_back(r1);
    mat.push_back(r2);
   
    int n=mat.size();
    vector<vector<int>> m;
    int i=0,k,cnt=0;
    bool flag=0;
    while(i!=n)
    {
       if(mat[i][1]>=mat[i+1][0])
       {while(mat[i][1]>=mat[i+1][0])
       {
             cout<<"while ="<<mat[i][1]<<endl;
             cnt++;
             flag=1;
             if(cnt==1)
             {
              cout<<"enter"<<endl;
              k=i;
             }
             i++;
               
       }
       }
      cout<<"i = "<<i<<endl;
      if(flag==1)
       {
         vector<int> v;
         v.push_back(mat[k][0]);
         v.push_back(mat[i][1]);
         i++;
         m.push_back(v);
         vector<int> ss;
          flag=0;
       }
       else
       {
         cout<<"enter1"<<endl;
         flag=0;
         cnt=0;
         vector<int> v;
          v.push_back(mat[i][0]);
          v.push_back(mat[i][1]);
          m.push_back(v);
          i++;
       }
       if(i==n-1)
       {
         vector<int> v;
         v.push_back(mat[i][0]);
          v.push_back(mat[i][1]);
          m.push_back(v);
          i++;
       }
    }
    for(auto &ss:m)
    {
        for(auto&t:ss)
        {
            cout<<t<<"  ";
        }
    }

 }