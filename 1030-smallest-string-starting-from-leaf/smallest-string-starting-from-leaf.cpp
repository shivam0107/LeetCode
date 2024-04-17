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

    void stRev(string &temp){
        int i = 0;
        int j = temp.length();

        while(i <= j ){
            swap(temp[i] , temp[j]);
            i++;
            j--;
        }
    }

    void getSmallest(string &ans , string temp , TreeNode* root){

        if(root == NULL) return;

        temp += char('a'+root->val);

        if(root->left == NULL && root->right == NULL){
            reverse(temp.begin(), temp.end());
            if (ans.empty() || temp < ans) {
                ans = temp;
            }

           reverse(temp.begin(), temp.end());
        }
         
        getSmallest(ans , temp, root->left );    
        getSmallest(ans , temp, root->right );
    }

    string smallestFromLeaf(TreeNode* root) {
        string ans;

        getSmallest(ans , "" , root);

         return ans;
    }
};