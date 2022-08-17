#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size(), res = 1;
        vector<int> dp (n,1); //every pair is having minimum 1 length of sequence 
        sort(pairs.begin(),pairs.end()); //sorting by first value
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(pairs[i][0]>pairs[j][1]) dp[i] = dp[j]+1; //finding optimum value till ith iteration
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> pairs {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{9,8},{-5,3},{0,3}};
    Solution sa;
    cout<<sa.findLongestChain(pairs);
    return 0;
}

//time complexity: O(n log n) + o(n)
//space complexity: O(n)