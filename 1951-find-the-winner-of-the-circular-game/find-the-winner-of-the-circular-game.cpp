class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> dq;
        for(int i=1; i<=n;i++){
            dq.push(i);
        }


        int cnt=0;

        while(dq.size()!=1){
            int val=dq.front();
            dq.pop();
            cnt++;
            if(cnt%k!=0){
                  dq.push(val);
            }
        }

        return dq.front();
    }
};