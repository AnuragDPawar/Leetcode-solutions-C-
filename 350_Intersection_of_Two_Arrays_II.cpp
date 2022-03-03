#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        int n1=nums1.size(),n2=nums2.size();
        map<int,int> m;
        for(int i=0;i<n1;i++) //putting all the elements from nums1 and their frequency into the map
        {
            m[nums1[i]]++;
        }
        vector<int> res;
        for(int i=0;i<n2;i++)
        {
            //checking if elements from nums2 are present in map and if found reducing their frequency to avoid copying same elements
            if(m.find(nums2[i])!=m.end() && m.find(nums2[i])->second-- >0) 
                res.push_back(nums2[i]);
        }
        return res;
    }
};

int main()
{
    Solution sa;
    vector<int> nums1 {1,2,2,1,2};
    vector<int> nums2 {1,2};
    vector<int> res= sa.intersection(nums1,nums2);
    for(auto x: res) cout<<x<<" ";
    return 0;
}

//time complexity: O(m+n)
//space complexity: O(m)