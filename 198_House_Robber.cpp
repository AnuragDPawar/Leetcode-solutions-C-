 #include <bits/stdc++.h>
 using namespace std;

  int rob(vector<int>& nums) {
        if(nums.size()==0) return 0; //edge case 1
        if(nums.size()==1) return nums[0]; //edge case 2
        if(nums.size()==2) return max(nums[0],nums[1]); //edge case 3
        vector<int> dp (nums.size()); //lookup table to check the recent optimum solution
        dp[0]=nums[0]; 
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
       {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);  
       }
        return dp[nums.size()-1];
    }

int main()
{
    vector<int> nums {2,7,9,3,1};
    cout<<rob(nums);
    return 0;
}
/*
Algorithm
1. Handle edge cases as shown in comments.
2. Declare dp array with size same as nums which will act as lookup table.
3. First values of dp will be stored manually.
4. In every iteration of FOR we will choose max of nums[i]+dp[i-2] and dp[i-1].
5. This max value will be stores to dp[ith] position.
6. Return the last element of dp.
*/