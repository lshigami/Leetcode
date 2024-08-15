class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Sắp xếp các số dựa trên thứ tự lớn nhất khi ghép chuỗi
        sort(nums.begin(), nums.end(), [](int a, int b) {
            string s1 = to_string(a), s2 = to_string(b);
            return s1 + s2 > s2 + s1;
        });

        // Nếu phần tử lớn nhất là 0, trả về "0" để tránh kết quả như "00..."
        if (nums[0] == 0) return "0";

        string res;
        for (int num : nums) {
            res += to_string(num);
        }

        return res;
    }
};
