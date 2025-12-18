class Solution {
public:
    typedef long long ll;
    ll maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();

        ll profit=0;
        for(int i=0; i<n ;i++){
            ll p=prices[i]*strategy[i];
            profit+=p;
        }

        int i=0;
        ll prev=0;
        ll curr=0;
        ll maxx=0;
        for(int j=0; j<n; j++){
            prev+=strategy[j]*prices[j];
            ll window_sz=j-i+1;
            if(window_sz>k/2){
                curr+=prices[j];
            }

            if(window_sz==k){
                maxx=max(maxx,curr-prev);
                prev-=prices[i]*strategy[i];

                if(window_sz>k/2){
                    curr-=prices[i+k/2];
                }
                i++;
                
            }

        }

        return profit+maxx;
    }
};