#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==1) return nums;
        map<int, int> mp;
        //counting the frequncy of each element
        for(auto x: nums) mp[x]++; 
        vector<vector<int>> freq (nums.size()+1);
        map<int,int>::iterator it;
        //storing each element according their frequncy 
        for(it=mp.begin();it!=mp.end();it++) freq[it->second].push_back(it->first);
        vector<int> res;
        //storing k elements into res vector
        for(int i=freq.size()-1;i>=0;i--)
        {
            for(int j=0;j<freq[i].size();j++)
            {
                res.push_back(freq[i][j]);
                if(res.size()==k) return res;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums {1,1,1,2,2,3};
    Solution sa;
    vector<int> res = sa.topKFrequent(nums,2);
    for(auto x: res) cout<<x<<" ";
    return 0;
}