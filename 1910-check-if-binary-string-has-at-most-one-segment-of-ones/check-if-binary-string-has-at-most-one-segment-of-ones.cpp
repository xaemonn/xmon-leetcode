class Solution {
public:
    bool checkOnesSegment(string s) {
        

        int seg=0;
        int curr=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
               curr++;
            }else{
                if(curr>0){
                    seg++;
                }
                curr=0;
            }
        }

        if(curr>0){
            seg++;
        }

        if(seg>1){
            return false;
        }
        return true;
    }
};