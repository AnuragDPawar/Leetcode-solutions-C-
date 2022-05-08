#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size(), mini = INT_MIN;
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<mini) return true; //pattern found
            else
            {
                while(!st.empty() && nums[i]>st.top()) //popping the numbers which are not obeying the condition
                {
                    mini = st.top();
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};

int main()
{
    vector<int>nums {3,5,0,3,4};
    Solution sa;
    bool res = sa.find132pattern(nums);
    cout<<res;
    return 0;
 }

/*
Time complexity: O(n)
Space complexity: O(n)
*/