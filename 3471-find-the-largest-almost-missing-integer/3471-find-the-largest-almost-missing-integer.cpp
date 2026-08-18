class Solution {
public: 
    int largestInteger(vector<int>& nums, int k) {
        int d[60] = {0}; // Khởi tạo toàn bộ mảng về 0
        int n = nums.size();
        
        // Duyệt qua tất cả các đoạn con (subarray) có độ dài k
        for (int i = 0; i + k - 1 < n; i++) {
            unordered_set<int> seen; // Tránh đếm trùng trong cùng 1 cửa sổ
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }
            for (int val : seen) {
                d[val]++;
            }
        }
        
        // Tìm số lớn nhất chỉ xuất hiện đúng 1 lần
        for (int j = 50; j >= 0; j--) {
            if (d[j] == 1) return j;
        }
        
        return -1;
    }
};
