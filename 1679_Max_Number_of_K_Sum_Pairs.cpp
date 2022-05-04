#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxOperations(vector<int>& nums, int k) 
    {
        int cnt=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[k-nums[i]]>0) //if difference exists
            {
                cnt++;
                mp[k-nums[i]]--;
            }
            else mp[nums[i]]++; //if not then storing the number
        }
        return cnt;
    }

};

int main()
{
    vector<int> nums {4,4,1,3,1,3,2,2,5,5,1,5,2,1,2,3,5,4};
    Solution sa;
    cout<<sa.maxOperations(nums,2);
    return 0;
}

/*
Time coomplexity: O(n)
space compmplexity: O(n)
*/