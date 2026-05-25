class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        int maxi=maxJump;
        int mini=minJump;
        vector<int> dp(n,0);
        dp[0]=1;
        int reach=0;
        for(int i=1; i<n ;i++){
            //add in window
            if(i-mini>=0) reach+=dp[i-mini];
            //remove from winodw
            if(i-1-maxi>=0) reach-=dp[i-1-maxi];

            if(reach>0 && s[i]=='0'){
                dp[i]=1;
            }
        }
        return dp[n-1];
    }
};