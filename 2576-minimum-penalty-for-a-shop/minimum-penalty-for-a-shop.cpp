class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();

        vector<int> pref(n+1,0),suff(n+1,0);

        for(int i=0 ; i<n ; i++){
           if(customers[i]=='N'){
                pref[i+1]=pref[i]+1;
           }else{
            pref[i+1]=pref[i];
           }
        }

        for(int i=n-1 ; i>=0 ; i--){
            if(customers[i]=='Y'){
                suff[i]=suff[i+1]+1;
            }else{
                suff[i]=suff[i+1];
            }
        }

        int mini=INT_MAX;
        int idx=-1;
        for(int i=0; i<=n ; i++){
            if(pref[i]+suff[i]<mini){
               idx=i;
               mini=pref[i]+suff[i];
            }
        }

        return idx;
    }
};