#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end()); //putting element into set to remove duplicates
        int res=0;
        for(auto n:nums)
        {
            int curr=n, prev=n-1, next=n+1; //for every number we'll check its next and previous consecutive number
            while(st.find(prev)!=st.end())
            {
                st.erase(prev); //to avoid recalculation
                prev--;
            }
            while(st.find(next)!=st.end())
            {
                st.erase(next);
                next++;
            }
            res=max(res,next-prev-1); //everytime find the maximum value
        }
        return res;
    }

};

int main()
{
    vector<int> nums {0,3,7,2,5,8,4,6,0,1};
    Solution sa;
    cout<<sa.longestConsecutive(nums);
    return 0;
}

//time complexity: O(n)
//space complexity: O(n)