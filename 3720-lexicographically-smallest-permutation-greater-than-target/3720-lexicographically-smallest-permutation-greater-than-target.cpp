#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        
        // Đếm tần suất các ký tự trong s
        vector<int> countS(26, 0);
        for (char c : s) {
            countS[c - 'a']++;
        }

        // Thử độ dài tiền tố chung i từ n - 1 giảm dần về 0
        for (int i = n - 1; i >= 0; i--) {
            // Kiểm tra xem s có đủ ký tự để tạo target[0...i-1] không
            vector<int> countRem = countS;
            bool validPrefix = true;
            
            for (int j = 0; j < i; j++) {
                int charIdx = target[j] - 'a';
                if (--countRem[charIdx] < 0) {
                    validPrefix = false;
                    break;
                }
            }

            if (!validPrefix) continue;

            // Tìm ký tự c > target[i] nhỏ nhất còn lại
            int targetChar = target[i] - 'a';
            int chosenChar = -1;
            for (int c = targetChar + 1; c < 26; c++) {
                if (countRem[c] > 0) {
                    chosenChar = c;
                    break;
                }
            }

            // Nếu tìm được ký tự hợp lệ
            if (chosenChar != -1) {
                string result = target.substr(0, i);
                result += (char)('a' + chosenChar);
                countRem[chosenChar]--;

                // Điền các ký tự còn lại theo thứ tự tăng dần
                for (int c = 0; c < 26; c++) {
                    while (countRem[c] > 0) {
                        result += (char)('a' + c);
                        countRem[c]--;
                    }
                }
                return result;
            }
        }

        return "";
    }
};

