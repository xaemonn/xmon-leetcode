class Solution {
public:

    bool check(double y, vector<vector<int>>& squares, double total){
        double areadown=0;
         int n=squares.size();
    

         
        for(int i=0; i<n ;i++){
             double nx=(double)squares[i][0];
             double ny=(double)squares[i][1];
             double len=(double)squares[i][2];


              if(ny>y) continue;
             if(ny<=y && ny+len<=y){
                areadown+=(len)*(len);
             }
             else if(ny<=y){
                double side=min(len, y-ny);
                areadown+=(side)*(len);
             }
        }


        return areadown>=total/2.0;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        //sort(squares.begin(),squares.end());
         double low=1e9;
        double high=0;

        double total=0.0;

        for(auto it:squares){
            total+=1.0*(it[2])*(it[2]);
            low=min(low,(double)it[1]);
            high=max(high,(double)it[1]+it[2]);
        }
       
        
        
        //double ans=-1;
        while((high-low)>1e-5){
            double mid=(low+high)/2;
            if(check(mid,squares,total)){
                 high=mid;
            }else{
                 low=mid;
            }
        }

        return low;
    }
};