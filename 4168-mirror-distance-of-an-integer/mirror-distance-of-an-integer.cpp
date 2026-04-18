class Solution {
public:
const int mod=1e9+7;
    int mirrorDistance(int n) {
        vector<int> digits;

        int temp=n;
        while(temp){
            int d=temp%10;
            digits.push_back(d);
            temp=temp/10;
        }

        reverse(digits.begin(),digits.end());

        int rev=0;
        long long cnt=1;
        for(int i=0; i<digits.size(); i++){
              int num=cnt*digits[i];
              rev+=num;
              cnt=cnt*10;
        }
        return abs(n-rev);
    }
};