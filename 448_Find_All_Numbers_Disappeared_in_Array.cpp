#include <bits/stdc++.h>
using namespace std;

class Solutions{
    public:
    vector<int> find_missing(vector<int> &nums)
    {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            int curr=abs(nums[i]); //to avoid accessing the negatvie index
            nums[curr-1]=-abs(nums[curr-1]); //negating every element for the current-1 index
            //this will also ensure that the number at missing no.-1's place will be positive
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
}; 

int main()
{
    vector<int> nums {4,3,2,7,8,2,3,1};
    
    Solutions sa;
    vector<int> res = sa.find_missing(nums);
    for(auto x:res) cout<<x<<" "; 
    return 0;
}