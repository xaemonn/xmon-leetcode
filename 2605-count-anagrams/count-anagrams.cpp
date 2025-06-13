class Solution {
public:
    const int mod = 1e9 + 7;

    
    long long inv(long long base, int exp) {
        long long res = 1;
        while (exp) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    int countAnagrams(string s) {
        vector<long long> fact(1e5 + 5, 1);
        for (int i = 1; i < 1e5 + 5; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }

        s += ' '; 

        int len = s.length();
        int i = 0;

        long long res = 1;

        while (i < len) {
            if (s[i] == ' ') {
                i++;
                continue;
            }

            int j = i;
            map<char, int> mp;
            while (j < len && s[j] != ' ') {
                mp[s[j]]++;
                j++;
            }

            int sz = j - i;
            long long ans = fact[sz];
            for (auto [ch, freq] : mp) {
                ans = (ans * inv(fact[freq], mod - 2)) % mod;
            }

            res = (res * ans) % mod;
            i = j;
        }

        return res;
    }
};
