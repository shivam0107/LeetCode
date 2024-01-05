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

    int dfsHeight(TreeNode* root){
        if(root == NULL) return 0;

        int lh = dfsHeight(root->left);
        if(lh == -1) return -1;
        int rh = dfsHeight(root->right);
        if(rh == -1) return -1;

        if(abs(rh-lh) > 1) return -1;

        return 1 + max(lh , rh);
    }

    int findH(TreeNode* root){
        if(root == NULL) return 0;

        int lh = findH(root->left);
        int rh = findH(root->right);


        return 1 + max(lh , rh);
    }

    bool isBalanced(TreeNode* root) {
        if(root  == NULL){
            return true;
        }

        return dfsHeight(root) != -1;

        //O(N) for traversal , //O(N) for finding height

        // int lh = findH(root->left);
        // int rh = findH(root->right);

        // if(abs(lh-rh) > 1) return false;

        // bool left = isBalanced(root->left);
        // bool right = isBalanced(root->right);

        // if(!left || !right) return false;

        // return true;

    }
};