#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int help(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j)
    {
        //returning if we've already calculated the value
        if(dp[i][j]!=-1) return dp[i][j];
        //calculating max path for all the neighbours
        int top = 0,x = matrix[i][j],bottom = 0,left =0, right =0;
        if(i-1>=0 && matrix[i-1][j]>x) 
            top = help(matrix, dp, i-1,j);

        if(i+1<=matrix.size()-1 && matrix[i+1][j]>x) 
            bottom = help(matrix, dp, i+1,j);

        if(j-1 >=0 && matrix[i][j-1]>x) 
            left = help(matrix, dp, i, j-1);

        if(j+1<=matrix[0].size()-1 && matrix[i][j+1]>x) 
            right = help(matrix, dp, i , j+1);
        //updating and returning the max value for input i,j
        return dp[i][j] = 1 + max({left, right, top, bottom});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(),ans = INT_MIN;
        vector<vector<int>> dp (n, vector<int> (matrix[0].size(), -1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                dp[i][j] = help (matrix,dp,i,j);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> matrix {{9,9,4},{6,6,8},{2,1,1}};
    Solution sa;
    cout<< sa.longestIncreasingPath(matrix);
    return 0;
}

/*
Time complexity: O(m*n)
Space complexity: O(m*n)
*/