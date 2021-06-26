/*
让我们一起来玩扫雷游戏！

给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。

现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：

如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回面板。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        update(board, x, y);
        return board;
    }

    void update(vector<vector<char>>& board, int x, int y) {
        if (board[x][y] != 'E')
            return;
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int tmpx = x - 1 + i;
                int tmpy = y - 1 + j;
                if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m) {
                    if (board[tmpx][tmpy] == 'M') {
                        count++;
                    }
                }
            }
        }
        board[x][y] = (count == 0) ? 'B' : count + '0';
        
        if (count != 0)
            return;
        
        // 递归查看和'B'相邻的位置
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int tmpx = x - 1 + i;
                int tmpy = y - 1 + j;
                if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m) {
                    update(board, tmpx, tmpy);
                }
            }
        }
    }
};

int main()
{
    vector<vector<char>> board {{'E', 'E', 'E', 'E', 'E'},
                                {'E', 'E', 'M', 'E', 'E'},
                                {'E', 'E', 'E', 'E', 'E'},
                                {'E', 'E', 'E', 'E', 'E'}};
    
    vector<int> click {3, 0};
    auto ans = Solution().updateBoard(board, click);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

