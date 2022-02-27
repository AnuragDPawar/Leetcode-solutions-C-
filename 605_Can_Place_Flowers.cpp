#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool canPlace(vector<int> &nums, int n)
    {
        nums.insert(nums.begin(),0); //adding one zero at the begining
        nums.push_back(0); ////adding one zero at the end
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i-1]==0 && nums[i]==0 && nums[i+1]==0) //if we encounter three zeros straight thet means 
            {
                n--;
                i++;
            }
        }
        return n<=0; //checking if we convered all the flowers
    }
};

int main()
{
    Solution sa;
    vector<int> nums {1,0,0,0,1};
    cout<<sa.canPlace(nums,1);
    return 0;
}

//time complexity: O(n)