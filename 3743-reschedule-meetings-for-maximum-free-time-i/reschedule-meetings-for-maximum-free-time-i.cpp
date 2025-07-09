class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
         vector<int> free;
         //store all gaps
        
            free.push_back(startTime[0]);
         

         int prev=endTime[0];
         for(int i=1; i<startTime.size(); i++){
               
                free.push_back(startTime[i]-prev);
               

               prev=endTime[i];
         }
          int n=endTime.size();
        
            free.push_back(eventTime-endTime[n-1]);
         
         int ans=0;   //k meetings means shifting k+1 gaps
         //choose best k+1 gaps using sliding window
        
         for(int i=0; i<k+1 && i<free.size(); i++){
            ans+=free[i];
         }

         int sum=ans;
            int l=0;
         for(int i=k+1;i<free.size(); i++){
             sum-=free[l]; l++;
             sum+=free[i];
             ans=max(sum,ans);
         }

         return ans;


    }
}; 