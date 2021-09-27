/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <stdlib.h>
#include <stdio.h>

typedef BOOL;
#define TRUE 1
#define FALSE 0

typedef struct _INT_BOX{
  int array[16];
  int count;
} INT_BOX;

INT_BOX g_intBox;

void writeBox(INT_BOX* box, long long data);
BOOL checkArray(INT_BOX box);
void printBox(INT_BOX box);

bool isPalindrome(int x){

  long long input = x;
  memset(&g_intBox,0,sizeof(INT_BOX));

  if ((long long)x < 0){
    return false;
  }

  writeBox(&g_intBox,input);
  printBox(g_intBox);

  return (checkArray(g_intBox))? true : false;

}

void writeBox(INT_BOX* box, long long data)
{
  box->array[box->count] = data % 10;
  box->count++;

  if (data / 10 == 0 && box->count != 0){
    return;
  }

  writeBox(box, data / 10);
}

BOOL checkArray(INT_BOX box)
{
  int mid = box.count /2;
  int i;

  for (i = 0; i < mid; i++){
    if (box.array[i] != box.array[box.count-1-i]){
      return FALSE;
    }
  }

  return TRUE;

}

void printBox(INT_BOX box)
{
  int i;

  for (i = 0; i < box.count; i++){
    printf("%d\n",box.array[i]);
  }
}


// @lc code=end

