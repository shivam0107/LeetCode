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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long ans = 0;
        queue<pair<TreeNode* , long long>> q;
        q.push({root , 0});

        while(!q.empty()){
              
            long long size = q.size();
            long long first , last;
            long long min = q.front().second;

           for(int j = 0; j<size; j++ ){
                long long i = q.front().second - min;
                TreeNode* node = q.front().first;
                q.pop();

                if(j == 0) first = i;
                if(j == size-1) last = i;

                if(node->left){
                    q.push({node->left , 2*i+1});
                 }
           
                 if(node->right){
                    q.push({node->right , 2*i+2});
                }

           }

            ans = max( ans , last-first + 1);          
        }

        return (int)ans;
        

         
    }
};