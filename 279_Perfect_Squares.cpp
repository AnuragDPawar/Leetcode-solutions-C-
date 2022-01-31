
 #include <bits/stdc++.h>
 using namespace std;
vector<int> dp;
    int solve(int n)
    {
        if(n==0) return 0;
        if(n<=3) return n;
        if(dp[n]!=-1) return dp[n]; //checking if we have already calculated the value to avoid excess recursive calls
        int ans=n;
        for(int i=1;i*i<=n;i++) //starting with 1 to break the n into perfect squares
        {
            ans=min(ans,1+solve(n-i*i)); //storing ans
        }
        dp[n]=ans; //if we are calculating the value for n for the first time then storing it in the lookup table
        return ans;
        
    }
        
    int numSquares(int n) 
    {
        dp.resize(n+1,-1); //initializing lookup table with -1
        int ans=solve(n);
        return ans;
    }

      int main()
    {
        int n=27;
        cout<<numSquares(n);
        return 0;
    }
   