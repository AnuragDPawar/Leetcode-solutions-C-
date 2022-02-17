#include <bits/stdc++.h>
using namespace std;
vector<int> remove_element(vector<int> nums, int val)
{
    int n=nums.size(), cnt=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==val) cnt++;
        else nums[i-cnt]=nums[i];
    }   
    return nums;
}
int main()
{
    vector<int> nums {0,1,2,2,3,0,4,2};
    vector<int> res = remove_element(nums,2);
    for(auto x: res) cout<<x<<" ";
    return 0;
}

/*
Algorithm
1. Search for the key, if found increase the count.
2. If not found then replace the i-cnt th variable with ith variable.
3. This will replace the current element (which is not the key) with the position on which key was found. 
*/