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
    
    int maxi = INT_MIN;
    int findH(TreeNode* root){
         if(root ==NULL) {
            return 0;
        }

        int lh = findH(root->left);
        int rh = findH(root->right);

        

        return max(lh , rh) + 1;
    }
    
    void findMax(TreeNode* root , int &maxi){
         if(root ==NULL) {
            return;
        }

        int lh = findH(root->left);
        int rh = findH(root->right);

         maxi = max(maxi , lh+rh);

        findMax(root->left , maxi);
        findMax(root->right , maxi);
        

    }

    int diameterOfBinaryTree(TreeNode* root) {
       int maxi = INT_MIN;
       findMax(root , maxi);
        return maxi;
    }
};