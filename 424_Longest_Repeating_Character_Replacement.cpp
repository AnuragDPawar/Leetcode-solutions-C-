#include <bits/stdc++.h>
using namespace std;

class Solutions{
    public:
    int characterReplacement(string s, int k)
    {
        int l=0,res=0,curMax=0;
        map<char,int>mp;
        for(int r=0;r<s.length();r++)
        {
            mp[s[r]]++; //to count frequncy of incoming char.
            curMax=max(curMax,mp[s[r]]); //to update the current maximum frequncy.
            if((r-l+1)-curMax>k) //checking if we crossed the allowed number of replacements
            {
                mp[s[l]]--;//if yes then we will reduce the frequncy of the s[l].
                if(mp[s[l]]==0) mp.erase(mp[s[l]]); //if it 0 then remove it from map
                l++; //move the window forward
            }
            res=max(res,r-l+1);  //result will be current window
        }
        return res;
    }

};

int main()
{
    Solutions sa;
    string s="AABABBA";
    cout<<sa.characterReplacement(s,1);
    return 0;
}
/*
time complexity: O(26*n) i.e. O(n)
Space complexity: O(26)
Algorithm: Sliding window approach
1. Initially both l,r will start with 0.
2. r will move forward and count the frequncy of the next letter.
3. Once a new letter is added we will check if it has frequncy greater than current max frequncy.
4. If it has frequncy grater than current freq then will will update it.
5. At every iteration we will calculate the length of the window - maxfreqency and compare it with k.
6. If it is greater than k then we know that we cannot replace those many letters.
7. We need to shrink the window and hence we will remove lth element and reduce it frequency and l++.
8. Result will be the current window size.
*/