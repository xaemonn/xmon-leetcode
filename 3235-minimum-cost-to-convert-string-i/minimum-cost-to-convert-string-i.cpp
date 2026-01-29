class Solution {
public:
    long long costof(int idx, string& source, string& target,
                     vector<char>& original, vector<char>& changed,
                     vector<int>& cost) {

        vector<vector<pair<int,int>>> edges(26);
        int n = original.size();
        for(int i = 0; i < n; i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            edges[u].push_back({v, cost[i]});
        }

        priority_queue<pair<long long,int>,
            vector<pair<long long,int>>, greater<>> pq;

        vector<long long> dist(26, LLONG_MAX);

        int start = source[idx] - 'a';
        int goal  = target[idx] - 'a';

        dist[start] = 0;
        pq.push({0, start});

        while(!pq.empty()){
            auto [curcost, u] = pq.top();
            pq.pop();

            if(curcost > dist[u]) continue;
            if(u == goal) return curcost;

            for(auto& [v, w] : edges[u]){
                if(curcost + w < dist[v]){
                    dist[v] = curcost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[goal];
    }

    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        long long total = 0;
        int n = source.size();
         
        vector<vector<long long>> v(26,vector<long long>(26,LLONG_MAX));
        for(int i = 0; i < n; i++){

            if(v[source[i]-'a'][target[i]-'a']==LLONG_MAX){
            long long c = costof(i, source, target, original, changed, cost);
            v[source[i]-'a'][target[i]-'a']=c;
            if(c == LLONG_MAX) {
                return -1; 
            }
            total += c;
            }else{
                total+=v[source[i]-'a'][target[i]-'a'];
            }
            
        }
        return total;
    }
};
