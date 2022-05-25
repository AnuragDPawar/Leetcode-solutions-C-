#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int lengthOfLIS(vector<int>& nums) {
        //to store the number of smallest elements for the ith element
        vector<int> dp (nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
            //to check from 0 to ith index and update the dp[i]
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && dp[i]<=dp[i])
                    dp[i] = 1 + dp[j]; 
            }
        }
        int res = dp[0];
        //largest number holds the answer
        for(auto x: dp) res = max(res, x);
        return res;
    }
};

int main()
{
    vector<int> nums {10,9,2,5,3,7,101,18};
    Solution sa;
    cout<<sa.lengthOfLIS(nums);
    return 0;
}

/*
Time complexity: O(n^2)
Space complexity: O(n)
*/