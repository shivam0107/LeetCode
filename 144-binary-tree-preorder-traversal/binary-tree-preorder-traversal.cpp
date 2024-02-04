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

     void preorder(TreeNode *root , vector<int> &nums){
     if(root == NULL){
         return;
     }
     
     nums.push_back(root->val);

     preorder(root->left, nums);
     preorder(root->right,nums);

 }

 void iterativePreorder(TreeNode *root , vector<int> &nums){
    stack<TreeNode*> st;

    st.push(root);

    while(!st.empty()){
        TreeNode* temp = st.top();
        st.pop();

        if(temp->right != NULL) st.push(temp->right);
        if(temp->left != NULL) st.push(temp->left);
        nums.push_back(temp->val);
    }

    
 }

  TreeNode* find(TreeNode* curr){
        TreeNode* pred = curr->left;

        while(pred->right != NULL && pred->right != curr){
            pred = pred->right;
        }

        return pred;
    }

    void morrisTraversal(TreeNode* root , vector<int> &nums){
        TreeNode* curr = root;
        while(curr != NULL){
           
            if(curr->left == NULL){
                 nums.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* pred = find(curr);
                if(pred->right == NULL){
                    pred->right = curr;
                     nums.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                      
                    pred->right = NULL;
                   
                    curr = curr->right;
                  
                }

            }
        }
    }




    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;

        morrisTraversal(root , ans);

        return ans;
    }
};