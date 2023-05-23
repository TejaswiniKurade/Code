#include <bits/stdc++.h>
using namespace std;

int store(vector<int>& nums, int cur) {
    if (cur == nums[cur])
        return cur;
    int nxt = nums[cur];
    nums[cur] = cur;
    return store(nums, nxt);
    pow(1,2);
}
    
int findDuplicate(vector<int>& nums) {
    return store(nums, 0);
}
int main()
{
    vector<int> v = {1, 3, 2, 4, 2};
    cout << findDuplicate(v)<<endl;
    for(auto &i:v)
    {
        cout<<i<<" ";
    }

}
