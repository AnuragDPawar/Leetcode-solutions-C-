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

  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> Q;
        vector<vector<int>> res;
        if(root==NULL) return res;
        bool reverse=true; //to change from left to right or right to left 
        Q.push_front(root);
        while(!Q.empty())
        {
            int n=Q.size();
            vector<int> vec; //creating temp vector for nth level
            deque<TreeNode*> dQ; //using this to strore elements from front as we need to switch the side 
            for(int i=0;i<n;i++)
            {   
                 TreeNode* temp=Q.front();
                 Q.pop_front();
                vec.push_back(temp->val); //adding values
                if(reverse)
                {
                    if(temp->left) dQ.push_front(temp->left);
                    if(temp->right) dQ.push_front(temp->right);
                }
                else
                {
                    if(temp->right) dQ.push_front(temp->right);
                    if(temp->left) dQ.push_front(temp->left);
                }                

            }
            Q.insert(Q.end(),dQ.begin(),dQ.end());
            reverse=!reverse; //togling 
            if(!vec.empty()) res.push_back(vec); //pushing temp vector into result vector
        }
        
        return res;    
    }
  
    int main()
    {
        TreeNode* root;
        root->val=5;
        zigzagLevelOrder(root);
        return 0;
    }