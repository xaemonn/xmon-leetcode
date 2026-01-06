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
    typedef long long ll;

    void recur(TreeNode* root,vector<ll>& v, ll lvl,vector<bool>& used){
        if(!root) return;
        
        v[lvl]+=root->val;
        used[lvl]=true;
        recur(root->left, v, lvl+1,used);
        recur(root->right,v,lvl+1,used);

    }
    int maxLevelSum(TreeNode* root) {
        vector<ll> v(10001,0);
        vector<bool> used(10001,false);
        recur(root,v,1,used);

        ll maxx=INT_MIN;
        ll lvl=-1;
        for(ll i=0; i<v.size(); i++){
            if(used[i] && v[i]>maxx){
                lvl=i;
                maxx=v[i];
            }
        }

        return lvl;

    }
};