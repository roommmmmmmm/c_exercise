
#include <stdio.h>
#include <stdlib.h>
//定义一个结构体来表示二叉树
typedef struct node{
  int key;
  struct node *left , *right ,*parent;
}Node;

Node *root = NULL;

Node
*Search(Node *x, int k){
  if ( x == NULL ) {
    return NULL;
  }
  if (x->key == k) {
    return x;
  }else if (x->key > k){
    return Search(x->left,k);
  }else {
    return Search(x->right,k);
  }
}

/*
 * @Node x 是root节点
 * @Node z 是要被插入的节点
 */
void
Insert(Node *x , Node *z) {
  //判断当前树内是否有值
  if (root == NULL) {
    root = z;
    z->parent = NULL;
    return ;
  }else{
    if ( z->key < x->key) {
      if (x->left == NULL) {
        x->left = z;
        z->parent = x;
      }else{
        Insert(x->left,z);
      }
    }else if (x->key < z->key) {
      if (x->right == NULL) {
        x->right = z;
        z->parent = x;
      }else{
        Insert(x->right,z);
      }
    }else{
      printf("Error: k alreay exists in the tree \n");
    }
  }
}
/* Assume the x != NULL and x points to the node to be deleted*/
void Delete(Node *x) {
  Node *y;
  /* check if we are deleting the root node*/
  /* if deleting the root*/
  if (x == root) {
    /* case 1*/
    if (x->left == NULL && x->right == NULL) {
      root = NULL;
    }
    /* case 2.1 : x has right child , no left child*/
    else if (x->left == NULL){
      root = x->right;
      x->right->parent = NULL;
    }
    /* case 2.2 : x has left child , no right child*/
    else if (x->right == NULL){
      root = x->left;
      x->left->parent = NULL;
    }
    /*case 3 : x has two child*/
    else{
      y = x->right;
      while (y->left != NULL) {
        y = y->left;
      }
      /* Special case : y == x->right */
      if (y == x->right) {
        y->parent = NULL;
        root = y;
        y->left = x->left;
      }else {
        Node *y_parent = y->parent , *y_right = y->right;

        y->parent = NULL;
        root = y;
        y->left = x->left;
        y->right = x->right;
        x->left->parent = y;
        x->right->parent = y;
        y_parent->left = y_right;
        if (y_right) {
          y_right->parent = y_parent;
        }
      }
    }
  }
  /* if not deleting the root*/
  else {
    /* case 1 :x is a left*/
    if (x->left == NULL && x->right == NULL) {
      /* update parent's child pointer*/
      /* if x is left child of its parent*/
      if (x->parent->left == x) {
        x->parent->left = NULL;
      }
      /* if x is right child of its parent*/
      else{
        x->parent->right = NULL;
      }
    }
    /* case 2.1 : x has right child , no left child*/
    else if (x->left == NULL){
      if (x->parent->left == x) {
        x->parent->left = x->right;
        x->right->parent = x->parent;
      }else{
        x->parent->right = x->right;
        x->right->parent = x->parent;
      }
    }
    /* case 2.2 : x has left child , no right child*/
    else if (x->right == NULL){
      if (x->parent->left == x) {
        x->parent->left = x->left;
        x->left->parent = x->parent;
      }else{
        x->parent->right = x->left;
        x->left->parent = x->parent;
      }
    }
    /* case 3 : x has two child*/
    else{
      y = x->right;
      while (y->left != NULL) {
        y = y->left;
      }
      /* Special case : y==x->right*/
      if (y == x->right) {
        /* if x is x->parent->left*/
        if (x->parent->left == x) {
          y->parent = x->parent;
          x->parent->left = y;
        }
        /* if x is x->parent->right*/
        else {
          y->parent = x->parent;
          x->parent->right = y;
        }
        y->left = x->left;
        x->left->parent = y;
      }
      /* General case : y != x->right*/
      else {
        Node *y_parent = y->parent, *y_right = y->right;
        /* if x is x->parent->left*/
        if (x->parent->left == x) {
          y->parent = x->parent;
          x->parent->left = y;
        }
        /* if x is x->parent->right*/
        else {
          y->parent = x->parent;
          x->parent->right = y;
        }
        y->left = x->left;
        y->right = x->right;
        x->left->parent = y;
        x->right->parent = y;
        y_parent->left = y_right;
        if (y_right != NULL) {
          y_right->parent = y_parent;
        }
      }
    }
  }
}
//以Inorder的方式遍历树
void
Inorder(Node *x) {
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
//以Perorder的方式遍历树
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
  Node *new_node,*to_be_delete;
  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 15;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 8;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 17;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 6;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 10;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 20;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 19;
  Insert(root,new_node);

  new_node = (Node *) malloc(sizeof(Node));
  new_node->left = new_node->right = NULL;
  new_node->key = 16;
  Insert(root,new_node);

  printf("Inorder : \n");
  Inorder(root);
  printf("\n");
  printf("Perorder : \n");
  Perorder(root);
  printf("\n");

  // if (Search(root,12) != NULL ) {
  //   printf("12 is found!\n");
  // } else {
  //   printf("Not found!\n");
  // }
  // if (Search(root,13) != NULL ) {
  //   printf("13 is found!\n");
  // } else {
  //   printf("Not found!\n");
  // }
  // if (Search(root,6) != NULL ) {
  //   printf("6 is found!\n");
  // } else {
  //   printf("Not found!\n");
  // }
  to_be_delete=Search(root,17);
  if (to_be_delete) {
    Delete(to_be_delete);
    printf("17 is deleted\n");
    free(to_be_delete);
  }
  // to_be_delete=Search(root,3);
  // if (to_be_delete) {
  //   Delete(to_be_delete);
  //   printf("3 is deleted\n");
  //   free(to_be_delete);
  // }
  // to_be_delete=Search(root,14);
  // if (to_be_delete) {
  //   Delete(to_be_delete);
  //   printf("14 is deleted\n");
  //   free(to_be_delete);
  // }
  printf("Inorder : \n");
  Inorder(root);
  printf("\n");
  printf("Perorder : \n");
  Perorder(root);
  printf("\n");
  return 0;
}
