class Solution {
public:
   
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int t = target;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == t) {
                return mid;
            } else if (nums[low] <= nums[mid]) {
                // left half sorted
                if (nums[low] <= t && t < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // right half sorted
                if (nums[mid] < t && t <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
