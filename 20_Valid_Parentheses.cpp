#include <bits/stdc++.h>
using namespace std;
#define MAXE 10000

class Stack{
    int top;
    public:
        char myStack [MAXE];
        Stack() {top=-1;} //constructor
        bool push(char s);
        char pop();
        bool isEmpty();
        char returnTop();
};

char Stack::returnTop()
{
    char s=myStack[top];
    return s;
}
bool Stack::push(char s)
{
    if(top>=MAXE-1) 
    {
        cout<<"\nStack overflow\n";
        return false;
    }
    else
    {
        myStack[++top] = s;
        return true;
    }
}
char Stack::pop()
{
    if(top<0)
    {
        cout<<"\nStack empty\n";
        exit;
    }
    else
    {
        char s=myStack[top];
        top--;
        return s;
    }
}

bool Stack::isEmpty()
{
    if(top<0) return true;
    return false;
}

class Solution{
    public:
    bool isValid(string s)
    {
        Stack st;
        if(s.length()==1) return false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{'||s[i]=='[') st.push(s[i]);
            else
            {
                if(st.isEmpty()) return false;
                else if(st.returnTop()=='(' && s[i]!=')') return false;
                else if(st.returnTop()=='{' && s[i]!='}') return false;
                else if(st.returnTop()=='[' && s[i]!=']') return false;
                else st.pop();
            }
        }
        if(st.isEmpty()) return true;
        return false;
    }

};

int main()
{
    Solution sa;
    string s="{{()}";
    bool res=sa.isValid(s);
    cout<<res;
    return 0;
}

/*
I have impletemented stack just for practice.
Algorithm
1. Push any kind of opening bracket in the stack.
2. If not opening bracket check if stack is emtpy or not if not then compare for each pair.
3. If not found return false.
4. After the end of FOR if stack is empty return true as string has a perfect pair.\
*/