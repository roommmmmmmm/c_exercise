#include <stdio.h>

char S[100];
int Top,Number_of_Items = 0;
//进栈
void Push(char c) {
  if (Number_of_Items == 0) {
    Top = 0;
    S[Top] = c;
  }else{
    Top++;
    S[Top] = c;
  }
  Number_of_Items++;
}
//出栈
void Pop() {
  Top--;
  Number_of_Items--;
}

int TopItem() {
  return S[Top];
}
int IsEmpty(){
  return Number_of_Items ==0 ? 1 : 0;
}
int main() {
  char input;
  printf("Enter a paretheses sequence (type <Enter> when done) :\n");
  scanf("%c", &input);
  while (input != '\n') {
    if (input == '(' || input == '[' || input == '{') {
      Push(input);
    }else if(input == ')'){
      if (IsEmpty() || TopItem() !='(') {
        printf("This sequence is not balanced!\n");
        return 0;
      }else{
        Pop();
      }
    }else if(input == ']'){
      if (IsEmpty() || TopItem() !='[') {
        printf("This sequence is not balanced!\n");
        return 0;
      }else{
        Pop();
      }
    }else if(input == '}'){
      if (IsEmpty() || TopItem() !='{') {
        printf("This sequence is not balanced!\n");
        return 0;
      }else{
        Pop();
      }
    }
    scanf("%c",&input );
    }
    if (IsEmpty()) {
      printf("Belanced!\n");
    }else{
      printf("This sequence is not balanced!\n");
    }
  return 0;
}
