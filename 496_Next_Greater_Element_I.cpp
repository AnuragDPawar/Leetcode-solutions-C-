#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res (nums1.size(),-1);
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++)
        {
            int x = nums2[i];
            while (!st.empty() && x > st.top()) //to find immediate next grater number
            {
                mp[st.top()] = x;
                st.pop();  
            }
            st.push(x);
        }
        for(int i=0;i<nums1.size();i++) //storing the result
        {
            if(mp.find(nums1[i])!=mp.end())
                res[i] = mp.find(nums1[i])->second;
        }
        return res;
    }
};

int main()
{
    vector<int> nums1 {4,1,2};
    vector<int> nums2 {1,3,4,2};
    vector<int> res;
    Solution sa;
    res = sa.nextGreaterElement(nums1, nums2);
    for(auto x:res) cout<<x<<" ";
    return 0;    
}

//time complexity: O(m.n)
//space complexity: O(n-1)