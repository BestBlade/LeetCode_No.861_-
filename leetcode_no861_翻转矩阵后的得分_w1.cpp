/* ------------------------------------------------------------------|
有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

返回尽可能高的分数。

 

示例：

输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
输出：39
解释：
转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 

提示：

1 <= A.length <= 20
1 <= A[0].length <= 20
A[i][j] 是 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/score-after-flipping-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	贪心法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.3 MB, 在所有 C++ 提交中击败了81.72%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void reversematrixrow(vector<int>& v) {
    for (int& i : v) {
        i = !i;
    }
    return;
}

int matrixScore(vector<vector<int>>& A) {
    if (A.size() == 0 || A[0].size() == 0) {
        return 0;
    }
    int m = A.size();
    int n = A[0].size();
    vector<int> count(n, 0);
    int res = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (A[i][0]) {
                count[j] += A[i][j];
            }
            else {
                count[j] += (1 - A[i][j]);
            }
        }
        int k = max(count[j], m - count[j]);
        res += k * (1 << (n - 1 - j));

    }
    return res;
}

int main() {
    vector<vector<int>> A = { {0,0,1,1},{1,0,1,0},{1,1,0,0} };
    int res = matrixScore(A);
}

