class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
       int n=grid.size();
       int m=grid[0].size();

       int start=x;
       int end=x+k-1;

       while(start<=end){
        for(int j=y; j<y+k; j ++){
            swap(grid[start][j], grid[end][j]);
        }
        start++;
        end--;
       }

       return grid;
    }
};