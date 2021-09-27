/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
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
#include <stdio.h>

int addNode(struct ListNode* l1, struct ListNode* l2, int* carry);
struct ListNode* addToList(struct ListNode* list,int data);
struct ListNode* jumpToNextNode(struct ListNode* list);

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
  int carry = 0;
  int val;
  struct ListNode* newList = NULL;

  while (l1 != NULL || l2 != NULL || carry != 0){
    val = addNode(l1,l2,&carry);
    newList = addToList(newList,val);
    l1 = jumpToNextNode(l1);
    l2 = jumpToNextNode(l2);
  }

  return newList;

}

struct ListNode* jumpToNextNode(struct ListNode* list)
{
  return ((list != NULL)? list->next : NULL);
}

int addNode(struct ListNode* l1, struct ListNode* l2, int* carry)
{
  int sum;
  int a = (l1 == NULL)? 0 : l1->val;
  int b = (l2 == NULL)? 0 : l2->val;

  sum = a + b + *carry;

  *carry = sum / 10;

  return sum % 10;
}

struct ListNode* addToList(struct ListNode* list,int data)
{
  struct ListNode* temp = list;
  struct ListNode* newNode = malloc(sizeof(struct ListNode));
  newNode->val = data;
  newNode->next = NULL;

  if (temp == NULL){
 //   printf("New List is Created\n");
    return newNode;
  }

  while (temp->next != NULL){
    temp = temp->next;
  }

  temp->next = newNode;

  return list;

}
// @lc code=end

