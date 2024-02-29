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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        int l = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ans;

            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                ans.push_back(node->val);
            }

       
                for(int i = 0; i<ans.size(); i++){
                  if(l%2 == 0){

                        if(ans[i]%2 == 0){
                            cout<<"1"<<endl;
                             return false;
                        }
                    
                        if(i+1 < ans.size() && ans[i] >= ans[i+1] ){
                            cout<<"2"<<endl;

                            return false;
                        }
                  }
                   else{
                        if(ans[i]%2 == 1){
                            cout<<"3"<<endl;

                             return false;
                        }
                    
                        if(i+1 < ans.size() && ans[i+1] >= ans[i] ){
                            cout<<"4"<<endl;

                            return false;
                        }
                    }
                }
                cout<<"l"<<l<<endl;
          l++;
          
        }

        return true;
    }
};