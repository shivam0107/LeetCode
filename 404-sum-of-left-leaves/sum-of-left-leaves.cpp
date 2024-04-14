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

    bool isLeaf(TreeNode* node){
        if(node->left == NULL && node->right == NULL){
            return true;
        }


        return false;
    }

    int getSum(int &sum , TreeNode* &root){
        if(root == NULL) return 0;

        if(root->left && isLeaf(root->left)){
            sum += root->left->val;
        }
        if(root->left){
            getSum(sum , root->left);

        }

        if(root->right){
            getSum(sum , root->right);
        }

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;

        return getSum(sum , root);
    }
};