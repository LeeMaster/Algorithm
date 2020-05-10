#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define PLUS 0x00001 // +
#define MIUS 0x00010 // -
#define MUL  0x00100 // *
#define DIV  0x01000  // /
#define LBR  0x100000 // (

typedef struct stack_{
  int capcity;
  int * top;
  int * array;
} stack;

stack new_stack(int cap){
  int * arr = (int * )malloc(cap * sizeof(int));
  stack stack_ = {cap, arr, arr};
  return stack_;
}

void resize_(stack * stack_, int capcity_){
  int size = stack_ -> top - stack_ -> array;
  int * array_ = (int * )malloc(capcity_ * sizeof(int));
  memcpy(array_, stack_ -> array, size);
  free(stack_ -> array);
  stack_ -> array = array_;
  stack_ -> top = stack_ -> array + size;
  stack_ -> capcity = capcity_;
}

void push(stack * stack_, int value){
  int capcity;
  if (stack_ -> top == (stack_ -> array + stack_ -> capcity)){
    //resize
    resize_(stack_, stack_ -> capcity * 2);
  }
  stack_ -> top ++;
  *(stack_ -> top) = value;
}

int pop(stack * stack_){
  int value;
  if(stack_ -> top == stack_ -> array) return -1;
  value =  * stack_ -> top;
  stack_ -> top --;
  return value;
}

int top(stack * stack_){
  return * stack_ -> top;
}

int empty(stack * stack_){
  return stack_ -> top == stack_ -> array;
}

int is_number(char * ch){
  return (*ch < ('9' - 'a') || *ch > ('0' - 'a'));
}

#define SUCCESS 0
#define CONTINUE 1
#define FAILED 2

int process(stack * operands, stack * operators){
  int op, val1, val2;
  if (empty(operators)){
    printf("The oprator stack is empty will do nothing");
    return SUCCESS;
  }
  op = pop(operators);
  val1 = pop(operands);
  val2 = pop(operands);
  if(val1 == -1 || val2 == -1){
    printf("The operand stack is empty will do nothing");
    return FAILED;
  }
  switch (op){
    case PLUS:
      push(operands, val2 + val1);return CONTINUE;
    case MIUS:
      push(operands, val2 - val1);return CONTINUE;
    case MUL:
      push(operands, val2 * val1);return CONTINUE;
    case DIV:
      push(operands, val2 / val1);return CONTINUE;
    case LBR:
      return SUCCESS;
  }
}

void infix_anlysize(char * infixexpr, stack * operands, stack * operators){
  char * pos = infixexpr;
  int val = 0, now;
  int state;
  for(;;){
    // handle number
    if (is_number(pos)){
      // find the number and push it to opeands stack
      val *= 10;
      now = atoi(pos);
      val += now;
      if(is_number(pos + 1)) continue;
      push(operands, val);
      val = 0;
    }

    // hanle + -
    if (*pos == '+' || *pos == '-'){
      // 
      if (empty(operators) || top(operators) == LBR){
        push(operators, *pos == '+'? PLUS : MIUS);
      }
    }

    // hanle *
    if (*pos == '*' || *pos == '/'){
      //
      if (empty(operators) || top(operators) == LBR || top(operators) == PLUS || top(operators) == MIUS){
        push(operators, *pos == '*'? MUL : DIV);
      }

      if(top(operators) == MUL || top(operators) == DIV){
        while((state = process(operands, operators)) != SUCCESS){
          if (state == FAILED){
            exit(1);
          }
        }
        push(operators, *pos == '*'? MUL : DIV);
      }
    }

    // hanle (
    if (*pos == '('){
      push(operators, LBR);
    }

    // handle )
    if (*pos == ')'){
      while((state = process(operands, operators)) != SUCCESS){
        if (state == FAILED){
          exit(1);
        }
      }
    }

    // at the end of string
    if (*pos == '\0'){
      // eval and then break
      while((state = process(operands, operators)) != SUCCESS){
        if (state == FAILED){
          exit(1);
        }
      }
      break;
    }

    pos ++;
  }
}


int main(int argc, char const *argv[])
{
  //expression * expr;
  stack operands, operators;
  char * infix;
  int result = 0;

  if (argc == 0){
    printf("no expression\n");
    return 1;
  }
  infix = argv[1];
  operands = new_stack(strlen(infix));
  operators = new_stack(strlen(infix));
  infix_anlysize(infix, &operands, &operators);
  //expr = build_expr(&operands, &operators);

  result = *operands.top;

  return 0;
}
