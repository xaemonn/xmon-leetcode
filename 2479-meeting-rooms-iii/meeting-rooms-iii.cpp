class Solution {
public:
    typedef long long ll;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n, 0);

        priority_queue<int, vector<int>, greater<>> free; // min heap to store free rooms
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq; // {end time, room}

        sort(meetings.begin(), meetings.end());
        int m = meetings.size();

        ll curr = 0;

        for (int i = 0; i < n; i++) {
            free.push(i);
        }

        for (int i = 0; i < m; i++) {
            ll st = meetings[i][0];
            ll end = meetings[i][1];

            while (!pq.empty() && st >= pq.top().first) {
                int room = pq.top().second;
                pq.pop();
                free.push(room);
            }

            if (!free.empty()) {
                int room = free.top();
                free.pop();
                curr = st;
                pq.push({end, room});
                ans[room]++;
            } else {
                auto it = pq.top();
                pq.pop();

                ll time = it.first;
                int room = it.second;
                curr = time;
                ans[room]++;

                ll duration = end - st;
                pq.push({curr + duration, room});
            }
        }

        int maxx = -1;
        int room = -1;
        for (int i = 0; i < n; i++) {
            if (ans[i] > maxx) {
                room = i;
                maxx = ans[i];
            }
        }

        return room;
    }
};