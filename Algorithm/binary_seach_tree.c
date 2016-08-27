
#include <stdio.h>
#include <stdlib.h>
//定义一个结构体来表示二叉树
typedef struct node{
  int key;
  struct node *left , *right;
}Node;

Node *root = NULL;
/*
 * @Node x 是root节点
 * @Node z 是要被插入的节点
 */
void Insert(Node *x , Node *z) {
  //判断当前树内是否有值
  if (root == NULL) {
    root = z;
    return ;
  }else{
    if ( z->key < x->key) {
      if (x->left == NULL) {
        x->left = z;
      }else{
        Insert(x->left,z);
      }
    }else if (x->key < z->key) {
      if (x->right == NULL) {
        x->right = z;
      }else{
        Insert(x->right,z);
      }
    }else{
      printf("Error: k alreay exists in the tree \n");
    }
  }
}
//以Inorder的方式遍历树
void Inorder(Node *x) {
  if (x == NULL) {
    return ;
  }
  if (x->left != NULL){
    Inorder(x->left);
  }

  printf("%d\n",x->key);

  if (x->right != NULL) {
    Inorder(x->right);
  }
}

void Perorder(Node *x) {
  if (x == NULL) {
    return ;
  }
  printf("%d\n",x->key);

  if (x->left != NULL){
    Perorder(x->left);
  }

  if (x->right != NULL) {
    Perorder(x->right);
  }
}

int main() {
  Node *new_node;
  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 14;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 12;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 1;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 6;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 3;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 12;
  Insert(root,new_node);

  printf("Inorder : ");
  Inorder(root);
  printf("\n");
  printf("Perorder : ");
  Perorder(root);
  printf("\n");
  return 0;
}
