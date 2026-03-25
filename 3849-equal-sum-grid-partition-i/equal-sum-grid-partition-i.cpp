class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long total=0;
        for(int i=0; i<n ;i++){
            for(int j=0;j<m ;j++){
                total+=grid[i][j];
            }
         }
         long long curr=0;
         for(int i=0; i<n;i++){
            for(int j=0;j<m ;j++){
                curr+=grid[i][j];
            }
            long long rem=total-curr;
            if(curr==rem){
                return true;
            }
         }
          curr=0;
         for(int j=0; j<m ;j++){
            for(int i=0;i<n ;i++){
                curr+=grid[i][j];
            }
            long long rem=total-curr;
            if(curr==rem){
                return true;
            }
         }

         return false;
    }
};