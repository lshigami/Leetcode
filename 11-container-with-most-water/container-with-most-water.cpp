class Solution {
public:
    int maxArea(vector<int>& height) {
    int n = height.size();
    int area = 0;
    int l = 0;
    int r = n - 1;

    while (l < r) {
        int cd = r - l;
        int cr = min(height[r], height[l]);
        int temp = cd * cr;

        if (area < temp) {
            area = temp;
        }

        if (height[l] < height[r])
            l++;
        else
            r--;
    }

    return area;
}
};