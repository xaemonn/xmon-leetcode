class Solution {
public:

   void recur(int row,int col, vector<vector<int>>& grid, char dir){
    if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]==2 || grid[row][col]==-2){
        return;
    }
    grid[row][col]=1;

    if(dir=='u') {recur(row-1, col,grid,'u');}
    if(dir=='d') {recur(row+1, col,grid,'d');}
    if(dir=='l') {recur(row, col-1,grid,'l');}
    if(dir=='r') {recur(row, col+1,grid,'r');}
   }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
         vector<vector<int>> grid(m,vector<int>(n,0));

         for(int i=0; i<guards.size(); i++){
            int r=guards[i][0];
            int c=guards[i][1];
            grid[r][c]=2;
         }
         for(int i=0; i<walls.size(); i++){
            int r=walls[i][0];
            int c=walls[i][1];
            grid[r][c]=-2;
         }

         for(auto it:guards){
            int r=it[0];
            int c=it[1];
            recur(r-1,c,grid,'u');
            recur(r+1,c,grid,'d');
            recur(r,c-1,grid,'l');
            recur(r,c+1,grid,'r');
         }
         int ans=0;
         for(int i=0; i<m ;i++){
            for(int j=0; j<n ;j++){
                 if(grid[i][j]==0){
                    ans++;
                 }
            }
         }

         return ans;
    }
};