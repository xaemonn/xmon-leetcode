class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int left=0;
        int rt=0;
        for(auto s:moves){
            if(s=='L'){
                left++;
            }else if(s=='R'){
                rt++;
            }
        }
        int blank=n-left-rt;

        int win=max(left,rt);
        int loose=min(left,rt);
        return blank+win-loose;
    }
};