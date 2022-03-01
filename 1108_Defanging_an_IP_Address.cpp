#include <bits/stdc++.h>
using namespace std;

class Solutions{
    public:
    string defange(string s)
    {
        string res;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='.') res.push_back(s[i]); //if not '.' then directly add to res string
            else //else replace it with '[.]'
            {   
                res.push_back('[');
                res.push_back('.');
                res.push_back(']');
            }
        }
        return res;
    }
};

int main()
{
    Solutions sa;
    string s= "1.1.1.1";
    cout<<sa.defange(s);
    return 0;
}

//time complexity: O(n)
//space complexity: O(1)