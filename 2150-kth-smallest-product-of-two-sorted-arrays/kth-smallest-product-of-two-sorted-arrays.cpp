class Solution {
public:
   typedef long long ll;

   ll check(ll x, vector<int>& nums2, long long prod){
  
    ll n2=nums2.size();

    ll l=0;
    ll r=n2-1;
    while(l<=r){
        ll mid=(l+r)/2;

        if((x<0  && nums2[mid]*x>prod) || (x>=0 && nums2[mid]*x<=prod)){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }

    if(x<0){
        return n2-l;
    }return l;
   }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
          ll low=-1e10;
          ll high=1e10;

          while(low<=high){
            ll mid=(low+high)/2;
             ll cnt=0;
             for(ll i=0; i<nums1.size(); i++)
            {    ll x=nums1[i];
                
                ll vals=check(x,nums2,mid);
                cnt+=vals;}

            if(cnt<k){
                low=mid+1;
            }else{
                high=mid-1;
            }
          }

          return low;
    }
};