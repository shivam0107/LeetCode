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
   int maxi =INT_MIN;
    void findmax(TreeNode* par , TreeNode* child){
       if(par == NULL || child == NULL) return;

       int diff = par->val - child->val;
       maxi = max(maxi , abs(diff));
       findmax(par , child->left);
       findmax(par , child->right);
    }


    int maxAncestorDiff(TreeNode* root) {
       

       if(root == NULL) return 0;
       findmax(root , root->left);
       findmax(root , root->right);

       maxAncestorDiff(root->left);
       maxAncestorDiff(root->right);

       

        return maxi;

    }
};