# include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(): val(0), next (nullptr) {};
    ListNode(int x): val(x), next(nullptr){};
    ListNode(int x, ListNode *next): val(x), next(next){};
};

class Solution{
    public:
     void insert(int x, ListNode** head)
    {
        ListNode* temp=new ListNode;
        ListNode* ptr = nullptr;
        temp->val=x;
        temp->next=nullptr;
        if(!*head) *head=temp;
        else
        {
            ptr= *head;
            while(ptr->next) ptr=ptr->next;
            ptr->next=temp;
        }
    }
    ListNode* reverse(ListNode** head)
    {
        ListNode* prev=nullptr;
        ListNode* curr=*head; //storing head into a temp node
        while (curr)
        {
            ListNode* temp=curr->next; //stored current's next into a temp node.
            curr->next=prev; 
            prev=curr;
            curr=temp;
        }
        return prev;       

    }
    void display(ListNode** head)
    {
        ListNode* temp= *head;
        while(temp)
        {
            cout<<temp->val<<endl;
            temp=temp->next;
        }
    }

};

int main()
{
    Solution sa;
    vector<int> s {1,2,3,4,5,6};
    ListNode *head=nullptr;
    for(int i=0;i<s.size();i++)
    {
        sa.insert(s[i], &head);
    }
    ListNode* temp= sa.reverse(&head);
    sa.display(&temp);
    return 0;
}