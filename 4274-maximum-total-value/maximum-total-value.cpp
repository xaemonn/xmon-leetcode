class Solution {
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int m) {
        long long l = 1, r = 0, th = 0, c = 0, t = 0, mod = 1e9 + 7;
        for (int x : value) if (x > r) r = x;
        
        while (l <= r) {
            long long mid = l + (r - l) / 2, cnt = 0;
            for (int i = 0; i < value.size(); ++i) {
                if (value[i] >= mid) {
                    cnt += 1 + (value[i] - mid) / decay[i];
                }
            }
            if (cnt >= m) {
                th = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        for (int i = 0; i < value.size(); ++i) {
            if (value[i] > th) {
                long long n = 1 + (value[i] - th - 1) / decay[i];
                c += n;
                long long f = value[i];
                long long lst = value[i] - (n - 1) * (long long)decay[i];
                long long s = (n * (f + lst) / 2) % mod;
                t = (t + s) % mod;
            }
        }
        
        if (m > c && th > 0) {
            t = (t + ((m - c) % mod) * (th % mod)) % mod;
        }
        
        return t;
    }
};