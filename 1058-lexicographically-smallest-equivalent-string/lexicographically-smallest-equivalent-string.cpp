class Solution {
public:
   class disjoint{
    vector<int> par;
    public:
    disjoint(int n){
        par.resize(n);
        for(int i=0; i<n ;i++){
            par[i]=i;
        }
    }

    int findP(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=findP(par[x]);
    }

    void unite(int u, int v){
        int pu=findP(u);
        int pv=findP(v);
        if(pu==pv) return;
        if(pu<pv){
            par[pv]=par[pu];
        }else{
            par[pu]=par[pv];
        }
    }
   };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int len=s1.length();
        disjoint ds(26);
        for(int i=0; i<len ;i++){
               ds.unite(s1[i]-'a', s2[i]-'a');
        }

        string ans="";

        for(int i=0; i<baseStr.length(); i++)
        {
            ans.push_back(ds.findP(baseStr[i]-'a')+'a');
        }

        return ans;
    }
};