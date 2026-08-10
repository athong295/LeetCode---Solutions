#include <vector>

class Solution {
public:
    bool winnerSquareGame(int n) {
        std::vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // Chỉ cần 1 nước đi khiến đối thủ thua là thắng ngay
                }
            }
        }
        
        return dp[n];
    }
};