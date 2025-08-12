class Solution {
public:
     int dist(vector<int>& pt){
        int x=pt[0];
        int y=pt[1];

        int d=x*x+ y*y;

        return d;
     }

     int part(vector<vector<int>>& p, int low, int high){
          int pivot=dist(p[high]);  //highest distance(assumed), can do random too

          int i=low; int j=low;

          while(j<high){
            if(dist(p[j])< pivot){
                swap(p[j],p[i]);
                i++;
            }

            j++;
          }
          swap(p[i],p[high]);
        return i;
     }


     void quick(vector<vector<int>>& p, int k , int low, int high){
        if(low==high){
            return;
        }

        int pos=part(p, low, high);

        if(pos==k){
            return;
        }
        else if(pos<k){
            quick(p, k, pos+1,high);
        }else{
            quick(p, k, low, pos-1);
        }
     }


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        quick(points,k,0, points.size()-1);
        for(int i=0; i<k;i++){
            ans.push_back(points[i]);
        }

        return ans;
    }
};