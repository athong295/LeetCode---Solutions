class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        
        // Lưu trữ các ghế đã đặt dưới dạng bitmask
        for (const auto& seat : reservedSeats) {
            int r = seat[0];
            int c = seat[1];
            // Chỉ quan tâm ghế từ 2 đến 9
            if (c >= 2 && c <= 9) {
                rowMask[r] |= (1 << c);
            }
        }
        
        int ans = 0;
        
        // Mặt nạ kiểm tra cho các vị trí
        // Ghế 2, 3, 4, 5: bit 2,3,4,5 bật = 0b0000111100 = 60
        int leftMask   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        // Ghế 6, 7, 8, 9: bit 6,7,8,9 bật = 0b1111000000 = 960
        int rightMask  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
        // Ghế 4, 5, 6, 7: bit 4,5,6,7 bật = 0b0011110000 = 240
        int middleMask = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        
        for (auto& [row, mask] : rowMask) {
            bool leftFree   = (mask & leftMask) == 0;
            bool rightFree  = (mask & rightMask) == 0;
            bool middleFree = (mask & middleMask) == 0;
            
            if (leftFree && rightFree) {
                ans += 2;
            } else if (leftFree || rightFree || middleFree) {
                ans += 1;
            }
        }
        
        // Những hàng không có ghế nào bị đặt (trong khoảng 2-9) xếp được 2 nhóm mỗi hàng
        int emptyRows = n - rowMask.size();
        ans += emptyRows * 2;
        
        return ans;
    }
};