class Solution {
public:
    typedef long long ll;

    static bool comp(int& a, int& b){
        return abs(a)<abs(b);
    }

    ll sameSign(vector<int>& v){
        int n=v.size();
        int j=0;
        ll cnt=0;
        for(int i=0; i<n ;i++){
            while(j<n && v[j]<= 2LL*v[i]){
                j++;
            }
            cnt+=(j-i-1);
        }

        return cnt;
    }

    ll oppSign(vector<int>& p,vector<int>& n){
        ll cnt=0;
        for(auto i:p){
            int lim=i;

            int low=-i-lim;
            int high=-i+lim;

            auto l=lower_bound(n.begin(),n.end(),low);
            auto r=upper_bound(n.begin(),n.end(),high);

            cnt+=(r-l);
        }

        return cnt;
    }
    long long perfectPairs(vector<int>& nums) {
        int n=nums.size();

        for(int i=0; i<n ;i++){
            nums[i]=abs(nums[i]);
        }

        sort(nums.begin(),nums.end());
       
       

        ll ans=0;
       

       int r=0;
        for(int l=0; l<n;l++){
            if(r<l+1){
                r=l+1;    //baad vale pairs hi check krne hai bas
            }

            while(r<n && nums[r]<= 2LL* nums[l]){
                 r++;
            }

            ans+=(r-l-1);
        }
        return ans;
        
    }
};