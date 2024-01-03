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

     void preorder(TreeNode *root , vector<int> &nums){
     if(root == NULL){
         return;
     }
     
     nums.push_back(root->val);

     preorder(root->left, nums);
     preorder(root->right,nums);

 }

 void iterativePreorder(TreeNode *root , vector<int> &nums){
    stack<TreeNode*> st;

    st.push(root);

    while(!st.empty()){
        TreeNode* temp = st.top();
        st.pop();

        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);
        nums.push_back(temp->val);
    }

 }


    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        iterativePreorder(root , ans);

        return ans;
    }
};