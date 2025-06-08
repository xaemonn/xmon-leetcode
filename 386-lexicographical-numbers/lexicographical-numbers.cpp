class Solution {
public:
    void recur(int num, int lim, vector<int>& ans){
        if(num>lim) return;

        ans.push_back(num);

        for(int dig=0; dig<=9; dig++){
            int next=num*10+dig;

            if(next<=lim){
                recur(next,lim,ans);
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1; i<=9; i++){
            recur(i, n, ans);
        }

        return ans;
    }
};