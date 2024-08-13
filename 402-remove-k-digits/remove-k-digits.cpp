class Solution {
public:
    string removeKdigits(std::string num, int k) {
        stack<char> stack;

        for (char digit : num) {
            // Loại bỏ chữ số lớn hơn chữ số hiện tại và nếu còn có thể loại bỏ
            while (k > 0 && !stack.empty() && stack.top() > digit) {
                stack.pop();
                k--;
            }
            stack.push(digit);
        }

        // Loại bỏ thêm chữ số nếu k > 0
        while (k > 0 && !stack.empty()) {
            stack.pop();
            k--;
        }

        // Tạo số từ stack
        std::string result;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }

        // Đảo ngược chuỗi vì stack trả về từ cuối
        reverse(result.begin(), result.end());

        // Bỏ số '0' đứng đầu
        auto pos = result.find_first_not_of('0');
        result = pos == std::string::npos ? "0" : result.substr(pos);

        return result.empty() ? "0" : result;
    }
};