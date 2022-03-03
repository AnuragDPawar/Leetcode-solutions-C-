#include <bits/stdc++.h>
using namespace std;

class Solutions{
    public:
    bool isAnagram(string s,string t)
    {
        if(s.length()!=t.length()) return false; //if length of the both string is different the return false
        map<char,int> m;
        for(int i=0;i<s.length();i++) //for the first string: storing each char and its frequency in map
        {
            m[s[i]]++;
        }
        for(int i=0;i<t.length();i++) //iterating second string
        {
            if(m.find(t[i])!=m.end()) //checking if char is present in map
            {
                m.find(t[i])->second--; //if yes then reducing the freqeuncy 
                if(m.find(t[i])->second==0) m.erase(t[i]); //if the frequency is zero then delete the element 
            }
        }
        if(m.empty()) return true; //if map is empty then all the characters matched
        return false;
    }
};

int main()
{
    Solutions sa;
    string s="cat", t="tac";
    cout<<sa.isAnagram(s,t);
    return 0;
}

//time complexity: O(m+n)
//space complexity: O(m)