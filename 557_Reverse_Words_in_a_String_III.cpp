#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string reverseWords(string s) {
        int i=0,start=0;
        string res="";
        for(i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                int p=i-1;
                string temp = "";
                while (p>=start)
                {
                    temp+=s[p];
                    p--;
                }
                //fixing starting pointer
                start=i+1;
                res+=temp;
                res+=" ";
            }
        }
        //adding the last word
        i-=1;
        while (i>=start)
        {
            res+=s[i];
            i--;
        }
        
        return res;    
    }
};

int main()
{
    string s = "Let's take LeetCode contest";
    Solution sa;
    cout<<sa.reverseWords(s);
    return 0;
}
//time & space complexity: O(n)