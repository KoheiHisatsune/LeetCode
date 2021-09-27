/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

void indexSet(int* indexArray, int arrayNum, int nums);
void stringSort(char* s, int* indexArray, int len);

char * convert(char * s, int numRows){

  int len = strlen(s);
  int* indexArray = malloc(sizeof(int) * len);

  indexSet(indexArray,len,numRows);

  stringSort(s,indexArray,len);

/*  int i;
  for (i = 0; i < len; i++){
    printf("%d\n",indexArray[i]);
  }*/

  free(indexArray);

  return s;
}

void stringSort(char* s, int* indexArray, int len)
{
  int mid = len / 2;
  int i;
  int j = 0;
  int k = mid;
  int l = 0;

  if (len <= 1){
    return;
  }

  stringSort(s,indexArray,mid);
  stringSort(s + mid,indexArray + mid, len - mid);

  int* indexBufer = malloc(sizeof(int) * mid);
  char* charBuffer = malloc(sizeof(char) * (mid + 1));

  for (i = 0; i < mid; i++){
    indexBufer[i] = indexArray[i];
    charBuffer[i] = s[i];
  }
/*  charBuffer[i] = '\0';
  printf("%s\n",charBuffer);*/

  while (j < mid && k < len){
    if (indexBufer[j] <= indexArray[k]){
      indexArray[l] = indexBufer[j];
      s[l++] = charBuffer[j++];
    }
    else {
      indexArray[l] = indexArray[k];
      s[l++] = s[k++];
    }
  }

  while (j < mid){
    indexArray[l] = indexBufer[j];
    s[l++] = charBuffer[j++];
  }

  free(indexBufer);
  free(charBuffer);
}

void indexSet(int* indexArray, int arrayNum, int nums)
{
  int i = 0;
  int j = 0;
  BOOL isReverse = FALSE;

  while (i < arrayNum){
    if (isReverse){
      indexArray[i++] = j--;
    }
    else {
      indexArray[i++] = j++;
    }

    if (j == nums -1){
      isReverse = TRUE;
    }
    else if (j == 0){
      isReverse = FALSE;
    }

  }
}
// @lc code=end

