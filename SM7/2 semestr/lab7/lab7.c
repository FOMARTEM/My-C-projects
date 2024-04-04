#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key; //значение
    struct Node* left; //левый узел
    struct Node* right; //правый узел
}Node;

//Создание узла дерева
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
        exit(1);
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//функция добавления значения в дерево
Node* insert(Node* root, int key) { 
    //если корень дерева пустой то он создаёт новое
    if (root == NULL) {
        return createNode(key);
    }
    
    //если ключ меньше ключа в корне то ложим в лево, иначе в право
    if (key < root->key) {
        root->left = insert(root->left, key);
    } 
    else {
        if (key > root->key) {
            root->right = insert(root->right, key);
        }
    }
    
    return root;
}

//функция вывода дерева с лева на право
void printTree(Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->key);
        printTree(root->right);
    }
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    
    if (key < root->key) {
        return search(root->left, key);
    }
    
    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int value; //значение которое будем ложить в дерево
    int n = 0; //количество элементов

    scanf("%d", &value);
    while (value != -1){
        root = insert(root, value);
        printf("Элемент %d добавлен. Результат обхода: ", value);
        printTree(root);
        printf("\n");
        scanf("%d", &value);
    }

    int searchKey;
    printf("Введите число которое хотите найти: ");
    scanf("%d", &searchKey);
    Node* result = search(root, searchKey);

    if (result != NULL) {
        printf("Элемент %d найден в дереве.\n", searchKey);
    } else {
        printf("Элемент %d не найден в дереве.\n", searchKey);
    }

    return 0;
}