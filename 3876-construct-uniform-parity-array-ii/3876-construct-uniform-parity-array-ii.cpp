#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_odd = INT_MAX;

        // Tìm số lẻ nhỏ nhất
        for (int x : nums1) {
            if (x % 2 != 0) {
                min_odd = min(min_odd, x);
            }
        }

        // Nếu không có số lẻ nào (toàn bộ là chẵn) -> Hợp lệ
        if (min_odd == INT_MAX) return true;

        // Nếu có số chẵn nhỏ hơn số lẻ nhỏ nhất -> Không thể đổi thành lẻ
        for (int x : nums1) {
            if (x % 2 == 0 && x < min_odd) {
                return false;
            }
        }

        return true;
    }
};