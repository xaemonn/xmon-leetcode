class Solution {
public:

    typedef long long ll;
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        vector<int> dig(n);

        ll maxx=0;

        for(int i=0; i<n ;i++){
            int l=dimensions[i][0];
            int w=dimensions[i][1];
            long long d = 1LL * l * l + 1LL * w * w;

            dig[i]=d;
            maxx=max(maxx,d);
        }

        ll area=0;
        for(int i=0; i<n ;i++){
            if(dig[i]==maxx){
                ll val=dimensions[i][0]*dimensions[i][1];
                area=max(area,val);
            }
        }

            return area;
        


    }
};