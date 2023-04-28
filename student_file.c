#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definimos variables
struct node {
    int value;
    struct node *left;
    struct node *right;
};
// Función para crear un nuevo nodo
struct node* new_node(int value) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insertamos un nuevo nodo en el árbol
struct node* insert(struct node* raiz, int value) {
    if (raiz == NULL) {
        return new_node(value);
    }
    if (value < raiz->value) {
        raiz->left = insert(raiz->left, value);
    } else {
        raiz->right = insert(raiz->right, value);
    }
    return raiz;
}

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