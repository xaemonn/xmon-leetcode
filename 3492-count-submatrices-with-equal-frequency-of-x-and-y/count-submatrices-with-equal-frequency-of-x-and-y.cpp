class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> sumx(n,vector<int>(m,0)), sumy(n,vector<int>(m,0));

        for(int i=0; i<n ;i++){
            for(int j=0; j<m ;j++){
                int x=0;
                int y=0;
                if(grid[i][j]=='X'){
                    x=1;
                }
                if(grid[i][j]=='Y'){
                    y=1;
                }

                sumx[i][j]+=x;
                sumy[i][j]+=y;
                if(i>0){
                    sumx[i][j]+=sumx[i-1][j];
                    sumy[i][j]+=sumy[i-1][j];
                }
                if(j>0){
                    sumx[i][j]+=sumx[i][j-1];
                    sumy[i][j]+=sumy[i][j-1];
                }
                if(i>0 && j>0){
                    sumx[i][j]-=sumx[i-1][j-1];
                     sumy[i][j]-=sumy[i-1][j-1];
                }
            }
        }

        int ans=0;
        for(int i=0; i<n ;i++){
            for(int j=0; j<m ; j++){
                if(sumx[i][j]>0 && sumy[i][j]>0 && sumx[i][j]==sumy[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};