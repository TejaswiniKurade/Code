#include <bits/stdc++.h>
using namespace std;

 int main()
 {
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n, 0));
    if(n==1)
    {
        v[0][0]=1;
        cout<<v[0][0]<<endl;
    }
    else if(n==2)
    {
        v[0][0]=1;
        v[1][0]=1;
        v[1][1]=1;
        cout<<v[0][0]<<endl;
        cout<<v[1][0]<<endl;
        cout<<v[1][1]<<endl;
    }
    else
    {
        v[0][0]=1;
        v[1][0]=1;
        v[1][1]=1;
        int cnt=3;
        while(cnt<=n)
        {
            if(cnt%2!=0)
            {
                for(int i=0;i<cnt-2;i++)
                {
                   v[cnt-1][i+1]=v[cnt-2][i]+v[cnt-2][i+1];
                }
                v[cnt-1][0]=1; v[cnt-1][cnt-1]=1;
                cnt++;
            }
            else
            {
                for(int i=0;i<cnt-2;i++)
                {
                   v[cnt-1][i+1]=v[cnt-2][i]+v[cnt-2][i+1];
                }
                v[cnt-1][0]=1; v[cnt-1][cnt-1]=1;
                cnt++;
            }
        }
        for (auto& s : v) 
        {
            for (auto& elem : s)
             {
                 if(elem!=0)
                 {
                    cout << elem << ' ';
                 }
             }
             cout<<endl;
        
       }     

 }}