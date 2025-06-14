class Solution {
public:
    int minMaxDifference(int num) {
        vector<int> dig;
        int temp = num;

        
        while (temp) {
            dig.push_back(temp % 10);
            temp /= 10;
        }

        reverse(dig.begin(), dig.end());
        int n = dig.size();

        int maxx = -1, mini = -1;

      
        for (int i = 0; i < n; i++) {
            if (dig[i] != 9) {
                maxx = dig[i];
                break;
            }
        }

       
        for (int i = 0; i < n; i++) {
            if (dig[i] != 0) {
                mini = dig[i];
                break;
            }
        }

       
        int max1 = 0;
        for (int i = 0; i < n; i++) {
            int d = dig[i];
            if (d == maxx) d = 9;
            max1 = max1 * 10 + d;
        }

        
        int min1 = 0;
        for (int i = 0; i < n; i++) {
            int d = dig[i];
            if (d == mini) d = 0;
            min1 = min1 * 10 + d;
        }

        return max1 - min1;
    }
};
