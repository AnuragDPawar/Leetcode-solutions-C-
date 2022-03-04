#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> findAnagram(string s, string p)
    {
        vector<int> res;
        if(p.length()>s.length()) return res;
        map<char,int> pCount;
        map<char,int> sCount;
        for(int i=0;i<p.length();i++)
        {
            pCount[p[i]]++;
            sCount[s[i]]++;
        }
        if(pCount==sCount) res.push_back(0);
        int l=0; //left pointer
        for(int r=p.length();r<s.length();r++)
        {
            sCount[s[r]]++; //adding frequency of new character (right pointer)
            sCount[s[l]]--; //subtracting frequency of old character (left pointer)
            if(sCount.find(s[l])->second==0) sCount.erase(s[l]); //if freq of any char is 0 then remove it from map
            l++; //increament the left pointer
            if(sCount==pCount) res.push_back(l);
        }
        return res;
    }

};

int main()
{
    Solution sa;
    string s= "cbaebabacd";
    string p="abc";
    vector<int> ans = sa.findAnagram(s,p);
    for(auto x: ans) cout<<x<<" ";
    return 0;
}

//time complexity: O(len(s))
// space complexity: O(26) there are max 26 characters