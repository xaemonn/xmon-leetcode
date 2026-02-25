class Solution {
public:
    static bool comp(int a, int b){
        int seta=__builtin_popcount(a);
         int setb=__builtin_popcount(b);
         if(seta==setb){
            return a<b;
         }
         return seta<setb;
    }
    vector<int> sortByBits(vector<int>& arr) {
         sort(arr.begin(),arr.end(),comp);
         return arr;
    }
};