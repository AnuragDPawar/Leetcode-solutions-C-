#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){};
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode* next): val(x),next(next) {};
};

class Solution{
    public: 
    void insert(ListNode** head, int x)
    {
        cout<<"Insersion started";
        ListNode* temp=new ListNode(x);
        ListNode* ptr = nullptr;
        temp->next=nullptr;
        if(!*head) *head=temp;
        else
        {   ptr=*head;
            while (ptr->next) ptr=ptr->next;
            ptr->next=temp;
        }        
    }
    void display(ListNode** head)
    {
        ListNode* temp=*head;
        while(temp)
        {
            cout<<temp->val<<endl;
            temp=temp->next;
        }
    }
    ListNode* removeNthfromEnd(ListNode** head, int n)
    {
        if(!*head) return *head;
        ListNode* dummy = new ListNode(0);
        dummy->next=*head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i=0;i<n;i++) // to maintain the distance of n from slow node
        {
            fast=fast->next;
        }
        while(fast->next!=NULL) //while this loop will end then slow will be at length-n-1 position
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return dummy->next;
    }
};

int main()
{
    Solution sa;
    vector<int> s {1,2,3,4,5,6};
    ListNode* head=nullptr;
    for(int i=0;i<s.size();i++)
    {
        sa.insert(&head, s[i]);
    }
    cout<<"Original list:";
    sa.display(&head);
    ListNode* temp;
    temp=sa.removeNthfromEnd(&head,2);
    cout<<"\nDeleted list:";
    sa.display(&temp);
    return 0;
}