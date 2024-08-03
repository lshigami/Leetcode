#define ll long long

class Solution {
private:
    bool isValid(ll side, ll neededApples) {
        ll appleCount = 2 * side * (side + 1) * (2 * side + 1);
        return appleCount >= neededApples;
    }

public:
    long long minimumPerimeter(long long neededApples) {
        ll left = 1;
        ll right = 1e6;
        ll ans = 0;
        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (isValid(mid, neededApples)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans * 8;
    }
};
