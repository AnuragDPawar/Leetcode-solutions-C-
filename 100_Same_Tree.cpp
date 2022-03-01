#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr),right(nullptr){};
    TreeNode(int x): val(x),left(nullptr),right(nullptr){};
    TreeNode(int x,TreeNode *left,TreeNode *right): val(x),left(left),right(right){};
};

class Solutions{
    public:
    bool isSameTree(TreeNode **p, TreeNode **q)
    {
        TreeNode *node1= *p;
        TreeNode *node2= *q;
        if(!node1 || !node2) return false; //if one of the child is absent
        if(!node1 && !node2) return true; //if both children are absent (leaf node)
        //recursively calling same function for the value and their both children
        return node1->val == node2->val && isSameTree(&node1->left,&node2->left) && isSameTree(&node1->right,&node2->right);     
    }
};

int main()
{
    Solutions sa;
    //Tree 1 for testing
    TreeNode *head1=new TreeNode(5);
    TreeNode *child11=new TreeNode(4);
    TreeNode *child12=new TreeNode(3);
    head1->left=child11;
    head1->right=child12;
    //Tree 2 for testing
    TreeNode *head2=new TreeNode(5);
    TreeNode *child21=new TreeNode(4);
    TreeNode *child22=new TreeNode(3);
    head2->left=child21;
    head2->right=child22;
    cout<<sa.isSameTree(&head1,&head2);
    return 0;
}

//time complexity O(n) 