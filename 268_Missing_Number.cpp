#include <bits/stdc++.h>
using namespace std;

class Solutions{
    public:
    int missing(vector<int> nums)
    {
        int s1=0, s2=0;
        for(int i=0;i<=nums.size();i++)
        {
            if(i<nums.size()) s1+=nums[i];
            s2+=i;
        }
        return s2-s1;
    }
};

int main()
{
    Solutions sa;
    vector<int> nums {3,0,1};
    cout<<sa.missing(nums);
    return 0;
}