#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int isSingle(vector<int> nums)
    {
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            res=res^nums[i];
        }
        return res;
    }
};

int main()
{
    Solution sa;
    vector<int> s {1,2,2,1,3,4,4};
    cout<<sa.isSingle(s);
    return 0;
}