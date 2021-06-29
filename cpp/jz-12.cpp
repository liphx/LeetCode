/*
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
 * 如果 word 存在于网格中，返回 true ；否则，返回 false 。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
 * 同一个单元格内的字母不允许被重复使用。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * board 和 word 仅由大小写英文字母组成
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backtrack(vector<vector<char>>& board, int i, int j, const string &word, int idx) {
        if (idx == word.size())
            return true;
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if (word[idx] != board[i][j])
            return false;

        board[i][j] = '*';
        if (backtrack(board, i - 1, j, word, idx + 1) || 
                backtrack(board, i + 1, j, word, idx + 1) ||
                backtrack(board, i, j - 1, word, idx + 1) || 
                backtrack(board, i, j + 1, word, idx + 1)) 
            return true;

        board[i][j] = word[idx];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) 
            return word.empty();

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, i, j, word, 0))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    vector<vector<char>> board = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' },
        { 'A', 'D', 'E', 'E' }
    };
    cout << Solution().exist(board, "ABCCED") << endl; // 1

    vector<vector<char>> board2 = {
        { 'a', 'b' },
        { 'c', 'd' }
    };
    cout << Solution().exist(board2, "abcd") << endl; // 0

    vector<vector<char>> board3 = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'E', 'S' },
        { 'A', 'D', 'E', 'E' }
    };
    cout << Solution().exist(board3, "ABCESEEEFS") << endl; // 1
}
