#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int triangularSum(vector<int>& nums) 
    {
        int n = nums.size(), p = nums.size()-1;
        if(n==1) return nums[0];
        vector<int> arr (nums.size()-1);
        for(int i=0;i<n;i++) //this loop will run size of array times.
        {
            for(int j=0;j<p;j++) 
            {
                arr[j] = (nums[j] + nums[j+1])%10;
            }
            nums=arr;
            p--; //reducing the internal iteration
        }
        return arr[0];
    }

};

int main()
{
    vector<int> nums {1,2,3,4,5};
    Solution sa;
    cout<<sa.triangularSum(nums);
    return 0;
}

//time complexity: O(n!)
//space complexity: O(n-1)