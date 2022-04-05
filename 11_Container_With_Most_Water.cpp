#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxArea(vector<int>& nums) {
        int maxarea = 0, l=0,r=nums.size()-1;
        while(l<r)
        {
            int ht = min (nums[l],nums[r]);
            int area = 0;
            area = ht * (abs(r-l));
            maxarea=max(maxarea,area);
            if(nums[l]<nums[r]) l++;
            else r--;
        }
        return maxarea;
    }

};

int main()
{
    vector<int> nums {1,8,6,2,5,4,8,3,7};
    Solution sa;
    cout<<sa.maxArea(nums);
    return 0;
}

/*
Algorith
1. Use two pointers method, first will point to first index and second one to last.
2. Calculate the area at each iteration and update the maxarea.
3. Move the pointer with the smaller value.
Time complexity: O(n)
space complexity: O(1)
*/