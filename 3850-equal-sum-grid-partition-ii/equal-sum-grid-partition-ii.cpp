class Solution {
public:
   typedef long long ll;
   
    bool check(vector<vector<int>>& grid, ll& total){
        int n=grid.size();
        int m=grid[0].size();
        set<ll> st;
        ll upper=0;

        for(int i=0; i<n ;i++){
            for(int j=0; j<m ;j++){
                upper+=grid[i][j];
                st.insert(grid[i][j]);
            }
            ll lower=total-upper;
            if(i==0){
                if(upper==lower){
                    return true;
                }else{
                    if(upper>lower){
                        ll req=upper-lower;
                        if(grid[0][0]==req || grid[0][m-1]==req){
                            return true;
                        }
                    }
                }
            }
            if(i>=1){
                if(upper==lower){
                    return true;
                }else{
                    if(upper>lower){
                        ll req=upper-lower;
                        if(st.find(req)!=st.end()){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool checkforone(vector<vector<int>>& grid){

         int n=grid.size();
        int m=grid[0].size();

     
          ll total=0;
          for(int i=0; i<m ;i++){
            total+=grid[0][i];
          }
         
        ll curr=0;
        set<ll> st;
        for(int j=0; j<m ;j++){
            curr+=grid[0][j];
            ll rem=total-curr;
            if(curr==rem){
                return true;
            }else {
                if(curr>rem){
                   ll req=curr-rem;
                   if(j>=0){
                    if(grid[0][j]==req || grid[0][0]==req){
                        return true;
                    }
                   }
                }
            }
        }
         
         curr=0;
        for(int j=m-1; j>=0 ;j--){
            curr+=grid[0][j];
            ll rem=total-curr;
            if(curr==rem){
                return true;
            }else {
                if(curr>rem){
                   ll req=curr-rem;
                   if(j<=m-1){
                    if(grid[0][j]==req || grid[0][m-1]==req){
                        return true;
                    }
                   }
                }
            }
        }
        return false;
      
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

     

        if(n==1){
            return checkforone(grid);
        }else if(m==1){
            vector<vector<int>> temp(1,vector<int>(n,0));
            for(int i=0; i<n; i++){
                temp[0][i]=grid[i][0];
            }
            return checkforone(temp);
        }

        vector<vector<int>> grid1(n,vector<int>(m,0)), grid2(m,vector<int>(n,0)), 
        grid3(m,vector<int>(n,0));
        
       ll total=0;
        for(int i=0; i<n ;i++){
            for(int j=0; j<m ;j++){
                grid1[n-i-1][m-j-1]=grid[i][j];
                total+=grid[i][j];
            }
        }

       

        for(int i=0; i<n ;i++){
            for(int j=0; j<m ;j++){
                grid2[j][i]=grid[i][j];
            }
        }

        for(int i=0; i<m;i++){
            for(int j=0; j<n ;j++){
                grid3[m-i-1][n-j-1]=grid2[i][j];
            }
        }

        
        
      
         return (check(grid,total) || check(grid1,total) || check(grid2,total) || check(grid3,total));
    }
};