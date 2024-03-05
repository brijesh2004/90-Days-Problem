class Solution {
public:
    int ans = 0;
    void left(TreeNode* root , unordered_map<int , int>& leftCnt , int cnt){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            leftCnt[cnt]++;
            return ;
        }

        left(root->left , leftCnt , cnt+1);
        left(root->right , leftCnt, cnt+1);
    }
     void right(TreeNode* root , unordered_map<int , int>& rightCnt , int cnt){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            rightCnt[cnt]++;
            return ;
        }

        right(root->left , rightCnt , cnt+1);
        right(root->right , rightCnt, cnt+1);
    }

    void solve(TreeNode* root , int k){
        if(root==NULL){
            return ;
        }
        unordered_map<int , int>leftCnt , rightCnt;
        left(root->left , leftCnt , 1);
        right(root->right , rightCnt , 1);
       for(auto it:leftCnt){
           for(auto it1:rightCnt){
               if(it1.first+it.first<=k){
                   ans = ans + it.second*it1.second;
               }
           }
       }
       solve(root->left , k);
       solve(root->right ,k);
    }

    void treetoGrp(TreeNode* root , unordered_map<int , vector<int>>&adj ,unordered_map<int , int>&leaf){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            leaf[root->val]++;
        }
        if(root->left!=NULL){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
         if(root->right!=NULL){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        treetoGrp(root->left , adj, leaf);
        treetoGrp(root->right , adj , leaf);
    }
//   int ans = 0;
    void dfs(int node , int cnt , unordered_map<int , vector<int>>&adj, unordered_map<int ,int>&vis
    ,unordered_map<int , int>&leaf , int k){
        vis[node] =1;
        if(cnt>k){
            return;
        }
        if(leaf[node]&&cnt>0){
            ans++;
        }
          for(auto it: adj[node]){
              if(!vis[it]){
                  dfs(it , cnt+1 , adj , vis , leaf , k);
              }
          }
        
    }
    int countPairs(TreeNode* root, int distance) {

        // iterative method

        //  solve(root , distance);
        //  return ans;

        // convert tree into graph
        unordered_map<int , vector<int>>adj;
        unordered_map<int , int>leaf;
        treetoGrp(root , adj , leaf);
        
        for(auto it: leaf){
             unordered_map<int , int>vis;
            dfs(it.first , 0 , adj , vis , leaf , distance);
        }
         return ans/2;
    }
};