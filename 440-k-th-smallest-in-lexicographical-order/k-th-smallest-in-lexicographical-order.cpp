class Solution {
public:
    int count(int n, long num1, long num2 ){
        int steps=0;
        while(num1<=n){
            steps+=min((long)(n+1),num2)-num1;
            num1*=10;
            num2*=10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            int step=count(n,curr,curr+1);
            if(step<=k){
                curr++;
                k-=step;
            }else{
                curr*=10;
                k--;
            }
        }

        return curr;
    }
};