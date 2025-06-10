class Solution {
public:
    //small r (items to choose)
    int choose(int n , int r){
        if(r>n-r){
            r=n-r;
        }
        long long res=1;
        for(int i=1; i<=r;i++){
            res*=(n-i+1);
            res=res/i;
        }

        return res;
    }
    int uniquePaths(int m, int n) {
        return choose(n+m-2, n-1);
    }
};