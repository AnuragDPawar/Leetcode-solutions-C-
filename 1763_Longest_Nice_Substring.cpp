#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string longestNiceSubstring(string s) {
        if(s.length()==1) return "";
        unordered_set<char> st;
        //to put characters into set to find the upper/lower case
        for(auto x:s) st.insert(x); 
        for(int i=0;i<s.length();i++)
        {
            //checking if we are having nice substring
            if(st.count(tolower(s[i])) && st.count(toupper(s[i]))) continue;
            //if not then breaking the string into two parts
            string prev = longestNiceSubstring(s.substr(0,i));
            string next = longestNiceSubstring(s.substr(i+1));
            return prev.length()>=next.length() ? prev : next;
        }
        return s;
    }
};

int main()
{
    string s = "YazaAay";
    Solution sa;
    cout<<sa.longestNiceSubstring(s);
    return 0;
}