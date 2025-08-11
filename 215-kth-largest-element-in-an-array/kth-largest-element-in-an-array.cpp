class Solution {
public:
    int solve(vector<int>& v,int k){
        int n=v.size();
        vector<int> l,r,mid;
        int idx=rand()%n;

        int pivot=v[idx];

        cout<<pivot<<endl;
        for(auto i:v){
            if(i<pivot){
                l.push_back(i);    //smaller than pivot
            }else if(i>pivot){
                r.push_back(i);   //larger
            }else{
                mid.push_back(i);  //same element aayega isme
            }
        }

        if(r.size()>=k){
            return solve(r,k);
        }else if(k>r.size() && k<=(mid.size()+ r.size())){
            return pivot;
        }
        return solve(l, k- r.size()- mid.size());




    }
    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums,k);
    }
};