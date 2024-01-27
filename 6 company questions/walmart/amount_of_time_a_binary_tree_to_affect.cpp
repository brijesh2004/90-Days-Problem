// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/submissions/1142230646/?envType=daily-question&envId=2024-01-10


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
    void solve(TreeNode * root, unordered_map<int , vector<int>>&adj, int parent){
        if(root==NULL){
            return ;
        }
       if(root->left!=NULL){
           adj[root->val].push_back(root->left->val);
       }
       if(root->right!=NULL){
           adj[root->val].push_back(root->right->val);
       }
       if(parent!=-1)
        adj[root->val].push_back(parent);
      solve(root->left , adj , root->val);
      solve(root->right , adj , root->val);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int , vector<int>>adj;
        solve(root , adj , -1);
        // for(auto it : adj){
        //     cout<<it.first<<" ";
        //     for(auto t:it.second){
        //         cout<<t<<" ";
        //     }
        //     cout<<endl;
        // }

        unordered_map<int ,bool>vis;
        queue<pair<int ,int>>q;
        
        q.push({start , 0});
        vis[start] = true;
        int ans = 0;
        while(!q.empty()){
            int val = q.front().first;
            int time = q.front().second;
            q.pop();
            ans = time;
           for(auto it : adj[val]){
               if(vis[it]!=true){
                   q.push({it , time+1});
                   vis[it] = true;
               }
           }
        }

   return ans;
    }
};