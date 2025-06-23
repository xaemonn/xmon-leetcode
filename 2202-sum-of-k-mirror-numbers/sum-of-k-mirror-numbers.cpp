class Solution
{
public:
    typedef long long ll;

    ll gen(ll num, bool odd)
    {
        string s = to_string(num);

        string temp = s;
        if (odd)
        {
            temp.pop_back();
        }
        reverse(temp.begin(), temp.end());
        string s1 = s + temp;

        ll val = stoll(s1);
        return val;
    }

    bool check(ll num, int k)
    {
        vector<int> v;
        while (num)
        {
            int dig = num % k;
            v.push_back(dig);
            num = num / k;
        }

        int n = v.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (v[i] != v[n - i - 1])
            {
                return false;
            }
        }
        return true;
    }
    long long kMirror(int k, int n)
    {
        ll sum = 0;
        for (ll i = 1; n > 0; i *= 10)
        {
            for (int j = i; n > 0 && j < i * 10; j++)
            {
                ll num1 = gen(j, true);
                if (check(num1, k))
                {
                    n--;
                    sum += num1;
                }
            }

            for (int j = i; n > 0 && j < i * 10; j++)
            {
                ll num2 = gen(j, false);
                if (check(num2, k))
                {
                    n--;
                    sum += num2;
                }
            }
        }

        return sum;
    }
};