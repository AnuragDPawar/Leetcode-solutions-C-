#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxSubArray(vector<int>& nums) {
            int sum = nums[0], curSum = 0;
            for(auto x: nums)
            {
                if(curSum<0) curSum = 0;
                curSum+=x;
                sum = max(sum, curSum);
            }
            return sum;
        }
};

int main()
{
    vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
    Solution sa;
    cout<<sa.maxSubArray(nums);
    return 0;
}