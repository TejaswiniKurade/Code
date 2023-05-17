#include <bits/stdc++.h>
using namespace std;

 int main()
 {
    
    vector<vector<int>> mat;
    vector<int> r1={0,1,2,0};
    vector<int> r2={3,4,5,2};
    vector<int> r3={1,3,1,5};
    mat.push_back(r1);
    mat.push_back(r2);
    mat.push_back(r3);

    int r = mat.size(), c = mat[0].size();
   //r=3  c=4
    set<int> sr;
    set<int> sc;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(mat[i][j]==0)
            {
                 sr.insert(i);
                 sc.insert(j);
            }
        }
    }
    for (auto iter = sr.begin(); iter != sr.end(); iter++)
    {
        for(int j=0;j<c;j++)
        {
            mat[*iter][j]=0;
        }
    }
    for (auto iter = sc.begin(); iter != sc.end(); iter++)
    {
        for(int j=0;j<r;j++)
        {
            mat[j][*iter]=0;
        }
    }

    vector<int> rowy;
    for(auto &rowy:mat)
    {
        for(auto &ele:rowy)
        {
            cout<<ele<<"  ";
        }
        cout<<endl;

    }
  
   


 }