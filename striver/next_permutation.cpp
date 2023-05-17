#include <bits/stdc++.h>
using namespace std;

 int main()
 {
    
   vector<int> v={1,2,3};
   int n=v.size();
   int i=n-1;
   bool flag=0;
   for(int i=n-1;i>=0;i--)
   {for(int j=i-1;j>=0;j--)
    {
      if(v[i]>v[j])
      {
        swap(v[i],v[j]);
        flag=1;
        break;
      }
    }
    if(flag==1)
    {
        break;
    }
   }
   for(auto &i:v)
   {
     cout<<i<<" ";
   }

}