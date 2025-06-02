class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i=0; i<=min(limit,n); i++){
            if(n-i > 2*limit) continue;

            long long maxB=min(n-i, limit);
            long long minB=max(0, n-i-limit);
            ans+=maxB-minB+1;
        }

        return ans;
    }
};