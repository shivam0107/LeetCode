/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isLeaf(TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }

        return false;
    }
    //we can not do this this become complecated [1,2,3,4]
    void inorder(TreeNode* root , vector<int> &ans){
        if(root == NULL) return ;

        // if(isLeaf(root)) ans.push_back(root->val);

       if(root->right) {
           ans.push_back(root->val);
           inorder(root->right , ans);

       }
       else{
           ans.push_back(root->val);
           inorder(root->left , ans);
       }

    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int x = INT_MIN;
            int size = q.size();
            for(int i = 1; i<=size; i++){
                 TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);

                if(node->right) q.push(node->right);

                x = node->val;
            }
            ans.push_back(x);
        }

        return ans;
    }
};