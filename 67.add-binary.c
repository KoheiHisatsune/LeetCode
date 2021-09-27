/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start
#include <stdio.h>
#include <string.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct _BINARY_DARA{
  int len;
  char buf[16384];
} BINARY_DATA;

char g_retBuf[16384];

void reverseFromChar(BINARY_DATA* dst, char* src);
void reverseToChar(char* dst, BINARY_DATA src);
char fullAdder(char a, char b, char* carry);
void addData(BINARY_DATA* result, BINARY_DATA a, BINARY_DATA b);

char * addBinary(char * a, char * b){

  BINARY_DATA data_a;
  BINARY_DATA data_b;
  BINARY_DATA addResult;

  memset(&addResult,0,sizeof(BINARY_DATA));
  memset(&data_a,0,sizeof(BINARY_DATA));
  memset(&data_b,0,sizeof(BINARY_DATA));
  memset(&g_retBuf,0,sizeof(g_retBuf));

  reverseFromChar(&data_a,a);
  reverseFromChar(&data_b,b);

  addData(&addResult,data_a,data_b);

  reverseToChar(g_retBuf,addResult);

  return g_retBuf;

}

void addData(BINARY_DATA* result, BINARY_DATA a, BINARY_DATA b)
{
  int i;
  int len = (a.len > b.len)? a.len : b.len;
  char carry = 0;

  for (i = 0; i < len; i++){
    result->buf[i] = fullAdder(a.buf[i],b.buf[i],&carry);
    result->len++;
    //printf("%d\n",result->buf[i]);
  }

  if (carry != 0){
    result->buf[len] = 1;
    result->len++;
  }

}

char fullAdder(char a, char b, char* carry)
{
  char result;

  //printf("a %d b %d carry %d",a,b,*carry);

  result = (a + b + *carry) % 2;
  *carry = (a + b + *carry) / 2;

  return result;
}

void reverseFromChar(BINARY_DATA* dst, char* src)
{
  int i;
  int len = strlen(src);

  //printf("%s\n",src);

  for (i = 0; i < len; i++){
    dst->buf[i] = src[len - 1 -i] - '0';
    dst->len++;
    //printf("%d\n",dst->buf[i]);
  }

}

void reverseToChar(char* dst, BINARY_DATA src)
{
  int i;
  int len = src.len;

  for (i = 0; i < len; i++){
    dst[i] = src.buf[len - 1 - i] + '0';
    //printf("%c\n",dst[i]);
  }

  dst[len] = '\0';
}

// @lc code=end

