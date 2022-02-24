#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next (nullptr){};
    ListNode(int x): val(x),next (nullptr){};
    ListNode(int x, ListNode* next): val(x), next (next){};
};

class Solution{
    public:
    ListNode* findMid(ListNode** head)
    {
        ListNode* fast=*head;
        ListNode* slow=*head;
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    void createLL(int x, ListNode** head)
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
};

int main()
{
    Solution sa;
    vector<int> s {1,2,3,4,5,6};
    ListNode* head=nullptr;
    for(int i=0;i<s.size();i++)
    {
        sa.createLL(s[i], &head);
        cout<<"Inserting "<<s[i];
    }
    cout<<"\nOriginal LL:\n";
    sa.print(&head);
    ListNode* res=sa.findMid(&head);
    cout<<"\nLL from mid:\n";
    sa.print(&res);
    return 0;
}

//Time complexity: O(n) where n= number of nodes in LL