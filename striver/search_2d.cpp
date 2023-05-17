#include <bits/stdc++.h>
using namespace std;

 int main()
 {
    
    vector<vector<int>> mat;
    vector<int> r1={1};
    vector<int> r2={3};
    
    mat.push_back(r1);
    mat.push_back(r2);
    
    int t=3;
    int n=mat[0].size();
    int m=mat.size();
    int i=0,k,flag=0;
    while(i!=m)
    {
       if(mat[i][0]<=t)
       {
         k=i;
         i++;
       }
       else
           break;
    }
    for(int j=0;j<n;j++)
    {
        if(mat[k][j]==t)
        {
            flag=1;
        }
    }
    puts(flag?"Yes":"NO");

 }