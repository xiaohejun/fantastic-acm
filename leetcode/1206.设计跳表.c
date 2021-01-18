/*
 * @lc app=leetcode.cn id=1206 lang=c
 *
 * [1206] 设计跳表
 *
 * https://leetcode-cn.com/problems/design-skiplist/description/
 *
 * algorithms
 * Hard (60.43%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 6.1K
 * Testcase Example:  '["Skiplist","add","add","add","search","add","search","erase","erase","search"]\r\n' +
  '[[],[1],[2],[3],[0],[4],[1],[0],[1],[1]]\r'
 *
 * 不使用任何库函数，设计一个跳表。
 * 
 * 跳表是在 O(log(n))
 * 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。
 * 
 * 例如，一个跳表包含 [30, 40, 50, 60, 70, 90]，然后增加 80、45 到跳表中，以下图的方式操作：
 * 
 * 
 * Artyom Kalinin [CC BY-SA 3.0], via Wikimedia Commons
 * 
 * 跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 O(n)。跳表的每一个操作的平均时间复杂度是
 * O(log(n))，空间复杂度是 O(n)。
 * 
 * 在本题中，你的设计应该要包含这些函数：
 * 
 * 
 * bool search(int target) : 返回target是否存在于跳表中。
 * void add(int num): 插入一个元素到跳表。
 * bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false. 如果存在多个 num
 * ，删除其中任意一个即可。
 * 
 * 
 * 了解更多 : https://en.wikipedia.org/wiki/Skip_list
 * 
 * 注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。
 * 
 * 样例:
 * 
 * Skiplist skiplist = new Skiplist();
 * 
 * skiplist.add(1);
 * skiplist.add(2);
 * skiplist.add(3);
 * skiplist.search(0);   // 返回 false
 * skiplist.add(4);
 * skiplist.search(1);   // 返回 true
 * skiplist.erase(0);    // 返回 false，0 不在跳表中
 * skiplist.erase(1);    // 返回 true
 * skiplist.search(1);   // 返回 false，1 已被擦除
 * 
 * 
 * 约束条件:
 * 
 * 
 * 0 <= num, target <= 20000
 * 最多调用 50000 次 search, add, 以及 erase操作。
 * 
 * 
 */

// @lc code=start

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#define DBG_PRINT(fmt, ...) \
    printf("[%s : %d] " fmt "\n", __func__, __LINE__, ##__VA_ARGS__)

#define MAX_LEVEL 16

typedef struct _SkiplistNode {
    int32_t key;
    uint32_t cnt;
    struct _SkiplistNode *forward[MAX_LEVEL];
} SkiplistNode;

typedef struct {
    int32_t level;
    SkiplistNode *header;
} Skiplist;

static SkiplistNode* createSkipListNode(int key)
{
    SkiplistNode *node = malloc(sizeof(SkiplistNode));
    assert(node != NULL);
    memset(node, 0, sizeof(SkiplistNode));
    node->key = key;
    node->cnt = 1;
    return node;
}

static int randomLevel()
{
    int32_t level = 0;
    uint32_t mid = RAND_MAX >> 1;
    while (rand() < mid && level < (MAX_LEVEL - 1)) {
        ++level;
    }
    return level;
}

static void findNodeByKey(Skiplist* list, int32_t key,
                         SkiplistNode **node, SkiplistNode **update)
{
    SkiplistNode *p = list->header;
    for (int32_t level = list->level; level >= 0; --level) {
        while (p != NULL && 
               p->forward[level] != NULL && 
               key > p->forward[level]->key) {
            
            p = p->forward[level];
        }
        if (update != NULL) {
            update[level] = p;
        }
    }
    (*node) = p;
}

Skiplist* skiplistCreate() 
{
    Skiplist *skipList = malloc(sizeof(Skiplist));
    assert(skipList != NULL);
    memset(skipList, 0, sizeof(Skiplist));
    skipList->header = createSkipListNode(0);
    return skipList;
}

bool skiplistSearch(Skiplist* list, int32_t key) 
{
    SkiplistNode *preNode = NULL;
    findNodeByKey(list, key, &preNode, NULL);
    SkiplistNode *node = preNode != NULL ? preNode->forward[0] : NULL; 
    return node != NULL && node->key == key;
}

void skiplistAdd(Skiplist* list, int32_t key) 
{
    SkiplistNode *update[MAX_LEVEL];
    SkiplistNode *preNode = NULL;
    findNodeByKey(list, key, &preNode, update);
    SkiplistNode *node = preNode != NULL ? preNode->forward[0] : NULL;
    if (node != NULL && node->key == key) {
        node->cnt++;
        return;
    }
    int32_t newKeyLevel = randomLevel();
    if (newKeyLevel > list->level) {
        for (int32_t level = list->level + 1; level <= newKeyLevel; ++level) {
            update[level] = list->header;
        }
        list->level = newKeyLevel;
    }
    SkiplistNode *newNode = createSkipListNode(key);
    for (int32_t level = 0; level <= list->level; ++level) {
        newNode->forward[level] = update[level]->forward[level];
        update[level]->forward[level] = newNode;
    }
    return;
}

bool skiplistErase(Skiplist* list, int32_t key) 
{
    SkiplistNode *update[MAX_LEVEL];
    SkiplistNode *preNode = NULL;
    findNodeByKey(list, key, &preNode, update);
    SkiplistNode *node = preNode != NULL ? preNode->forward[0] : NULL;
    if (node == NULL || node->key != key) {
        return false;
    }
    node->cnt--;
    if (node->cnt != 0) {
        return true;
    }
    for (int32_t level = 0; level <= list->level; ++level) {
        if (update[level]->forward[level] != node) {
            break;
        }
        update[level]->forward[level] = node->forward[level];
    }
    free(node);
    while (list->level > 0 && 
           list->header->forward[list->level] == NULL) {
        list->level--;
    }
    return true;
}

void skiplistFree(Skiplist* list) 
{
    SkiplistNode *p = list->header;
    SkiplistNode *forward = NULL;
    while (p != NULL) {
        forward = p->forward[0];
        free(p);
        p = forward;
    }
    free(list);
}

/**
 * Your Skiplist struct will be instantiated and called as such:
 * Skiplist* list = skiplistCreate();
 * bool param_1 = skiplistSearch(list, target);
 
 * skiplistAdd(list, num);
 
 * bool param_3 = skiplistErase(list, num);
 
 * skiplistFree(list);
*/
// @lc code=end

int main()
{
    Skiplist* list = skiplistCreate();
    bool ret = false;
    
    skiplistAdd(list, 1);
    ret = skiplistSearch(list, 1);
    assert(ret == true);
    
    skiplistAdd(list, 2);
    ret = skiplistSearch(list, 2);
    assert(ret == true);

    skiplistAdd(list, 3);
    ret = skiplistSearch(list, 3);
    assert(ret == true);

    ret = skiplistSearch(list, 0);
    assert(ret == false);

    skiplistAdd(list, 4);
    ret = skiplistSearch(list, 4);
    assert(ret == true);

    ret = skiplistSearch(list, 1);
    assert(ret == true);

    ret = skiplistErase(list, 0);
    assert(ret == false);

    ret = skiplistErase(list, 1);
    assert(ret == true);

    ret = skiplistSearch(list, 1);
    assert(ret == false);
    
    skiplistFree(list);
}