#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};
class Linked_list{
    public:
    void insert(ListNode** head, int x)
    {   
        ListNode* temp=new ListNode(x);
        temp->next=nullptr;
        ListNode* ptr=nullptr;
        if(!*head) *head=temp;
        else
        {
            ptr=*head;
            while(ptr->next) ptr=ptr->next;
            ptr->next=temp;
        }
    }
    void print(ListNode** head)
    {
        ListNode* temp=*head;
        while(temp)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
    bool isPalindrome(ListNode** head)
    {
        //Finding the middle of the LL
        ListNode* fast=*head;
        ListNode* slow=*head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        //Reversing the second part of the LL
        ListNode* prev=NULL;
        while(slow)
        {
            ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        //Checking the palindrome
        ListNode* left=*head;
        ListNode* right=prev; //prev is pointing to the end of LL and this half part of LL is already reversed
        while(right)
        {
            if(left->val!=right->val) return false;
            right=right->next;
            left=left->next;
        }
        return true;
    }
};

int main()
{
    Linked_list l;
    vector<int> s {1,2,1,2,3};
    ListNode* head=nullptr;
    for(auto x: s) l.insert(&head, x); 
    l.print(&head); 
    cout<<endl;
    cout<<l.isPalindrome(&head);
    return 0;
}

/*
time complexity: O(n)
space complexity: O(1)
Algorithm:
1. Find the mid of the LL
2. Reverse the second of LL from midpoint i.e. slow pointer.
3. Check the palindrome with left and right pointer.
*/