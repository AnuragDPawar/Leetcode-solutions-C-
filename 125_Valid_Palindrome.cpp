#include <bits/stdc++.h>
using namespace std;

class Solutions{
    public:
    bool isPalindrome(string s)
    {
        if(s.length()==0) return true;
        int n=s.length()-1,i=0;
        while(i<n)
        {
            while(i<n && !isalnum(s[i])) i++; //skipping everything except alphanumeric characters from the BEGINNING 
            while(i<n && !isalnum(s[n])) n--; //skipping everything except alphanumeric characters from the END
            if(i<n && tolower(s[i])!=towlower(s[n])) return false; //lowering the characters and checking
            i++;n--;
        }
        return true;
    }
};

int main()
{
    Solutions sa;
    string s = "race a car";
    cout<<sa.isPalindrome(s);
    return 0;
}

//time complexity: O(n)
//space complexity: O(1)