class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left=colors[0];
        int n=colors.size();
        int rt=colors[n-1];

        int ans=0;
        for(int i=0; i<n ; i++){
            if(i!=0){
                if(colors[i]!=left){
                    ans=max(ans,i);
                }
            }
            if(i!=n-1){
                if(colors[i]!=rt){
                    ans=max(ans,n-i-1);
                }
            }
        }

        return ans;
    }
};