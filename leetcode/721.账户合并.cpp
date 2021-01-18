/*
 * @lc app=leetcode.cn id=721 lang=c
 *
 * [721] 账户合并
 *
 * https://leetcode-cn.com/problems/accounts-merge/description/
 *
 * algorithms
 * Medium (36.92%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    19.8K
 * Total Submissions: 43.5K
 * Testcase Example:  '[["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]'
 *
 * 给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称
 * (name)，其余元素是 emails 表示该账户的邮箱地址。
 * 
 * 
 * 现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。
 * 
 * 合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按字符 ASCII 顺序排列的邮箱地址。账户本身可以以任意顺序返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：
 * accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
 * "johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
 * "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
 * 输出：
 * [["John", 'john00@mail.com', 'john_newyork@mail.com',
 * 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary",
 * "mary@mail.com"]]
 * 解释：
 * 第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
 * 第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
 * 可以以任何顺序返回这些列表，例如答案
 * [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
 * ['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']]
 * 也是正确的。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * accounts的长度将在[1，1000]的范围内。
 * accounts[i]的长度将在[1，10]的范围内。
 * accounts[i][j]的长度将在[1，30]的范围内。
 * 
 * 
 */

// @lc code=start

class UnionSet {
public:
    UnionSet(int n) {
        for (int i = 0; i < n; ++i) {
            _fa.push_back(i);
        }
        _n = n;
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
        if (u < v) {
            _fa[v] = u;
        } else {
            _fa[u] = v;
        }
    }

    void buildSet(map<int, vector<int>> &mapping) {
        for (int i = 0; i < _n; ++i) {
            int u = find(i);
            mapping[u].push_back(i);
        }
    }
private:
    vector<int> _fa;
    int _n;
};

class Solution {
public:    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> pos;
        vector<string> emails; 
        unordered_map<int, string> nameMp;
        int id = 0;
        for (auto account : accounts) {
            string& name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                string& email = account[i];
                if (pos.find(email) == pos.end()) {
                    pos.insert(make_pair(email, id++));
                    emails.push_back(email);
                }
            }
            if (account.size() > 1) {
                nameMp[pos[account[1]]] = name;
            }
        }
        UnionSet uSet(id);
        for (auto account : accounts) {
            string& name = account[0];
            for (int i = 1; i < account.size() - 1; ++i) {
                int now = pos[account[i]];
                int next = pos[account[i + 1]];
                uSet.merge(now, next);
            }
        }
        unordered_map<int, int> faPos;
        vector<vector<string>> ret;
        int idx = 0;
        for (int i = 0; i < id; ++i) {
            int fa = uSet.find(i);
            if (faPos.find(fa) == faPos.end()) {
                faPos.insert(make_pair(fa, idx++));
                ret.push_back(vector<string>());
            }
            int nowIdx = faPos[fa];
            if (ret[nowIdx].size() == 0) {
                ret[nowIdx].push_back(nameMp[fa]);
            }
            ret[nowIdx].push_back(emails[i]);
        }
        for (int i = 0; i < ret.size(); ++i) {
            sort(++ret[i].begin(), ret[i].end());
        }
        return ret;
    }
};
// @lc code=end

