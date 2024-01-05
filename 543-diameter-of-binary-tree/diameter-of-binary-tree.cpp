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
    
  
    int findH(TreeNode* root){
         if(root ==NULL) {
            return 0;
        }

        int lh = findH(root->left);
        int rh = findH(root->right);

        

        return max(lh , rh) + 1;
    }
    
    int findMax(TreeNode* root , int &maxi){
         if(root ==NULL) {
            return 0;
        }

        // int lh = findH(root->left);
        // int rh = findH(root->right);


       int lh = findMax(root->left , maxi);
        int rh = findMax(root->right , maxi);

         maxi = max(maxi , lh+rh);

        
        return max(rh , lh)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
       int maxi = INT_MIN;
       //brute force O(n2)
       //O(n) - for traversing each node O(n) for getting height of each node
       findMax(root , maxi);
        return maxi;
    }
};