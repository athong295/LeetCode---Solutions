class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool all_zeros = true;
        
        for (int x : nums) {
            total_xor ^= x;
            if (x != 0) all_zeros = false;
        }
        
        if (all_zeros) return 0;
        if (total_xor != 0) return nums.size();
        return nums.size() - 1;
    }
};