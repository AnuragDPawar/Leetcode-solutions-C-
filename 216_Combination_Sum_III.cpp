#include<bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> res;
    public:
    void help(int k, int sum, int start,vector<int>&temp)
    {
        //base conditions
        if(temp.size()==k) //we have used k elements
        {
            if(sum==0) res.push_back(temp); //checking if we reached desired sum
            return;
        }
        if(sum<0) return;

        for(int i=start;i<=9;i++)
        {
            temp.push_back(i); //adding current element to the temp vector
            help(k,sum-i,i+1,temp); //calling recusion for all the possible combinations
            temp.pop_back(); //if sum not found then we'll remove the last element
        }
   
    }
    vector<vector<int>> combinationSum(int k, int n) 
    {
        vector<int> temp;
        help(k,n,1,temp);
        return res;
    }

};

int main()
{
    Solution sa;
    vector<vector<int>> ans = sa.combinationSum(3,9);
    for(auto x: ans)
    {
        for(auto y:x) cout<<y<<" ";
        cout<<endl;
    }
    return 0;
}

//time complexity: O(9) i.e. O(1)