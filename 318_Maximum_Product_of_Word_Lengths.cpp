#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), res = 0;
        //to represent every word as binary integer
        vector<int> word_int (n,0);
        for(int i=0;i<n;i++)
        {
            string s = words[i];
            int int_rep = 0;
            for(int j=0; j<s.length();j++)
            {
                //every char will have number 0-25 and it is ORed with existing number with double shift
                int_rep|=1<<(s[j]-'a');
            }
            word_int[i] = int_rep;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                //this will tell us that there is no char in common
                if((word_int[i] & word_int[j])==0)
                {
                    int temp = words[i].length() * words[j].length();
                    res = max(res,temp); 
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<string> words {"abcw","baz","foo","bar","xtfn","abcdef"};
    Solution sa;
    cout<<"Answer: "<<sa.maxProduct(words);
    return 0;
}

/*
Time complexity: 
    Preprocessing: Sum(len(all words))
    Comparison: n^2 (n = length of array)
Space complexity: O(n)
*/