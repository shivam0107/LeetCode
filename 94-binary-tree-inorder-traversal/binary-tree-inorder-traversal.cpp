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

    void inorderTraversal(TreeNode* root , vector<int> &ans){
        if(root == NULL){
            return;
        }

        inorderTraversal(root->left , ans);
        ans.push_back(root->val);
        inorderTraversal(root->right , ans);

    }

    void iterativeInorder(TreeNode *root , vector<int> &nums){
     stack<TreeNode*> st;
    TreeNode* temp = root;
    // if(root == NULL)
    //     return ans;

    while (true)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            temp = st.top();
            st.pop();

            nums.push_back(temp->val);
            temp = temp->right;
        }
    }
  

 }

    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        if(root == NULL) return ans;
        iterativeInorder(root , ans);


        return ans;
    }
};