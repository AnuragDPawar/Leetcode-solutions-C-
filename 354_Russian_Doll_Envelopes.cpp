#include <bits/stdc++.h>
using namespace std;

class Solution{
    static bool compare(vector<int>&a,vector<int>&b)
    {   //if number at 0th index is same then we'll look for 1st place
        if(a[0]==b[0])
            return a[1]>b[1]; //we want greater 1's place to be ahead of smaller
        return a[0]<b[0];
    }
    public:
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(),E.end(), compare);
        vector<int> dp;
        for(auto e:E)
        {
            //this function return immediate greate value in the vector, if not present it will point to the end.
            auto it = lower_bound (dp.begin(),dp.end(),e[1]);
            if(it==dp.end()) 
                dp.push_back(e[1]);
            else
                *it = e[1];
        }
        return dp.size();
    }
};

int main()
{
    vector<vector<int>> E {{1,3},{3,5},{6,7},{6,8},{8,4},{9,5}};
    Solution sa;
    cout<<sa.maxEnvelopes(E);
    return 0;
}

/*
Time complexity: O(n log n)
Space complexity: O(n)
*/