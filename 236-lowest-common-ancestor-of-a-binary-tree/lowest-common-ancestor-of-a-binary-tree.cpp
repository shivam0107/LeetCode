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


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> v1 , v2;
        getPath(root , v1 , p);
        getPath(root , v2 , q);

        TreeNode* node = NULL;

        for(auto i : v1){
            cout<<i->val<<" ";
        }

cout<<endl;
        for(auto i : v2){
            cout<<i->val<<" ";
        }

        int n = v1.size();
        int m = v2.size();
        n = min(n , m);

        for(int i = 0; i<n; i++ ){
            if(v1[i] == v2[i]){
              node = v1[i];
            }
            else{
                break;
            }
        }

        return node;
    }
};