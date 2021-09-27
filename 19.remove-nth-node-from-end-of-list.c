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


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

  struct ListNode* target;
  struct ListNode* start;
  struct ListNode* target =

  while (head != NULL){

  }


}

struct ListNode* ListPoint(struct ListNode* start, int num)
{
  int i;
  struct ListNode* temp = start;

  for (i = 0; i < num; i++){
    if (temp->next == NULL){
      return temp->next;
    }
    temp = temp->next;
  }

  return temp;
}
// @lc code=end

