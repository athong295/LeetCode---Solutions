class Solution {
public:
    bool isValid(string s) {
        // Chuỗi có độ dài lẻ thì không bao giờ ghép cặp đủ
        if (s.length() % 2 != 0) return false;

        stack<char> st;

        for (char c : s) {
            // Nếu là ngoặc mở thì đẩy vào stack
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } 
            // Nếu là ngoặc đóng
            else {
                if (st.empty()) return false; // Không có ngoặc mở tương ứng

                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    st.pop(); // Khớp cặp, xóa ngoặc mở khỏi stack
                } else {
                    return false; // Sai loại ngoặc
                }
            }
        }

        // Hợp lệ khi tất cả các ngoặc mở đều đã được đóng hết
        return st.empty();
    }
};