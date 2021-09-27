/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include <stdlib.h>
#include <string.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct _STACK_INSTANCE{
  char* data;
  int   elementSize;
  int   maxStackSize;
  int   writeIndex;
} STACK_INSTANCE;

void stackInitialize(STACK_INSTANCE* stack, void* bufferPool, int elementSize  , int maxStackSize);
void stackPush(STACK_INSTANCE* stack, void* data);
void* stackPop(STACK_INSTANCE* stack);
BOOL isLeftParentheses(char c);
BOOL isValidPair(char left, char right);

bool isValid(char * s){

  int i;
  int len = strlen(s);

  char buf[10000];
  char leftChar;
  STACK_INSTANCE leftStack;

  stackInitialize(&leftStack, &buf, sizeof(char), sizeof(buf));

  for (i = 0; i < len; i++){
    if (isLeftParentheses(s[i])){
      stackPush(&leftStack,&(s[i]));
      continue;
    }

    if (leftStack.writeIndex == 0){
      return false;
    }

    leftChar = *((char *)stackPop(&leftStack));

    if (!isValidPair(leftChar,s[i])){
      return false;
    }

  }

  if (leftStack.writeIndex != 0){
    return false;
  }

  return true;

}

void stackInitialize(STACK_INSTANCE* stack, void* bufferPool, int elementSize  , int maxStackSize)
{
  memset(stack,0,sizeof(STACK_INSTANCE));
  stack->elementSize = elementSize;
  stack->maxStackSize = maxStackSize;
  stack->data = bufferPool;

}

void stackPush(STACK_INSTANCE* stack, void* data)
{
  char* buf = stack->data + (stack->writeIndex * stack->elementSize);
  memcpy(buf,data,stack->elementSize);
  stack->writeIndex++;
}

void* stackPop(STACK_INSTANCE* stack)
{
  if (stack->writeIndex == 0){
    return NULL;
  }

  char* popValue = stack->data + ((stack->writeIndex - 1) * stack->elementSize);
  stack->writeIndex--;

  return popValue;
}

BOOL isLeftParentheses(char c)
{
  if (c == '(' || c == '{' || c == '['){
    return TRUE;
  }
  else {
    return FALSE;
  }
}

BOOL isValidPair(char left, char right)
{
  if (left == '(' && right == ')'){
    return TRUE;
  }

  if (left == '{' && right =='}'){
    return TRUE;
  }

  if (left == '[' && right == ']'){
    return TRUE;
  }

  return FALSE;
}






// @lc code=end

