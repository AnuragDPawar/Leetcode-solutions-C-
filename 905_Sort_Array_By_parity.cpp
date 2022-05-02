#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        if(nums.size()==1) return nums;
        vector<int> res (nums.size());
        int start = 0, end = nums.size()-1;
        for(auto x:nums)
        {
            if(x%2==1)
            {
                res[end]=x;
                end--;
            }
            else if(x%2==0)
            {
                res[start]=x;
                start++;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums {3,1,2,4};
    Solution sa;
    vector<int> res = sa.sortArrayByParity(nums);
    for(auto x:res) cout<<x<<" ";
    return 0;
}