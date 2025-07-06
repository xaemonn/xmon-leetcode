class FindSumPairs {
    vector<int> v1,v2;
    map<int,int> cnt;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->v1=nums1;
        this->v2=nums2;
        for(int i:v2){
            cnt[i]++; //freq of val in v2
        }
    }
    
    void add(int index, int val) {
         cnt[v2[index]]--;
         v2[index]+=val;
         cnt[v2[index]]++;
    }
    
    int count(int tot) {
        int res=0;
        for(int i:v1){
            int req=tot-i;
            if(cnt.count(req)){
                res+=cnt[req];
            }
        }

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */