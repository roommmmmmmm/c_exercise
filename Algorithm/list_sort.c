#include <stdio.h> /* printf ,scanf ,NULL*/
#include <stdlib.h> /* malloc free */

typedef struct node {
  int key;
  struct node *next;
}NODE;
NODE *Head = NULL;

void Insert(int k) {
  NODE *new_node,*current;
  new_node = (NODE *)malloc(sizeof(NODE));
  new_node->key = k;

  /*new node is inserted at the beginning of the list*/
  if (Head == NULL || Head->key >k) {
    new_node->next = Head;
    Head = new_node;
  }
  /*new node is inserted somewhere inside the list*/
  else{
    current = Head;
    while (1) {
        if (current->next == NULL || current->next->key > k ) {
          new_node->next = current->next;
          current->next = new_node;
          break;
        }
        current = current->next;
    }
  }
}
NODE *Delete(int k){
  NODE *current = Head,*answer;
  /* Handle the special case that the first node is to be deleted*/
  if (Head != NULL && Head->key == k) {
    Head = Head->next;
    return current;
  }else if(Head != NULL && Head->key > k){
    return NULL;
  }

  while (current != NULL) {
    /* check if the next node is to be deleted */
    if (current->next != NULL && current->next->key == k) {
      answer = current->next;
      current->next = current->next->next;
      return answer;
    }else if(current->next !=NULL && current->next->key > k){
      return NULL;
    }
    /* update current*/
    current = current->next;
  }
  /* if current is NULL,then k is not in the list,so return NULL*/
  if (current == NULL) {
    return NULL;
  }
}

void Print () {
  NODE *current;
  if (Head==NULL) {
    printf("This list is empty\n");
  }else{
    current = Head;
    while (current != NULL) {
      printf("%d\n",current->key );
      current = current->next;
    }
    printf("\n");
  }
}
int main() {
  NODE *x;
  Insert(15);
  Insert(12);
  Insert(1);
  Insert(3);
  Insert(2);
  Print();
  x = Delete(3);
  if (x != NULL) {
    free(x);
  }
  Print();
  return 0;
}
