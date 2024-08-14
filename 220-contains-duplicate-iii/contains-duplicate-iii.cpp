#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int valueDiff) {
        multiset<long long> s; // Dùng multiset để lưu trữ các phần tử và đếm tần suất
        
        for (int right = 0; right < nums.size(); right++) {
            if (right > k) {
                // Giữ cửa sổ kích thước k bằng cách xóa phần tử cũ nhất
                s.erase(s.find(nums[right - k - 1]));
            }
            
            // Tìm phần tử nhỏ nhất lớn hơn hoặc bằng nums[right] - valueDiff
            auto it = s.lower_bound((long long)nums[right] - valueDiff);
            
            // Kiểm tra nếu phần tử tìm thấy thỏa mãn điều kiện
            if (it != s.end() && *it <= (long long)nums[right] + valueDiff) {
                return true;
            }
            
            // Thêm phần tử hiện tại vào multiset
            s.insert(nums[right]);
        }
        
        return false;
    }
};
