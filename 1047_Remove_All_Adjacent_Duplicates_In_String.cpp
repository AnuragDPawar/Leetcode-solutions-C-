#include<bits/stdc++.h>
using namespace std;

class Solutions{
    public:
    string remove(string s)
    {
        string ans;
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty()) st.push(s[i]); //for the first iteration
            else if(st.top()!=s[i]) st.push(s[i]); //if letters don't match we will push
            else st.pop(); // if they match then we will pop, with this all the duplicated will be removed
        }
        while(!st.empty())
        {
            ans=st.top()+ans; //storing the answer
            st.pop();
        }
        return ans;
    }
};

int main()
{
    Solutions sa;
    string s="azxxzy";
    cout<<sa.remove(s);
    return 0;
}
//time complexity: O(n)
//space complexity: O(n)