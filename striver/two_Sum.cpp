// c++ program to find largest subarray length with sum 0
#include <bits/stdc++.h>
using namespace std;
// function for finding the length of
// largest subarray of an array that has sum 0
int maxLenSubSumZero(int ar[], int size)
{
    // Creating the map for storing previous sums
    unordered_map<int, int> prevsummap;
    // Declaring and Initializing the cur_sum to store sum
    int cur_sum = 0;
    // declaring the variable max_length for storing
    // maximum length of subarray with sum 0
    int max_length = 0;
    // Iterate over the input array
    for (int i = 0; i < size; i++) {
        // Adding current element to the previous calculated sum
        cur_sum += ar[i];

        if (ar[i] == 0 && max_length == 0)
            max_length = 1;
        if (cur_sum == 0)
            max_length = i + 1;

        // Checking this sum in the map
        if (prevsummap.find(cur_sum) != prevsummap.end()) {
            // If sum is in map then update the value of max_length
            max_length = max(max_length, i - prevsummap[cur_sum]);
        }
        else {
            // If sum is not in the map then
            // insert it into map with current index
            prevsummap[cur_sum] = i;
        }
    }

    return max_length;
}
//driver code
int main(){
    //declaring an array
    int ar[]={1,3,-1,4,-4};
    //finding size of an array
    int size=sizeof(ar)/sizeof(ar[0]);
    // calling function
    int res=maxLenSubSumZero(ar,size);
    //printing result
    cout<<res;
}
