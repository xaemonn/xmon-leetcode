class Solution {
public:
    typedef long long ll;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        ll sum=0;
        ll neg=0;
        ll mini=INT_MAX;
        bool zero=false;
        for(int i=0; i<n ;i++){
            for(int j=0; j<m ;j++){
                if(matrix[i][j]<0){
                    
                    neg++;
                }
                if(matrix[i][j]==0){
                    zero=true;
                }
                mini=min(abs((ll)matrix[i][j]),mini);
                sum+=abs(matrix[i][j]);
            }
        }

        if(neg%2!=0 && !zero){
            sum-=2*mini;
        }
        return sum;
    }
};