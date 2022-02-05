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

 vector<vector<int>> res;
    void isSum(TreeNode* root, int sum,vector<int>curr)
    {
        if(!root) return;
        curr.push_back(root->val);
        if((sum-root->val)==0 && !root->left && !root->right) //checking if we reached leaf node with sum
        {
            res.push_back(curr); //pushing current vector into main result vector
            return;
        }
        isSum(root->left,sum-root->val,vector<int>(curr)); 
        isSum(root->right,sum-root->val,vector<int>(curr));
        //curr.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {                
        isSum(root,sum,{});
        return res;
    }

    int main()
    {
        TreeNode* root;
        root->val=5;
        pathSum(root,10);
        return 0;
    }

/*
Algorithm
1. Strategy: DFS + recursion
2. Call recursive function
3. Check if root is NULL (base case 1)
4. Check if root is leaf and we have reached the desired sum (Base case 2) if yes then push the current vector into res.
5. Call same function for left and right subtree with reduced sum.
*/