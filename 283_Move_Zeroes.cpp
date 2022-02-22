#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void moveZero(vector<int> &nums);
};

void swap(int l, int r, vector<int> &nums)
{
    int temp=nums[l];
    nums[l]=nums[r];
    nums[r]=temp;
}

void Solution::moveZero(vector<int> &nums)
{
    int l=0,r=0;
    while(l<nums.size())
    {
        if(nums[l]==0) l++; //skipping the zeros
        else
        {
            swap(l,r,nums); //swapping
            l++;
            r++;
        }
    }

}

int main()
{   
    Solution sa;
    vector<int> nums {0,1,0,2,3,5};
    sa.moveZero(nums);
    for(auto x:nums) cout<<x<<" ";
    return 0;
}

/*
Algorithm
1. Use two pointers.
2. One will skip zeros and other will stay on zero.
3. Swap the elements.
*/
