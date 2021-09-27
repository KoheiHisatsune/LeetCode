/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode* deleteDuplicates(struct ListNode* head)
{
  struct ListNode* currentNode = head;

  while (currentNode != NULL){
    if (currentNode->next == NULL){
      break;
    }
    if (currentNode->val == currentNode->next->val){
      struct ListNode* temp = currentNode->next;
      currentNode->next = temp->next;
      free(temp);
      continue;
    }

    currentNode = currentNode->next;
  }

  return head;
}
// @lc code=end

