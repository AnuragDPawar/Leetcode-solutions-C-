#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> intersection(vector<int> nums1,vector<int> nums2)
    {
        set<int> S;
        vector<int> res;
        for(int i=0;i<nums1.size();i++) //storing each element from nums1 into set
        {
            S.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(S.count(nums2[i])) //checking if nums2 element is presnet in the set
            {
                res.push_back(nums2[i]); //adding to result
                S.erase(nums2[i]); //erasing it to avoid duplication
            }
        }
        return res;
    }
};

int main()
{
    Solution sa;
    vector<int> nums1 {9,4,5};
    vector<int> nums2 {9,4,9,8,4};
    vector<int> res= sa.intersection(nums1,nums2);
    for(auto x:res) cout<<x<<" ";
    return 0;
}

//time complexity: O(m+n)
//space complexity: O(m)