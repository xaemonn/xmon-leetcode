class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         int top=n;
         int right=0;
         int left=m;
         int bottom=0;

         for(int i=0; i<n ;i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]==1){
                    top=min(top,i);
                    left=min(left,j);
                    right=max(right,j);
                    bottom=max(bottom,i);
                }
            }
         }  

         int hor=(right-left+1);
         int ver=(bottom-top+1);
         return hor*ver; 
    }
};