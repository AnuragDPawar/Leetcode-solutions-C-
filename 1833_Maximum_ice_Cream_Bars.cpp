#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        double res =0, coin = coins;
        for(int i=0;i<costs.size();i++)
        {
            if(costs[i]<=coin && coin-costs[i]>=0)
            {
                res++;
                coin-=costs[i];
            }
        }
        return res;
    }
};

int main()
{
    vector<int> coins {1,3,2,4,1};
    Solution sa;
    cout<<sa.maxIceCream(coins,7);
    return 0;
}

/*
Time complexity: O(nlogn + n)
Space complexity: O(1)
*/