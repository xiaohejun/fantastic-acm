/*
 * @lc app=leetcode.cn id=86 lang=c
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (60.35%)
 * Likes:    332
 * Dislikes: 0
 * Total Accepted:    74.1K
 * Total Submissions: 120.2K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：head = 1->4->3->2->5->2, x = 3
 * 输出：1->2->2->4->3->5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdbool.h>

// struct ListNode {
//      int val;
//      struct ListNode *next;
// };

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *addPos = NULL;
    bool found = false;
    struct ListNode *p = NULL, *pre = NULL;
    for (p = head; p != NULL; pre = p, p = p->next) {
        if (p->val >= x) {
            addPos = pre;
            found = true;
            break;
        }
    }
    if (!found) {
        return head;
    }
    if (addPos == NULL) {
        p = head->next;
        pre = head;
    } else {
        p = addPos->next->next;
        pre = addPos->next;
    }
    for (; p != NULL; pre = p, p = p->next) {
        if (p->val < x) {
            pre->next = p->next;
            if (addPos == NULL) {
                p->next = head;
                head = p;
                addPos = head;
            } else {
                p->next = addPos->next;
                addPos->next = p;
                addPos = p;
            }
        }
    }
    return head;
}

/*
[4,3,2,1]\n2
*/
// @lc code=end

