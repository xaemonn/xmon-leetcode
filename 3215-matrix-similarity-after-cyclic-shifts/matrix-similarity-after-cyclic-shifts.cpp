class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> neww(n,vector<int>(m,0));
        for(int i=0; i<n ;i++){
            for(int j=0; j<m ;j++){
                if(i%2){
                    //odd->right
                    int steps=k%m;
                    neww[i][j]=mat[i][(j+steps+m)%m];
                }else{
                    //even->left
                    int steps=k%m;
                    neww[i][j]=mat[i][(j-steps+m)%m];
                }
            }
        }

        if(mat==neww){
            return true;
        }
        return false;
    }
};