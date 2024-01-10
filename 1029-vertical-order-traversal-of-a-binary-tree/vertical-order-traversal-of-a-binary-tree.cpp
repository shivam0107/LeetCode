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

    void inorder(TreeNode* root , pair<int , int> &p , map<int , map<int , multiset<int>>> &nodes , vector<vector<int>> &ans){
        if(root == NULL) return;

        int x = p.first , y= p.second;
        p = {x-1 , y+1};
        if(root->left) inorder(root->left , p , nodes , ans);
        nodes[x][y].insert(root->val);
        p = {x+1 , y+1};
        if(root->right) inorder(root->right , p , nodes , ans);    

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>> nodes;
        vector<vector<int>> ans;

        pair<int , int> p;
        p =  {0 , 0};

        inorder(root , p , nodes , ans);

        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end() ,  q.second.begin() , q.second.end());
            }

            ans.push_back(col);
        }

        // queue<pair<TreeNode* , pair<int , int>>> q;
        // q.push({root , {0 , 0}});

        // while(!q.empty()){
        //     auto p = q.front();
        //     q.pop();
        //     TreeNode* temp = p.first;
            
        //     int x = p.second.first;
        //     int y = p.second.second;

        //     nodes[x][y].insert(temp->val);
        //     if(temp->left){
        //         q.push({temp->left , {x-1 , y+1}});
        //     }
           
        //     if(temp->right){
        //         q.push({temp->right , {x+1 , y+1}});
        //     }


        // }

        // for(auto i : nodes){
        //     vector<int> col;
        //     for(auto p : i.second){
        //         col.insert(col.end() , p.second.begin() , p.second.end());
        //     }
        //     ans.push_back(col);
        // }

        return ans;

    }
};