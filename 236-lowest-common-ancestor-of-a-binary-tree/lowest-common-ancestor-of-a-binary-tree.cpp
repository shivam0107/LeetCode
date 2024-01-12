/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root ,vector<TreeNode*> &nums , TreeNode* n ){
        if(!root) return false;

        nums.push_back(root);

        if(root == n){
            return true;
        }

        if(getPath(root->left , nums , n) || getPath(root->right , nums , n)){
            return true;
        }

        nums.pop_back();
        return false;
    }

    TreeNode* getNode(TreeNode* root , TreeNode* p, TreeNode* q , TreeNode* &node){
        if(!root) return NULL;

        if(root == p){
           node =  root;
           return node;
        }
        if(root == q) {
            node = root;
            return node;
        }

       TreeNode* left =  getNode(root->left , p , q , node);
       TreeNode* right = getNode(root->right , p , q , node);


        if(left && right){
            node = root;
        }
        else if(left){
            node = left;
        }
        else if(right){
            node = right;
        }
        else{
            return NULL;
        }

        return node;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // optimized solution
        TreeNode* node = NULL;
        getNode(root , p  , q , node);


        //brute force approach O(n) , O(2n) extra space
        
        // vector<TreeNode*> v1 , v2;
        // getPath(root , v1 , p);
        // getPath(root , v2 , q);

        // TreeNode* node = NULL;
        // int n = v1.size();
        // int m = v2.size();
        // n = min(n , m);

        // for(int i = 0; i<n; i++ ){
        //     if(v1[i] == v2[i]){
        //       node = v1[i];
        //     }
        //     else{
        //         break;
        //     }
        // }

        return node;
    }
};