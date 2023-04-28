#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// función: insert, agrega elementos en un árbol con puntero inicial root
void insert(int data) {
   struct node tempNode/*punto a la memoria/ = (struct node*) malloc(sizeof(struct node));
   struct node *actual;
   struct node *padre;

   //agregamos los valores en node
    tempNode-> value=data;
    actual-> left == NULL;
    padre-> right== NULL;

   /**
   Código
    **/

   //si el árbol está vacio
   if(root == NULL) {
           root = tempNode;
           actual= root;
           padre = root;
           
   } else {
        actual = root;
        padre = NULL;

      while(1) {
         padre = actual;

         //recorrido por la izquierda del árbol
         if(data < padre->value) {
            actual=actual->left;

            //insertamos en izquierda
            if(actual == NULL) {
               padre ->left = tempNode;
               return; 
            }
         }
         //recorrido por la derecha del árbol
         else {
             actual=actual->right;
            //insertamos en derecha
            if(actual == NULL) {
               padre ->right = tempNode;
               return; 
            }
         }
      }
   }
}

void inorder_recorrido(struct node* raiz) {
   if(raiz != NULL) {
      inorder_recorrido (raiz -> left);
      printf("%i \n",raiz->value);
      inorder_recorrido (raiz -> right);
            
  }
}

int main() {
   int i;
   int array[9] = {50,30,24,5,28,45,98,52,60};

   for(i = 0; i < 8; i++)
      insert(array[i]);

    printf("\nInorder: ");
    inorder_recorrido(root);
}