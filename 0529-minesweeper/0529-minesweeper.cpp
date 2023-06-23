class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col) {
        int m = board.size();
        int n = board[0].size();

        // Kiểm tra điều kiện kết thúc đệ quy
        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'E')
            return;

        // Đếm số lượng ô lân cận chứa mìn
        int count = 0;
        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        for (const auto& dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && board[newRow][newCol] == 'M')
                count++;
        }

        // Trường hợp không có ô lân cận chứa mìn
        if (count == 0) {
            board[row][col] = 'B';
            for (const auto& dir : directions) {
                int newRow = row + dir.first;
                int newCol = col + dir.second;
                dfs(board, newRow, newCol);
            }
        }
        // Trường hợp có ô lân cận chứa mìn
        else {
            board[row][col] = count + '0';
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int col = click[1];

        if (board[row][col] == 'M') {
            // Ô nhấp vào chứa mìn, đổi thành 'X' và kết thúc trò chơi
            board[row][col] = 'X';
        } else {
            // Ô nhấp vào không chứa mìn, sử dụng DFS để mở ô và cập nhật bảng
            dfs(board, row, col);
        }

        return board;
    }
};
