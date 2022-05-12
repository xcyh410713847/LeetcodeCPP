/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (38.70%)
 * Likes:    7519
 * Dislikes: 0
 * Total Accepted:    1.7M
 * Total Submissions: 4.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
            关键字：
                滑动窗口，哈希表
            思路：
                使用左右边界left和right，left和right均指向第一个字符，right向右移动
                当right指向的字符在哈希表中出现且位置不在left之前，left指向该字符上一次所在的位置的后一位，right继续向右移动
                当right指向的字符不在哈希表中出现时，用哈希表记录right指向的字符的位置
                    如果当前字符串长度大于最大长度则更新最大长度，否则不变
                    right继续向右移动
                
        */

        int max_len = 0;
        unordered_map<char, int> hashTable;
        int left = 0, right = 0;
        while (right < s.size()) {
            auto it = hashTable.find(s[right]);
            if (it != hashTable.end() && it->second >= left) {
                // 能再哈希表中找到，而且位置不在left之前
                left = it->second + 1;
            }

            // 与最大长度比较
            max_len = max(max_len, right - left + 1);
            
            // 更新哈希表
            hashTable[s[right]] = right;

            // 向右移动
            right++;
            
        }

        return max_len;
    }
};
// @lc code=end

