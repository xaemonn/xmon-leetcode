class Solution {
public:
    typedef long long ll;
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();

        ll low=1;
        ll high=INT_MAX;

        ll ans=-1;
        while(low<=high){
             double time=0;
            ll mid=(low+high)/2;
            for(int i=0; i<n ;i++){
                double t=( double)dist[i]/( double)mid;
                if(floor(t)==t){
                    time+=t;
                }else{
                    if(i==n-1){
                        time+=t;
                    }else{
                    time+=ceil(t);}
                }
            }
            if(time<=hour){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return ans;
    }
};