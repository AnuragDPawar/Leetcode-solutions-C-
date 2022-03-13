#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        priority_queue<pair<int,int>> rank;
        for(int i=0;i<score.size();i++)
            rank.push(make_pair(score[i],i));
        
        vector<string> res (score.size());
        int cnt=1; //to keep track of top 3
        for(int i=0;i<score.size();i++)
        {
            if(cnt==1)
            {
                res[rank.top().second] = "Gold Medal";
                cnt++;
            }
            else if(cnt==2)
            {
                res[rank.top().second] = "Silver Medal";
                cnt++;
            }
            else if(cnt==3)
            {
                res[rank.top().second] = "Bronze Medal";
                cnt++;
            }
            else
            {
                res[rank.top().second] = to_string(cnt);
                cnt++;
            }
            rank.pop();
        }
        return res;
    }

};

int main()
{
    Solution sa;
    vector<int> score {10,3,8,9,4};
    vector<string> res = sa.findRelativeRanks(score);
    for(auto x: res) cout<<x<<" ";
    return 0;
}
/*time complexity: O(nlogn)+O(n)
Algorithm
1. Use a priority queue of pairs to store element and its index. 
2. Then run a For till the size of score array.
3 Place the element into res vector according to the second of top of queue. Use cnt to keep track of top 3.
*/