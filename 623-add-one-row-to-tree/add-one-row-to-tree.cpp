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

    TreeNode* getNode(int depth ,int val , TreeNode* &root){

        if(root == NULL) return NULL;
        queue<TreeNode*> q;

        depth = depth-1;

        q.push(root);
        while(!q.empty()){
           
            int size = q.size();
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(depth == 0){

                    if(node->left == NULL){
                        TreeNode* newNode = new TreeNode(val);
                        node->left = newNode;
                    }
                    else{
                         TreeNode* mostleft = node->left;
                         TreeNode* newNode = new TreeNode(val);
                         node->left = newNode;
                         newNode->left = mostleft;
                    }
                    
                     if(node->right == NULL){
                         TreeNode* newNode = new TreeNode(val);
                         node->right = newNode;
                    }
                    else{  
                         TreeNode* mostright = node->right;
                         TreeNode* newNode = new TreeNode(val);
                         node->right = newNode;
                         newNode->right = mostright;
                    }


                        
                }

                if(node->left){
                    q.push(node->left);

                }
                if(node->right){
                    q.push(node->right);
                }

               
               
            }
             depth--;
        }

           return NULL; 
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
         if(root == NULL) return NULL;
         if(depth == 1){
           
           TreeNode* newNode = new TreeNode(val);
           newNode->left = root;

           return newNode;
           

         }
         
         getNode(depth-1 , val ,  root);

      
        return root;
    }
};