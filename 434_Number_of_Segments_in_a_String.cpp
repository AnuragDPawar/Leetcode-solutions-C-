#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countSegments(string s) {
        int n = s.length(), res=0;
        if(n==0)return 0;
        bool flag = false;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ') flag = true;
            else if(s[i]==' ' && flag)
            {
                res++;
                flag = false;
            }
            if(i == n-1 && flag) res++;
        }
        return res;
    }
};

int main()
{
    string s = "Hello, my name is John";
    Solution sa;
    cout<<sa.countSegments(s);
    return 0;
}
/*
Time complexity: O(n)
Space complexity: O(1)
*/