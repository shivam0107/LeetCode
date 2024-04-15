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

      int getSum(int &sum , int n , TreeNode* &root)  {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL){
            sum += n;
        }
        if(root->left){
            n = n*10 + root->left->val;
            getSum(sum , n, root->left);
        }
        
        if(root->right){
            if(root->left != NULL)  n = n/10;
            n = n*10 + root->right->val;         
            getSum(sum , n, root->right);
        }
        return 0;
        
      }


    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int n = root->val;
        int sum = 0;

         getSum(sum , n , root);
         return sum;
    }
};