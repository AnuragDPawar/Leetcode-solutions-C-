#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> nums,int target)
{
    vector<int> res;
    unordered_map<int,int> m;
    for(int i=0;i<nums.size();i++)
    {   
        int diff=target-nums[i];
        if(m.find(diff)!=m.end() && m.find(diff)->second!=i) //checking if difference is present in map and its index is != i
        {
            res.push_back(i);
            res.push_back(m.find(diff)->second);
        }
        m[nums[i]]=i; //add nums[i] as key and i as value in the map
    }
    return res;
}
int main()
{
    vector<int> nums {2,7,11,15};
    vector<int> res = twoSum(nums,9);
    for(auto x:res) cout<<x<<endl;
    return 0;
}
/*
Algorithm
1. Use a map to store the difference of target and nums[i] i.e. key=nums[i] and value=i.
2. In every iteration we'll check if the difference is present in map and its index is not same as value of that field.
3. If found store the result into a vector.
*/