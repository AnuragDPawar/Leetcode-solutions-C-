#include<bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    public:
    void help(vector<int>& nums, int t, int start,vector<int> temp)
    {
        //base conditions
        if(t==0) //we have covered the desired sum
        {
            res.push_back(temp);
            return;
        }
        if(t<0) return; //we have crossed the desired sum

        //recursion
        for(int i=start;i<nums.size();i++)
        {
            if(i>start && nums[i]==nums[i-1]) continue; //to avoid duplication of the elements
            temp.push_back(nums[i]); //adding current element to the temp vector
            help(nums,t-nums[i],i+1,temp); //calling recusion for all the possible combinations
            temp.pop_back(); //if sum not found then we'll remove the last element
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int t) 
    {
        vector<int> temp;
        sort(nums.begin(),nums.end()); //this will keep all the element in increasing order
        help(nums,t,0,temp);
        return res;
    }

};

int main()
{
    Solution sa;
    vector<int> nums {2,5,2,1,2};
    vector<vector<int>> ans = sa.combinationSum(nums,5);
    for(auto x: ans)
    {
        for(auto y:x) cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}

//time complexity: O(k * 2^target). where k is the average length of recursion depth