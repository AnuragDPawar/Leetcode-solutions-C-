 #include <bits/stdc++.h>
 using namespace std;

int steps(int n)
{
    if(n<=2) return n;
    int x=2,y=1;
    for(int i=3;i<n;i++)
    {
        int temp=x;
        x=x+y;
        y=temp;
    }
    return x+y;
}



 int main()
 {
     cout<<steps(5);
     return 0;
 }

 /*
Algorithm
1. Answer will be addition of answers of recent 2 steps.
2. Handle edge case.
3. Assign 2 variables starting with x=2 (answer for 2nd steps), y=1 (answer for 1st step)
4. Keep adding and swapping x and y.
5. Return x+y.
*/