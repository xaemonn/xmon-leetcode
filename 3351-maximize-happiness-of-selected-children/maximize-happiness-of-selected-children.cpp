class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
      long long int x=0;
      int s=happiness.size();
      sort(happiness.begin(),happiness.end());
      int n=0;
     for(int i=0; i<k; i++){
       if( ( happiness[s-1-i]-n)>0) {x=x + happiness[s-i-1]-n;}
       else{ x=x+0;}
       n++;

     }

     return x;
       




      }  
    
};