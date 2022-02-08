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

  int pathSum_a(TreeNode* root, int sum)
    {
        if(!root) return 0;
        int res=0;
        if(root->val==sum) res++; //if current node has the value ==sum
        res+=pathSum_a(root->left,sum-root->val); //if not then searching left tree with reduced sum and adding into res
        res+=pathSum_a(root->right,sum-root->val); //if not then searching left tree with reduced sum and adding into res
        return res;        
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int ans=pathSum(root->left,sum) //recursive call for excluding the root and left subtree
            +pathSum(root->right,sum) //recursive call for excluding the root and right subtree
            +pathSum_a(root,sum); //recursive call for including the root
        return ans;
    }
int main()
{
    TreeNode* root;
    root->val=5;
    pathSum(root, 4);
    return 0;
}

/*
***ALGORITHM***
There are 2 cases: 1. Including root 2. Excluding root
1. Base case: if root is null ans will be 0
2. If the current node has the value==sum then increment res and go for further subtree.
3. All operations will be carried out by helper function and it will be called recursively by main function.
4. Main function will call itself for the 2nd case i.e. for left and right subtrees.
*/