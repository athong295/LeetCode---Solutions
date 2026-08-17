#include <vector>
#include <numeric>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int memo[501][501];
    vector<int> prefix;

    int getSum(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }

    int solve(int i, int j, const vector<int>& stoneValue) {
        // Chỉ còn 1 viên đá thì không thể chia tiếp, điểm thêm = 0
        if (i >= j) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];

        int maxScore = 0;

        // Thử mọi vị trí chia k từ i đến j - 1
        for (int k = i; k < j; k++) {
            int leftSum = getSum(i, k);
            int rightSum = getSum(k + 1, j);

            if (leftSum < rightSum) {
                // Bob bỏ bên phải, giữ bên trái
                maxScore = max(maxScore, leftSum + solve(i, k, stoneValue));
            } else if (leftSum > rightSum) {
                // Bob bỏ bên trái, giữ bên phải
                maxScore = max(maxScore, rightSum + solve(k + 1, j, stoneValue));
            } else {
                // Hai bên bằng nhau, Alice chọn bên đem lại nhiều điểm hơn
                int takeLeft = leftSum + solve(i, k, stoneValue);
                int takeRight = rightSum + solve(k + 1, j, stoneValue);
                maxScore = max({maxScore, takeLeft, takeRight});
            }
        }

        return memo[i][j] = maxScore;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memset(memo, -1, sizeof(memo));

        // Xây dựng mảng tiền tố
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(0, n - 1, stoneValue);
    }
};