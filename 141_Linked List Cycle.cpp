#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){};
    ListNode(int x): val(x),next(nullptr){};
    ListNode(int x, ListNode* next): val(x), next(next){};
};
class Solution{
    public:
        bool isCycle(ListNode** head)
        {
            ListNode *slow,*fast;
            slow=*head;
            fast=*head;
            while(fast!=NULL && fast->next!=NULL)
            {
                slow=slow->next;
                fast=fast->next->next;
                if(fast==slow) return true;
            }
            return false;
        }
};

int main()
{
    Solution sa;
    ListNode *head;
    head->val=5;
    bool res=sa.isCycle(&head);
    cout<<res;
    return 0;
}