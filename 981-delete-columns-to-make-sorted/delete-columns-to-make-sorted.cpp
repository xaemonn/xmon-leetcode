class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int ans=0;
        for(int i=0; i<m; i++){
            bool ok=true;
            for(int j=1; j<n ;j++){
                if(strs[j-1][i]<=strs[j][i]){

                }else{
                    ok=false;break;
                }
            }
            if(!ok){
                ans++;
            }
        }

        return ans;
    }
};