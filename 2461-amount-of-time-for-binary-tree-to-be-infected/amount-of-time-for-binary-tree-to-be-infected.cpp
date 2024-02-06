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

 void markParent(TreeNode* root ,unordered_map<TreeNode* , TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            if(current->left) {
                q.push(current->left);
                parent_track[current->left] = current;
            }

            if(current->right){
                q.push(current->right);
                parent_track[current->right] = current;
            }
        }
    }


    TreeNode* findNode(TreeNode* root , int start){

            queue<TreeNode*> q;
            q.push(root);
            TreeNode* startNode = NULL;

            while(!q.empty()){
                TreeNode* curr = q.front(); q.pop();

                if(curr->val == start){
                    startNode = curr;
                }

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            return startNode;

    }

    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode* , TreeNode*> parent_track;
        markParent(root , parent_track);

       TreeNode* startNode =  findNode(root , start);
       cout<<startNode->val<<endl;

        unordered_map<TreeNode* , bool> visited;

        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;
        int time = 0;

        while(!q.empty()){
              int size = q.size();
              int f =  0;

            for(int i = 0; i<size; i++){
                TreeNode* current = q.front(); q.pop();

                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                    f = 1;
                }
                
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                    f = 1;
                }

                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                    f = 1;
                }

               

            }
             if(f == 1)  time++;

            
        }

        return time;
    }
};