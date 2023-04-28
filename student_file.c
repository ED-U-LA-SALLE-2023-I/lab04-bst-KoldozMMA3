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

// Recorrido Preorden
void preorden_recorrido(struct node* raiz) {
    if (raiz != NULL) {
        printf("%i ", raiz->value);
        preorden_recorrido(raiz->left);
        preorden_recorrido(raiz->right);
    }
}
// Recorrido Postorden
void postorden_recorrido(struct node* raiz) {
    if (raiz != NULL) {
        postorden_recorrido(raiz->left);
        postorden_recorrido(raiz->right);
        printf("%i ", raiz->value);
    }
}

// Función principal
char* bst_fun(char* nodes) {
    struct node* raiz = NULL;
    char* token = strtok(nodes, " ");
    while (token != NULL) {
        int value = atoi(token);
        raiz = insert(raiz, value);
        token = strtok(NULL, " ");
    }

    // Imprimir el árbol en Preorden
    printf("Recorrido Preorden: ");
    preorden_recorrido(raiz);
    printf("\n");

    // Imprimir el árbol en Postorden
    printf("Recorrido Postorden: ");
    postorden_recorrido(raiz);
    printf("\n");

    return "Árbol impreso en Preorden y Postorden";

int main() {
    char nodes[100];
    printf("Ingrese los números del árbol separados por espacios: ");
    fgets(nodes, sizeof(nodes), stdin);
    nodes[strcspn(nodes, "\n\n")] = '\0'; // Eliminar el salto de línea final

    bst_fun(nodes);

    return 0;
}