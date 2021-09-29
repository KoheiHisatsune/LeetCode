/*
 * @lc app=leetcode id=61 lang=c
 *
 * [61] Rotate List
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

typedef int BOOL;
#define TRUE 1
#define FALSE 0

int getListLength(struct ListNode* list);
int pushListTail(struct ListNode* list);
struct ListNode* popListHead(struct ListNode* head, int val, int len);

struct ListNode* rotateRight(struct ListNode* head, int k){

  int i;
  int val;
  int count;
  unsigned long len;
  int rotateNum;

  unsigned long ulongK = k;

  struct ListNode* list = head;

  len = getListLength(list);

  rotateNum = (len > 0)? ulongK % len: 0;

  for (i = 0; i < rotateNum; i++){
    val = pushListTail(list);
    len--;
    list = popListHead(list,val,len);
    len++;
  }

  return list;

}

int getListLength(struct ListNode* list)
{
  int result = 0;

  while (list != NULL){
    result++;
    list = list->next;
  }

  return result;
}

int pushListTail(struct ListNode* list)
{
  int val;
  struct ListNode* prev = NULL;

  while (list->next != NULL){
    prev = list;
    list = list->next;
  }

  if (prev != NULL){
    prev->next = NULL;
  }

  val = list->val;

  free(list);

  return val;

}

struct ListNode* popListHead(struct ListNode* head, int val, int len)
{
  struct ListNode* new = malloc(sizeof(struct ListNode));
  new->val = val;

  if (len > 0){
    new->next = head;
  }
  else {
    new->next = NULL;
  }

  return new;
}
// @lc code=end

