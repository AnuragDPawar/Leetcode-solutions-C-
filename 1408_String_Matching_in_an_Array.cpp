#include<bits/stdc++.h>
using namespace std;

class Solution{
    static bool help (const string &s1, const string &s2)
    {
        return s1.length()<s2.length();
    }
    public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(), help);
        vector<string> res;
        int n = words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(words[j].find(words[i])!= -1)
                {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<string> words {"mass","as","hero","superhero"};
    Solution sa;
    vector<string> res = sa.stringMatching(words);
    for(auto x:res) cout<<x<<" ";
    return 0;
}

/*
Time complexity: O(nlogn)
Space complexity: O(1)
*/