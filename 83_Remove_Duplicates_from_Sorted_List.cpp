# include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(): val(0),next(nullptr) {};
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode* next): val(x),next(next){};
};

void insert(ListNode** head, int x)
{
    ListNode* temp = new ListNode;
    ListNode* ptr=NULL;
    temp->val=x;
    temp->next=nullptr;
    if(!*head) *head=temp;
    else 
    {
        ptr=*head;
        while(ptr->next) ptr=ptr->next;
        ptr->next=temp;
    }
}
void display(ListNode** head)
{
    ListNode* curr=*head;
    while(curr->next)
    {
        cout<<curr->val<<" ";
        curr=curr->next;
    }
}
ListNode* remove_duplicates(ListNode* head)
{
    ListNode* temp= head;
    while(temp)
    {
        while(temp->next && temp->val==temp->next->val)
        {
            temp->next=temp->next->next;
        }
        temp=temp->next;
    }
    return head;
}

int main()
{
    vector<int> v {1,1,2,3,4,5,6,6};
    ListNode* head=nullptr;
    for (size_t i = 0; i <= v.size(); i++)
    {
        insert(&head,v[i]);
    }
    remove_duplicates(head);
    display(&head);
    return 0;
}
