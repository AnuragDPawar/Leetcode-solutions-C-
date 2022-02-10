#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amt) {
        vector<int> dp (amt+1, amt+1);
        dp[0]=0;
      for(int i=1;i<=amt;i++)
      {
          for(int j=0;j<coins.size();j++)
          {
              if(coins[j] <= i) dp[i]=min(dp[i], dp[i - coins[j]] + 1);
          }
      }
        if (dp[amt]<=amt) return dp[amt];
        return -1;
    }

int main()
{
    vector<int> coins {1,2,5};
    cout<<"Ans: "<<coinChange(coins,11);
    return 0;
}