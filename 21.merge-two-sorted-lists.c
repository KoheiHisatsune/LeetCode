/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
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

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct _ListInstance{
  struct ListNode* head;
  struct ListNode* tail;
  int count;
} ListInstance;

void insertNewList(ListInstance* list, int val);
BOOL isFirstListUsed(struct ListNode* l1, struct ListNode* l2);
void printMergedList(ListInstance* list);

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
  ListInstance mergedList;
  memset(&mergedList,0,sizeof(ListInstance));

  while (l1 != NULL || l2 != NULL){
    if (isFirstListUsed(l1,l2)){
      insertNewList(&mergedList,l1->val);
      l1 = l1->next;
    }
    else{
      insertNewList(&mergedList,l2->val);
      l2 = l2->next;
    }
  }

 // printMergedList(&mergedList);

  return mergedList.head;

}

BOOL isFirstListUsed(struct ListNode* l1, struct ListNode* l2)
{
  if (l1 == NULL){
    printf("l1 : NULL, l2 : %d\n",l2->val);
    return FALSE;
  }

  if (l2 == NULL){
    printf("l1 : %d, l2 : NULL\n",l1->val);
    return TRUE;
  }

  printf("l1 : %d, l2 : %d\n",l1->val,l2->val);

  if (l1->val < l2->val){
    return TRUE;
  }

  return FALSE;

}

void insertNewList(ListInstance* list, int val)
{
  struct ListNode* newList = malloc(sizeof(struct ListNode));

  if (newList == NULL){
    printf("ListNode Allocation is Failed\n");
    return;
  }
  newList->val = val;
  newList->next = NULL;

  if (list->head != NULL){
    list->tail->next = newList;
    list->tail = newList;
  }
  else {
    list->head = newList;
    list->tail = newList;
  }

  list->count++;

}

void printMergedList(ListInstance* list)
{
  struct ListNode* temp = list->head;
  printf("List has %d nodes\n",list->count);
  printf("List Head : %x\n",list->head);
  while (temp != NULL){
    printf("VAL:%d\n",temp->val);
    temp = temp->next;
  }
}
// @lc code=end

