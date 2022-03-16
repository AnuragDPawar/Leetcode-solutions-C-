#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int reverse(int x) {
        if(x==0) return 0;
        bool negative=false;
        if(x<0) negative = true;
        string num = to_string(x);
        std::reverse(num.begin(),num.end());
        int res=0;
        //try-catch block to avoid integer overflow
        try{
            res=stoi(num);
        }catch(...){
            return 0;
        }
        if(negative) res*=-1;
        return res;
    }

};

int main()
{
    Solution sa;
    cout<<sa.reverse(-45123);
    return 0;
}

//time complexity: O(1) + O(n)  [1 for to_string and n for stoi, n=length of string]
//space complexity: O(n)  n=length of string i.e. number of digits 