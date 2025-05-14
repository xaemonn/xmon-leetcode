class Solution {
public:
    const int mod = 1e9 + 7;
    //matrix multiplication code
   vector<vector<int>> multiply(vector<vector<int>>&a , vector<vector<int>>& b){

     int n1=a.size();
     int m1=a[0].size();
     int m2=b[0].size();
     
     vector<vector<int>> ans(n1,vector<int>(m2,0));
     
     for(int i=0; i<n1;i++){
        for(int j=0; j<m2;j++){
           for(int k=0; k<m1; k++){
            ans[i][j]=(ans[i][j]+ 1LL* a[i][k]* b[k][j])%mod;
           }
        }
     }
     return ans;
   }

   //matrix exponentiation code

    vector<vector<int>> expo(vector<vector<int>>& grid,int t){
         vector<vector<int>> res(26,vector<int>(26,0));
         for(int i=0; i<26;i++){
            res[i][i]=1; //identity
         }

         while(t>0){
            if(t%2){
                res=multiply(res,grid);
            }
            grid=multiply(grid,grid);
            t=t/2;
         }

         return res;
    }
    


    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> freq(26,0);
        for(auto ch:s){
            freq[ch-'a']++;
        }

        vector<vector<int>> grid(26,vector<int>(26,0));
        for(int i=0; i<26;i++){
            int num=nums[i];
            for(int j=1; j<=num;j++){
                int next=(i+j)%26;
                grid[i][next]++;
            }
        }

        vector<vector<int>> trans=expo(grid,t);

        vector<int> final(26,0);

        for(int j=0; j<26; j++){
            for(int i=0; i<26;i++){
                final[j]=(final[j]+1LL*freq[i]*trans[i][j])%mod;
            }
        }


        int ans=0;
        for(auto i:final){
            ans=(ans+i)%mod;
        }

        return ans;

    }
};