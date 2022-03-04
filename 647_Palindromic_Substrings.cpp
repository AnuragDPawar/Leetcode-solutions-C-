#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int exapandFromCentre(string s, int start, int end, int& res)
    {
        if(start>end) return 0;
        while(start>=0 && end<s.length() && s[start]==s[end])
        {
            start--; //going backwards
            end++; //going towards end
            res++;//every matched string is a palindrome so result will increament
        }
        return res;
    }
    int countSubstrings(string s)
    {
        if(s.length()==0) return 0;
        int res=0;
        for(int i=0;i<s.length();i++)
        {
            exapandFromCentre(s,i,i,res);
            exapandFromCentre(s,i,i+1,res);
        }
        return res;
    }

};

int main()
{
    Solution sa;
    string s="abc";
    string p="aaa";
    cout<<sa.countSubstrings(s)<<endl;
    cout<<sa.countSubstrings(p);
    return 0;
}