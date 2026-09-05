#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Mảng lưu giá trị nhỏ nhất từ i đến cuối mảng
        vector<int> suff_min(n);
        suff_min[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff_min[i] = min(suff_min[i + 1], nums[i]);
        }
        
        // Duyệt từ trái sang phải để tìm chỉ số nhỏ nhất thỏa mãn
        int cur_max = nums[0];
        for (int i = 0; i < n; i++) {
            cur_max = max(cur_max, nums[i]);
            if (cur_max - suff_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};