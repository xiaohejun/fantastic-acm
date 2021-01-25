/*
 * @lc app=leetcode.cn id=959 lang=c
 *
 * [959] 由斜杠划分区域
 *
 * https://leetcode-cn.com/problems/regions-cut-by-slashes/description/
 *
 * algorithms
 * Medium (68.33%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    15.1K
 * Total Submissions: 20.1K
 * Testcase Example:  '[" /","/ "]'
 *
 * 在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。
 * 
 * （请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。
 * 
 * 返回区域的数目。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * [
 * " /",
 * "/ "
 * ]
 * 输出：2
 * 解释：2x2 网格如下：
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * [
 * " /",
 * "  "
 * ]
 * 输出：1
 * 解释：2x2 网格如下：
 * 
 * 
 * 示例 3：
 * 
 * 输入：
 * [
 * "\\/",
 * "/\\"
 * ]
 * 输出：4
 * 解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
 * 2x2 网格如下：
 * 
 * 
 * 示例 4：
 * 
 * 输入：
 * [
 * "/\\",
 * "\\/"
 * ]
 * 输出：5
 * 解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
 * 2x2 网格如下：
 * 
 * 
 * 示例 5：
 * 
 * 输入：
 * [
 * "//",
 * "/ "
 * ]
 * 输出：3
 * 解释：2x2 网格如下：
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 30
 * grid[i][j] 是 '/'、'\'、或 ' '。
 * 
 * 
 */

// @lc code=start


class UnionSet {
private:
    vector<int> _fa;
    int _size;
public:
    UnionSet(int n) {
        _fa.resize(n);
        for (int i = 0; i < n; ++i) {
            _fa[i] = i;
        }
        _size = n;
    }
    
    int find(int u) {
        return u == _fa[u] ? u : (_fa[u] = find(_fa[u]));
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            _fa[u] = v;
            _size -= 1;
        }
    }

    int size() {
        return _size;
    }
};

class Solution {
private:
    int _uuid;
    int _dir[4][2] = {
            {0, -1},
            {0, 1},
            {-1, 0},
            {1, 0}
        };
public:
    void setRound(vector<vector<int>> &maze, int x, int y) {
        for (int i = 0; i < 4; ++i) {
            int nowX = x + _dir[i][0];
            int nowY = y + _dir[i][1];
            if (maze[nowX][nowY] == -1) {
                maze[nowX][nowY] = _uuid++;
            }
        }
    }

    // 0: L
    // 1: R
    // 2: U
    // 3: D
    int getDirPos(vector<vector<int>> &maze, int nowX, int nowY, int p) {
        return maze[nowX + _dir[p][0]][nowY + _dir[p][1]];
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int newN = n + n + 1;
        vector<vector<int>> maze(newN, vector<int>(newN, -1));
        _uuid = 0;
        for (int i = 0; i < n; ++i) {
            int nowX = 2 * i + 1;
            for (int j = 0; j < n; ++j) {
                int nowY = 2 * j + 1;
                setRound(maze, nowX, nowY);
            }
        }
        UnionSet uset(_uuid);
        for (int i = 0; i < n; ++i) {
            int nowX = 2 * i + 1;
            for (int j = 0; j < n; ++j) {
                int nowY = 2 * j + 1;
                char c = grid[i][j];
                int l = getDirPos(maze, nowX, nowY, 0);
                int r = getDirPos(maze, nowX, nowY, 1);
                int u = getDirPos(maze, nowX, nowY, 2);
                int d = getDirPos(maze, nowX, nowY, 3);
                if (c == '\\') {
                    uset.merge(l, d);
                    uset.merge(r, u);
                } else if (c == '/') {
                    uset.merge(l, u);
                    uset.merge(r, d);
                } else {
                    uset.merge(l, r);
                    uset.merge(u, d);
                    uset.merge(l, u);
                }
            }
        }
        return uset.size();  
    }
};


// @lc code=end

