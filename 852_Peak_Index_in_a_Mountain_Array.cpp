#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int res=0,curMax=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>curMax)
            {
                curMax=nums[i];
                res=i;
            }
        }
        return res;
    }
};

int main()
{
    Solution sa;
    vector<int> nums {0,2,1,0};
    cout<<sa.peakIndexInMountainArray(nums);
    return 0;
}
//time complexity: O(n)
//space complexity: O(1)