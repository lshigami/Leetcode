class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;

        int n = points.size();
        for (int i = 1; i < n; i++)
            res += max(abs(points[i - 1][0] - points[i][0]), abs(points[i - 1][1] - points[i][1]));
        
        return res;
    }
};