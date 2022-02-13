# include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> nums)
{
    if(nums.size()==0) return 0;
    int res= *max_element(nums.begin(),nums.end());
    int curMax=1,curMin=1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        {
            curMax=1;
            curMin=1;
            continue;
        }
        int temp=curMax*nums[i];
        curMax=max({nums[i]*curMax,curMin*nums[i],nums[i]});
        curMin=min({temp,curMin*nums[i],nums[i]});
        res=max(res,curMax);
    }
    return res;
}
int main()
{
    vector<int> s {-2,0,1};
    cout<<maxProduct(s);
    return 0;
}

/*
Algorithm [Dynamic programming]
1. Two variables needed to keep track of min and max product till ith iteration.
2. At every iteration there are 3 possibilities for curMax and curMin:
    a. existing value * nums[i]
    b. existing value * curMin or curMax
    c. curent element i.e. nums[i]
3. Result will be max(res and curMax)
*/