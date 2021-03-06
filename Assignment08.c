//
// Assignment08.c
// 204251 Data Structure
//
// Kasidis Torcharoen
// 610510531
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BinaryNode {
    int item;
    struct BinaryNode *left, *right;
} node;

node *root = NULL;

node *generateNode(int data) {
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

bool hasLeft(node *p) { return (p->left != NULL); }
bool hasRight(node *p) { return (p->right != NULL); }

void preOrder(node *p) {
    printf("%d ", p->item);
    if (hasLeft(p)) { preOrder(p->left); }
    if (hasRight(p)) { preOrder(p->right); }
}

void inOrder(node *p) {
    if (hasLeft(p)) { inOrder(p->left); }
    printf("%d ", p->item);
    if (hasRight(p)) { inOrder(p->right); }
}

void postOrder(node *p) {
    if (hasLeft(p)) { postOrder(p->left); }
    if (hasRight(p)) { postOrder(p->right); }
    printf("%d ", p->item);
}

node *insert(int data) {
    node *new_node = generateNode(data);
    node *ptr, *leaf;
    if (root == NULL) { root = new_node; }
    else {
        ptr = root;
        while (ptr != NULL) {
            leaf = ptr;
            if (ptr->item > new_node->item) { ptr = ptr->left; }
            else { ptr = ptr->right; }
        }
        if (leaf->item > new_node->item) { leaf->left = new_node; }
        else { leaf->right = new_node; }
    }

    return root;

}

int main() {
    int N, cin;
    scanf("%d", &N);
    while (N-->0) {
        scanf("%d", &cin);
        insert(cin);
    }

    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
}