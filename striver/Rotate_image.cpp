
#include <bits/stdc++.h>
using namespace std;

 int main()
 {
    
    vector<vector<int>> mat;
    vector<int> r1={7,4,7};
    vector<int> r2={8,5,4};
    vector<int> r3={9,4,7};
    mat.push_back(r1);
    mat.push_back(r2);
    mat.push_back(r3);
    int n=mat.size();
    vector<vector<int>> mati(n,vector<int>(n,0));

    for(int i=0;i<n;i++)
    {
          int c=n;
          for(int j=0;j<n;j++)
          {
            mati[i][j]=mat[c-1][i];
              c--;
          }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //        mat[i][j]=mati[i][j];
    //     }
    // }
    vector<int> rowy;
    for(auto &rowy:mati)
    {
        for(auto &ele:rowy)
        {
            cout<<ele<<"  ";
        }
        cout<<endl;

    }
  
   


 }