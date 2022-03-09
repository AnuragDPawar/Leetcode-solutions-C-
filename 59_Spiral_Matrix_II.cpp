#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
     vector<vector<int>> generateMatrix(int n) {
        int top=0,left=0,right=n-1, bottom=n-1,ctr=1;
        int direction=1;
        vector<vector<int> > res(n, vector<int>(n));        
        while(left<=right && top<=bottom)
        {
            //filling top row
            if(direction==1)
            {
                for(int i=top;i<=right;i++) 
                {
                    res[top][i]=ctr;
                    ctr++;
                }
                top++;
                direction=2;
            }
            //filling rightmost column
            else if(direction==2)
            {
                for(int i=top;i<=bottom;i++)
                {
                    res[i][right]=ctr;
                    ctr++;
                }
                right--;
                direction=3;
            }
            //filling bottommost row
            else if(direction==3)
            {
                for(int i=right;i>=left;i--)
                {
                    res[bottom][i]=ctr;
                    ctr++;
                }
                bottom--;
                direction=4;
            }
            //filling leftmost column
            else if(direction==4)
            {
                for(int i=bottom;i>=top;i--)
                {
                    res[i][left]=ctr;
                    ctr++;
                }
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
    vector<vector<int>> ans = sa.generateMatrix(3);
    for(auto x: ans)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}

//time complexity: O(n*n)
//space complextiy: O(1)