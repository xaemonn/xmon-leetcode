class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();

        map<int,int> t,b;
        for(int i=0; i<n ;i++){
            t[tops[i]]++;
            b[bottoms[i]]++;
        }

        int ans=-1;
        

        for(int i=1; i<=6; i++){
            int cnt=0;
            for(int j=0; j<n ;j++){
                if(tops[j]==i || bottoms[j]==i){
                   cnt++;
                }
            }
            if(cnt==n){
                 int ops1=n-t[i];
                 int ops2=n-b[i];
                 ans=min(ops1,ops2);

            }
        }

        return ans;



    }
};