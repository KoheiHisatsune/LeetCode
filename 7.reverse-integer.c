/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <stdlib.h>
#include <stdio.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct _LIST_ELEMENT{
  struct _LIST_ELEMENT* next;
  struct _LIST_ELEMENT* prev;
  int data;
} LIST_ELEMENT;

typedef struct _LIST_INSTANCE{
  LIST_ELEMENT* head;
  LIST_ELEMENT* tail;
  int count;
} LIST_INSTANCE;

LIST_INSTANCE g_queueList;

void listInitialize(LIST_INSTANCE* list);
void queuePop(LIST_INSTANCE* list, int data, BOOL isRecursion);
long long queuePush(LIST_INSTANCE* list);
int power(int num);

int reverse(int x){

  unsigned long long inputAbs;
  int result;
  unsigned long long resultAbs;
  printf("%d\n",sizeof(long long));
  BOOL isMinus = FALSE;

  if ((long long)x < 0){
    isMinus = TRUE;
  }

  if (isMinus){
    inputAbs = (-1) * (long long)x;
  }
  else {
    inputAbs = (long long)x;
  }

  printf("%d\n",inputAbs);

  listInitialize(&g_queueList);
  queuePop(&g_queueList,inputAbs, FALSE);
  resultAbs = queuePush(&g_queueList);

  printf("%d %d\n",resultAbs,isMinus);

  if (isMinus && resultAbs <= INT_MAX){
    result = (-1) * resultAbs;
  }
  else if (resultAbs <= INT_MAX){
    result = resultAbs;
  }
  else {
    result = 0;
  }

  return result;

}

void listInitialize(LIST_INSTANCE* list)
{
  list->tail = NULL;
  list->head = NULL;
  list->count = 0;
}

void queuePop(LIST_INSTANCE* list, int data, BOOL isRecursion)
{
  if (data == 0 && isRecursion){
    return;
  }

  LIST_ELEMENT* new = malloc(sizeof(LIST_ELEMENT));
  if (list->head == NULL){
    list->head = new;
  }
  new->next = NULL;
  new->prev = list->tail;
  new->data = data % 10;
  if (list->tail != NULL){
    list->tail->next = new;
  }
  list->tail = new;
  list->count++;

  queuePop(list,data/10, TRUE);

}

long long queuePush(LIST_INSTANCE* list)
{
  long long data;
  LIST_ELEMENT* head = list->head;

  data = head->data;

  if (head->next != NULL){
    head->next->prev = NULL;
  }
  list->head = head->next;
  list->count--;

  free(head);

  if (list->head == NULL){
    return data;
  }
  else {
    return data * power(list->count) + queuePush(list);
  }

}

int power(int num)
{
  int i;
  int result = 1;

  for (i = 0; i < num; i++){
    result *= 10;
  }

  return result;
}




// @lc code=end

