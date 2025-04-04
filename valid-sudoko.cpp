class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char, bool> rows[9], cols[9], boxes[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                if (num != '.') {
                    int boxIndex = (i / 3) * 3 + j / 3;  
                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) {
                        return false; 
                    }
                    rows[i][num] = true;
                    cols[j][num] = true;
                    boxes[boxIndex][num] = true;
                }
            }
        }

        return true;
    }
};
