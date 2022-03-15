#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<bool> dp (s.length(),false);
        dp[0]=true; //empty substring will always be true
        for(int i=0;i<s.length();i++)
        {
            for(auto w: wordDict)
            {
                //checking if the word formed at ith index is found in the dictionary or n
                if(dp[i])
                {
                    //breaking the string to check with current  word
                    string temp=s.substr(i,w.length());               
                    if(temp==w) dp[i+w.length()] = true;                                                  
                }
            }
        }
        return dp[s.length()];
    }     

};

int main()
{
    string s = "catsandog";
    vector<string> wordDict {"cats","dog","sand","and","cat"};
    Solution sa;
    cout<<sa.wordBreak(s,wordDict);
    return 0;
}

//time complexity: O(m*n)
//space complexity: O(1)