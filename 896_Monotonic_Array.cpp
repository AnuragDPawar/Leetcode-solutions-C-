#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isMonotonic(vector<int>& nums) {
        bool increase = true;
        bool decrease = true;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1]) decrease=false; //this will update the decreasing boolean if array is inceasing
            if(nums[i]>nums[i+1]) increase=false; //this will update the decreasing boolean if array is decreasing
        }
        return increase||decrease; //if either of the conditions are true, result will be true
    }

};

int main()
{
    vector<int> nums {1,2,2,3,4};
    Solution sa;
    cout<<sa.isMonotonic(nums);
    return 0;
}

/*
time complexity: O(n)
space complexity: O(1)
*/