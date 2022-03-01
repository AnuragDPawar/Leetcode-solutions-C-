#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0),left(nullptr),right(nullptr){};
    TreeNode(int x): val(x),left(nullptr),right(nullptr){};
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x),left(left),right(right){};
};

class Solutions{
    public:
    int maxDepth(TreeNode **root)
    {
        if(!*root) return 0;
        queue<TreeNode*> Q;
        Q.push(*root);
        int flag=0,n=0;
        while(!Q.empty())
        {
            int size=Q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=Q.front();
                Q.pop();
                if(temp->left)
                {
                    Q.push(temp->left);
                    flag=1;
                }
                if(temp->right)
                {
                    Q.push(temp->right);
                    flag=1;
                }
            }
            if(flag==1) n++;
            if(flag==0 && Q.empty()) n++;
            flag=0;
        }
        return n;
    }
};

int main()
{
    Solutions sa;
    //Tree 1 for testing
    TreeNode *head=new TreeNode(5);
    TreeNode *child1=new TreeNode(4);
    TreeNode *child2=new TreeNode(3);
    head->left=child1;
    head->right=child2;
    cout<<sa.maxDepth(&head); 
    return 0;
}
//Time Complexity O(n)
//Algorithm: Use simple BFS, one a level checked increase the count