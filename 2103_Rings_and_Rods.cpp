#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countPoints(string s) {
        int n = s.length();
        unordered_map<int, string> mp;
        for(int i=1;i<n-1;i+=2) mp[s[i]]+=s[i-1]; //storing each character into string associated to a particular rod
        int cnt=0;
        unordered_map<int, string>::iterator it;
        for(it = mp.begin();it!=mp.end();it++)
        {
            string temp = it->second;
            int r=0,g=0,b=0;
            for(int i=0;i<temp.length();i++) //counting if a rod is having all 3 colors
            {
                if(temp[i]=='R') r++;
                else if(temp[i]=='G') g++;
                else if(temp[i]=='B') b++;
            }
            if(r!=0 && g!=0 && b!=0) cnt++;
        }
        return cnt;
    }
};

int main()
{
    string s = "B0R0G0R9R0B0G0";
    Solution sa;
    cout<<sa.countPoints(s);
    return 0;
}
/*
Time complexity: O(n)
Space complexity: O(k) (k=no. of rods)
*/