class Solution {
public:
   typedef long long ll;
    int mySqrt(int x) {
        int low=1;
        int high=x;

        if(x==0 || x==1){
            return x;
        }
         int ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            ll prod=mid*mid;
            if(prod==x){
                return mid;
            }else if(prod<x){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }

        }

        return ans;
    }
};