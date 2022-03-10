#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void rotate(vector<vector<int>> &matrix)
        {
            //converting original matrix into a transpose matrix i.e. rotating every element around diagonal
            for(int i=0;i<matrix.size();i++)
                for(int j=0;j<i;j++) 
                    swap(matrix[i][j],matrix[j][i]);
            
            //reversing the element of each row
            for(int i=0;i<matrix.size();i++)
                reverse(matrix[i].begin(),matrix[i].end());

        } 
};

int main()
{
    Solution sa;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    sa.rotate(matrix);
    for(auto x:matrix)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}

//time complexity: O(n)
//space complexity: O(1)