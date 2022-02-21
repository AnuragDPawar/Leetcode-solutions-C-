#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maxProfit(vector<int> prices);
};

int Solution::maxProfit(vector<int> prices)
{
    int mini=INT_MAX;
    int profit=0;
    for(int i=0;i<prices.size();i++)
    {
        mini=min(mini,prices[i]); //this will have the minimum element in the array.
        profit=max(profit,prices[i]-mini); //this will calculate and store the max profit.
    }
    return profit;
}

int main()
{
    Solution sa;
    vector<int> s {7,1,5,3,6,4};
    cout<<"Max profit is: "<<sa.maxProfit(s);
    return 0;
}

/*
Algorithm
1. Keep updating and storing the minimum element in the array.
2. Keep updating and storing the max profit while looping through.
*/
