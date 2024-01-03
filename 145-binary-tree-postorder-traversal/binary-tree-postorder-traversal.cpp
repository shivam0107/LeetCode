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

    void postorder(TreeNode *root , vector<int> &nums){
     if(root == NULL){
         return;
     }
     postorder(root->left, nums);
     postorder(root->right,nums);
     nums.push_back(root->val);

 }

 
    void IterativePostorder(TreeNode *root , vector<int> &nums){
     stack<TreeNode*> st1 ; 
     stack<int> st2;

     st1.push(root);
     while(!st1.empty()){
         TreeNode* temp = st1.top();
         st2.push(temp->val);
         st1.pop();

         if(temp->left != NULL) st1.push(temp->left);
         if(temp->right != NULL) st1.push(temp->right);
     }

     while(!st2.empty()){
         nums.push_back(st2.top());
         st2.pop();
     }
 }



    vector<int> postorderTraversal(TreeNode* root) {
         vector<int> ans;
         if(root == NULL) return ans;

        IterativePostorder(root , ans);

        return ans;
    }
};