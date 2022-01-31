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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> Q;
        vector<vector<int>> res;
        if(root==NULL) return res;
        Q.push(root);
        while(!Q.empty())
        {
            int n=Q.size();
            vector<int> vec(n); //creating temp vector for nth level
           
            for(int i=0;i<n;i++)
            {   
                 TreeNode* temp=Q.front();
                 Q.pop();
                vec[i]=temp->val; //adding values
                if(temp->left) Q.push(temp->left);              
                if(temp->right) Q.push(temp->right);
                
            }
            if(!vec.empty()) res.push_back(vec); //pushing temp vector into result vector
        }

        reverse(res.begin(),res.end());
        return res;        
    }

int main()
{   
    TreeNode* root;
    root->val=5;
    return 0;
}

/*
Algorithm
1. Traverse the tree with BFS mechanism.
2. While poping the elemets from the queue add them to the temporary vector.
3. Add the temporary vector to the final result vector.
4. Reverse the result vector and return it.
*/