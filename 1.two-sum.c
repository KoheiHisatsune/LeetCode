/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

#define PRIME 20011

typedef struct _LIST_NODE{
  int data;
  struct _LIST_NODE* next;
} LIST_NODE;

typedef struct _LIST_INSTANCE{
  LIST_NODE* head;
  LIST_NODE* tail;
  int count;
} LIST_INSTANCE;

int* checkList(LIST_INSTANCE* map, int* nums, int numsLen , int target);
void listAdd(LIST_INSTANCE* list, int data);
void printList(LIST_INSTANCE* map, int listNum);
int  hash(int key);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
  int i;
  int index;
  int* returnArray;

  LIST_INSTANCE* map = calloc(PRIME, sizeof(LIST_INSTANCE));

  for (i = 0; i < numsSize; i++){
    index = hash(nums[i]);
    listAdd(&(map[index]),i);
  }

//  printList(map,PRIME);

  returnArray = checkList(map, nums, numsSize ,target);
  *returnSize = 2;

  free(map);

  return returnArray;

}

int* checkList(LIST_INSTANCE* map, int* nums, int numsLen, int target)
{
  int i;
  int distance;
  int diff;
  int hash_comp;
  int* returnArray = malloc(2*sizeof(int));

  for (i = 0; i < numsLen; i++){
    hash_comp = hash(target - nums[i]);
    //printf("%d\n",hash_comp);
    if (map[hash_comp].count == 0){
      continue;
    }

    //printf("%d %d\n",map[hash_comp].head->data,i);

    if (map[hash_comp].head->data != i){
      returnArray[0] = i;
      returnArray[1] = map[hash_comp].head->data;
      break;
    }
    else if (map[hash_comp].head->next != NULL){
      returnArray[0] = i;
      returnArray[1] = map[hash_comp].head->next->data;
      break;
    }
  }

  return returnArray;
}

void listAdd(LIST_INSTANCE* list, int data)
{
  LIST_NODE* newNode = malloc(sizeof(LIST_NODE));
  newNode->data = data;
  newNode->next = NULL;

  if (list->count == 0){
    list->head = newNode;
    list->tail = newNode;
  }
  else {
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->count++;

}

void printList(LIST_INSTANCE* map, int listNum)
{
  int i;
  LIST_NODE* temp;

  for (i = 0; i < listNum; i++){
    if (map[i].count == 0){
      printf("List %d has no node\n",i);
      continue;
    }

    temp = map[i].head;
    while (temp != NULL){
      printf("%d %d\n",i,temp->data);
      temp = temp->next;
    }

  }
}

int hash(int key)
{
  return abs(key % PRIME);
}

// @lc code=end

