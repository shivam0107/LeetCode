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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
         queue<TreeNode *> q;

            if (root == NULL)
                return ans;
    
             q.push(root);

              int z = 1;
        int f = 0;

        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();

          
            for (int i = 0; i < size; i++)
                {
                    TreeNode *temp = q.front();
                    q.pop();
                    if (temp->left != NULL)
                        q.push(temp->left);
                    if (temp->right != NULL)
                        q.push(temp->right);
                    level.push_back(temp->val);
                }
               

           
            if(f  == 0){
             ans.push_back(level);
             f = 1;

            }else{
                reverse(level.begin() , level.end());
                ans.push_back(level);
                f = 0;
            }

            
        }

        return ans;

    }
};