#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int res = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else{
                    int len = i-st.top();
                    res = max(res,len);
                }
            }
        }
        return res;
    }
};

int main()
{
    string s = ")()()(";
    Solution sa;
    cout<<sa.longestValidParentheses(s);
    return 0;
}

/*
Time complexity: O(n)
Space complexity: O(n)
*/