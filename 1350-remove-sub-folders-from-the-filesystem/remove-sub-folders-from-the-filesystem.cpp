class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        vector<string> v;

        for(auto& f:folder){
           if(v.empty()){
            v.push_back(f);
           }else{
              string prev=v.back();
              if(f.find(prev)==0 && f.size()>prev.size() && f[prev.size()]=='/' ){
                //starting se match.....then "/" should be there
                continue;
              }else{
                    v.push_back(f);
              }
           }
        }

        return v;
    }
};