#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<string>> groupAnagrams(vector<string> str)
    {
        vector<vector<string>> res;
        if(str.size()==0) return res;
        map<string, vector<string>> mp;
        for(auto s:str)
        {
            string temp=s;
            sort(temp.begin(),temp.end()); //sorting each string to get key for map
            mp[temp].push_back(s); //each anagram will be sorted according to the key
        }
        for(auto x: mp)
            res.push_back(x.second); //taking values from the map to store into result vector

        return res;
    }
};

int main()
{
    Solution sa;
    vector<string> str {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> r = sa.groupAnagrams(str);
    for(auto x: r)
    {
        cout<<"[ ";
        for(auto y:x)
            cout<<y<<",";
        cout<<" ]";
    }
    return 0;
}

//time complexity: O(m.nlogn)
//space complexity: O(m)