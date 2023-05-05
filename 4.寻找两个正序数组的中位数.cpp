/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (41.53%)
 * Likes:    6502
 * Dislikes: 0
 * Total Accepted:    943.1K
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 算法的时间复杂度应该为 O(log (m+n)) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 暴力破解
        // return bruteForceAttack(nums1, nums2);

        // 暴力破解2
        return bruteForceAttack2(nums1, nums2);
    }

#pragma region 暴力破解
    /* 暴力破解
        关键字
            暴力破解
        思路
            1. 合并两个数组
            2. 排序
            3. 取中位数
        复杂度分析
            时间复杂度：O((m+n)log(m+n))
            空间复杂度：O(m+n)
    */

    double bruteForceAttack(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        sort(nums.begin(), nums.end());
        int size = nums.size();
        if (size % 2 == 0) {
            return (nums[size / 2 - 1] + nums[size / 2]) / 2.0;
        } else {
            return nums[size / 2];
        }
    }

#pragma endregion

#pragma region 暴力破解2
    /* 暴力破解2
        关键字
            暴力破解
        思路
            1，相加两个数组的长度，得到中位数的位置
            2，遍历两个数组，找到中位数的位置
            3，如果是偶数，取中间两个数的平均值
        复杂度分析
            时间复杂度：O(m+n)
            空间复杂度：O(1)
    */

    double bruteForceAttack2(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1 + size2;
        int mid = size / 2;
        int i = 0, j = 0;
        int pre = 0, cur = 0;
        while (i + j <= mid) {
            pre = cur;
            if (i < size1 && (j >= size2 || nums1[i] < nums2[j])) {
                cur = nums1[i++];
            } else {
                cur = nums2[j++];
            }
        }
        if (size % 2 == 0) {
            return (pre + cur) / 2.0;
        } else {
            return cur;
        }
    }

#pragma endregion

};
// @lc code=end

