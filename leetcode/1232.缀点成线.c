/*
 * @lc app=leetcode.cn id=1232 lang=c
 *
 * [1232] 缀点成线
 *
 * https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/description/
 *
 * algorithms
 * Easy (46.53%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    25.6K
 * Total Submissions: 54.6K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]'
 *
 * 在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y]
 * 表示横坐标为 x、纵坐标为 y 的点。
 * 
 * 请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= coordinates.length <= 1000
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 * coordinates 中不含重复的点
 * 
 * 
 */

#include <stdbool.h>
#include <math.h>

const double INF = 1e10;
const double EPS = 1e-10;

bool doublEqual(double a, double b)
{
    return fabs(a - b) < EPS;
}

double calcRate(int *a, int *b)
{
    int detx = a[0] - b[0];
    int dety = a[1] - b[1];
    return detx == 0 ? INF : (double)dety / (double)detx;
}

// @lc code=start
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize){
    double k = calcRate(coordinates[1], coordinates[0]);
    for (int i = 0; i < coordinatesSize; ++i) {
        for (int j = i + 1; j < coordinatesSize; ++j) {
            if (!doublEqual(k, calcRate(coordinates[j], coordinates[i]))) {
                return false;
            }
        }
    }
    return true;
}
// @lc code=end

// int main()
// {
//     return 0;
// }