/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (36.54%)
 * Likes:    5200
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.8M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
         //暴力破解
        // return bruteForceAttack(s);

        // 动态规划 
        // return dynamicPlanning(s);

        // 中心扩展算法
        return centerSpreadAlgorithm(s);
    }

#pragma region 暴力破解
    /* 暴力破解
            关键字
                暴力破解
            思路：
                遍历全部的子串，判断是否是回文串
                如果是，则更新最长的回文串
                如果不是，则继续遍历
        */
    string bruteForceAttack(string s) {
        int len = s.length();
        int maxLen = 0;
        string res;
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                string tmp = s.substr(i, j - i + 1);
                if (isPalindrome(tmp) && tmp.length() > maxLen) {
                    maxLen = tmp.length();
                    res = tmp;
                }
            }
        }
        return res;
    }

    bool isPalindrome(string s) {
        int len = s.length();
        for (int i = 0; i < len / 2; i++) {
            if (s[i] != s[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }

#pragma endregion

#pragma region 动态规划
     /* 动态规划
            关键字
                动态规划
            思路：
                对于一个子串而言，如果它是回文串，并且长度大于2
                那么将它首尾的两个字母去除之后，它仍然是个回文串
            时间复杂度：
                O(n^2)
            空间复杂度：
                O(n^2)
        */
    string dynamicPlanning(string s) {
        int n = s.size();
        if (n < 2) return s;
        
        int maxLen = 1;
        int begin = 0;
         // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        // 初始化：所有长度为1的子串都是回文串
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // 递推开始
        // 先枚举子串长度
        for (int L=2; L <= n; L++) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; i++) {
                // 由 L 和 i 可以确定有边界，即 j - i + 1 = L
                int j = i + L - 1;
                // 如果右边界超出范围，则不是回文串，退出循环
                if (j >= n) break;

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要 dp[i][j] 为 true，则说明 s[i..j] 是回文串，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }

#pragma endregion

#pragma region 中心扩展算法
     /* 中心扩展算法
            关键字
                中心扩展算法
            思路：
                枚举所有的回文中心，并尝试扩展，直到无法扩展位置
            时间复杂度：
                O(n^2)
            空间复杂度：
                O(1)
        */
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string centerSpreadAlgorithm(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
#pragma endregion

};
// @lc code=end

