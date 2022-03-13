#include <bits/stdc++.h>
using namespace std;

class Solutions{
    public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        //this will set two most different strings at start and end
        sort(strs.begin(),strs.end());  
        string a = strs[0];
        string b = strs[n-1];
        string ans = "";
        for(int i=0;i<a.length();i++)
        {
            if(a[i]==b[i]) ans+=a[i]; //checking how many letters are matching 
            else break;
        }
        return ans;
    }

};

int main()
{
    Solutions sa;
    vector<string> strs {"flower","flow","flight"};
    cout<<sa.longestCommonPrefix(strs);
    return 0;
}

//time complexity: O(nlogn*m)
//space complexity: O(1)