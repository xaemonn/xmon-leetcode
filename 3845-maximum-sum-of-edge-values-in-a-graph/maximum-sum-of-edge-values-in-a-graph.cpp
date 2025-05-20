class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
           
            long long score=0;
               if(n%2==0){
                  for(long long i=1; i<n-2; i+=2){
                       long long pro=1LL*i*(i+2);
                       score+=pro;
                  }
                   for(long long i=2; i<=n-2; i+=2){
                       long long pro=i*(i+2)*1LL;
                       score+=pro;
                  }
                  
                  
               }else{
                  for(long long i=1; i<=n-2; i+=2){
                       long long pro=i*(i+2)*1LL;
                       score+=pro;
                  }
                  for(long long i=2; i<n-2; i+=2){
                       long long pro=i*(i+2)*1LL;
                       score+=pro;
                  }

               }
               if(edges.size()==n){
                score+=2;
               }
               score+=1LL*(n)*(n-1);
               return score;
           
    }
};