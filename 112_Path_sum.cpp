 #include <bits/stdc++.h>
 using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

  bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return false; 
        else if(root->val==targetSum && !root->left && !root->right) return true; //leaf node case
        else
        {   
            int newTarget=targetSum-root->val;
            return hasPathSum(root->left,newTarget) || hasPathSum(root->right,newTarget); //checking in both directions
        }
    }

int main()
{
    TreeNode *root;
    root->val=5;
    hasPathSum(root,4);
    return 0;
}