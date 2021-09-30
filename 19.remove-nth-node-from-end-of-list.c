/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
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
#include <stdlib.h>
#include <string.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
  int count = 0;
  int i;
  struct ListNode* node = head;
  struct ListNode* temp;
  struct ListNode* tail = NULL;
  struct ListNode* secondNodeFromEnd = NULL;
  struct ListNode* prevNode;
  struct ListNode* nextNode;

  while (node != NULL){
    count++;
    secondNodeFromEnd = tail;
    tail = node;
    node = node->next;
  }

  if (count == 1){
    free(head);
    return NULL;
  }

  if (n == count){
    temp = head;
    head = head->next;
    free(temp);
    return head;
  }
  else if (n == 1){
    secondNodeFromEnd->next = NULL;
    free(tail);
    return head;
  }
  else{
    temp = head;

    for (i = 0; i < count - n - 1; i++){
      temp = temp->next;
    }

    prevNode = temp;
    temp = temp->next;
    nextNode = temp->next;
    prevNode->next = nextNode;
    free(temp);
    return head;
  }

}
// @lc code=end

