 #include <bits/stdc++.h>
 using namespace std;
void dfs(vector<vector<int>>& nums, int i,int j)
{
    nums[i][j]=0; //to avoid the same connection to be counted again
    for(int k=0;k<nums.size();k++)
    {
        if(nums[j][k]==1) dfs(nums,j,k); //if connection found then again slicing down the matrix
    }
}
int findCircleNum(vector<vector<int>>& nums)
{
    int cnt=0;
    for(int i=0;i<nums.size();i++)
    {
        for(int j=0;j<nums[i].size();j++)
        {
            if(nums[i][j]==1) //checking if there is connection between 2 cities
            {
                cnt++;
                dfs(nums,i,j); //calling dfs function to check further provinces into the sliced matrix
            }
        }
    }
    return cnt;
}
 int main()
 {
     vector<vector<int>> nums {{1,1,0},{1,1,0},{0,0,1}};
     cout<<findCircleNum(nums);
     return 0;
 }
 /*
Algorithm [Graph+DFS]
1. Traverse the matrix and check if isConnected[i][j]==1 i.e. if there is a connection between cities.
2. If yes, increase the count and slice down the matrix with a dfs function and search for connections in the smaller matrix.
3. While doing so, set isConnected[i][j]=0 to avoid a connection to be counted again.
*/