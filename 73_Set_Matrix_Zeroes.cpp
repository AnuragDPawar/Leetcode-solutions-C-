#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void setZeros(vector<vector<int>> &nums)
    {
        int row=nums.size(),col = nums[0].size();
        bool r=false, c=false;
        //marking first element of every rown and column as zero if it contains 0
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(nums[i][j]==0)
                {
                    if(i==0) r=true;
                    if(j==0) c=true;
                    nums[0][j]=0;
                    nums[i][0]=0;
                }
            }
        }
        //setting 0s in marked columns,rows and skipping first row and column
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
                if(nums[0][j]==0 || nums[i][0]==0) nums[i][j]=0;
        }
        //setting 0s for the first row and column
        if(r)
            for(int i=0;i<col;i++) nums[0][i]=0;
        if(c)
            for(int i=0;i<row;i++) nums[i][0]=0;
    }
};

int main()
{
    vector<vector<int>> nums = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution sa;
    sa.setZeros(nums);
    for(auto x:nums)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}
/*
time complexity: O(m*n)
space complexity: O(1)
Algorithm
1. Initialize two booleans and set them to false, they will be used for mat[0][0] position.
2. Traverse the matrix and if 0 found then mark the corresponding first element row, column to 0.
3. While traversing if i==0,j==0 i.e. very first element of matrix then set corresponding boolean to true.
4. Again, traverse the matrix with i=1, j=1 and if the first element of any row or column is 0 then set the whole row,column to 0.
5. For 0th row and 0th column check if respective booleans are true and if yes then set the 0s.
*/