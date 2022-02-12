 #include <bits/stdc++.h>
 using namespace std;

    int help(vector<int>& nums) //this function utilizes exact same code from house robber 1
    {
        if(nums.size()==0) return 0; //edge case 1
        if(nums.size()==1) return nums[0]; //edge case 2
        if(nums.size()==2) return max(nums[0],nums[1]); //edge case 3
        vector<int> dp (nums.size());
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);  
        }
        return dp[dp.size()-1];
    }
    int rob(vector<int>& nums) 
    {
        if(nums.size()==0) return 0; //edge case 1
        if(nums.size()==1) return nums[0]; //edge case 2
        if(nums.size()==2) return max(nums[0],nums[1]); //edge case 3
        int s1,s2,n=nums.size(); //two variable to hold the solutions
        vector<int> v1; 
        vector<int> v2;
        v1=vector<int>(nums.begin(),nums.end()-1); //sliced vector from start to end-1
        v2=vector<int>(nums.begin()+1,nums.end()); //sliced vector start-1 to end
        s1=help(v1);
        s2=help(v2);        
        return max(s1,s2);
    }


int main()
{
    vector<int> nums {1,2,3,1};
    cout<<rob(nums);
    return 0;
}

/*
Algorithm
1. We have to use the same logic as House robber 1
2. As the houses are arranged in circles we cannot rob 1st and last house together.
3. Hence we will use a helper function and pass it the sliced arrays.
4. 1st sliced array will contain the elements from 1 to n-1 and second will contain 0 to n-1.
5. Max from both will be the answer.
*/