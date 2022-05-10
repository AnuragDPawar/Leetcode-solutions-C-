#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int firstMissingPositive(vector<int>& nums) {
        bool containsOne = false;
        //checking if 1 is present or not
        for(auto x: nums)
        {
            if(x==1) containsOne = true;
            break;
        }
        int n = nums.size();
        if(n==1) return 2;

        //if 1 is there then missing number is between 1 to size of array
        for(int i=0;i<n;i++)
            if(nums[i]<=0 || nums[i]>n) nums[i] =1;
        
        //multiplying by -1 to each element by using current element as index
        for(int i=0;i<n;i++)
        {
            int x = abs(nums[i]);
            if(nums[x-1]>0) nums[x-1]*=-1;
        }

        //if any number is positive then missing number is i+1
        for(int i=0;i<n;i++)
            if(nums[i]>0) return i+1;     
        
        //all the number are present and last one is missing
        return n+1;
    }
};

int main()
{
    vector<int> nums {1,2,0};
    Solution sa;
    cout<<sa.firstMissingPositive(nums);
    return 0;
}

/*
Time complexity: O(n)
Space complexity: O(1)

****Using O(n) memory****
unordered_set<int> st;
for(auto x: nums) st.insert(x);
for(int i=1;i<nums.size()+1;i++)
{
    if(!st.count(i)) return i;
}
return nums.size()+1;
*/
