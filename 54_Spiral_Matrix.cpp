#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> res;
        int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
        int direction=1;
        while(top<=bottom && left<=right)
        {
            
            //fetching topmost row
            if(direction==1)
            {
                for(int i=left;i<=right;i++) res.push_back(matrix[top][i]);
                top++;
                direction=2;
            }
            //fetchting rightmost column
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++) res.push_back(matrix[i][right]);
                right--;
                direction=3;
            }
            //fetching bottommost row
            else if(direction==3)
            {
                for(int i=right;i>=left;i--) res.push_back(matrix[bottom][i]);
                bottom--;
                direction=4;
            }
            //fetching leftmost column
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--) res.push_back(matrix[i][left]);
                left++;
                direction=1;
            }
        }

        return res;
    }
};

int main()
{
    Solution sa;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res= sa.spiralOrder(matrix);
    for(auto x: res) cout<<x<<" ";
    return 0;
}
/*
Time complexity: O(m*n)
Space complexity: O(1)
Algorithm
1. Set boundries as left, right, top, bottom.
2. Breaking condition will be if left>right and top>bottom i.e. we are at the last cell.
3. Start traversing with first row, move from left to right, onece the row is fetch increment top as we are done with first line.
4. Similarly proceed with rightmost column then bottommost row and then leftmost column and keep updating corresponding boundary.
5. Basically we are slicing the matrix with a sequence.
*/