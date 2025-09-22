#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node *root = NULL;

// Create new node
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert node
void insert(struct Node **node, int key) {
    if (*node == NULL) {
        *node = newNode(key);
        return;
    }
    if (key < (*node)->key)
        insert(&((*node)->left), key);
    else if (key > (*node)->key)
        insert(&((*node)->right), key);
}

// Inorder traversal
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

// Preorder traversal
void preorder(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->key);
        preorder(node->left);
        preorder(node->right);
    }
}

// Postorder traversal
void postorder(struct Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->key);
    }
}

// Search a node
void search(struct Node* node, int key) {
    if (node == NULL) {
        printf("%d Not Found\n", key);
        return;
    }
    if (key == node->key) {
        printf("%d Found\n", key);
    } else if (key < node->key) {
        search(node->left, key);
    } else {
        search(node->right, key);
    }
}

// Find minimum value node (for deletion)
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete node (helper returns pointer)
struct Node* deleteNode(struct Node* node, int key) {
    if (node == NULL) return node;

    if (key < node->key) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->key) {
        node->right = deleteNode(node->right, key);
    } else {
        // Case 1: No child
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }
        // Case 2: One child
        else if (node->left == NULL) {
            struct Node* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct Node* temp = node->left;
            free(node);
            return temp;
        }
        // Case 3: Two children
        struct Node* temp = minValueNode(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}

// Wrapper for deletion to keep void type
void deleteKey(int key) {
    root = deleteNode(root, key);
}

// Main menu-driven function
void main() {
    int choice, key;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &key);
                insert(&root, key);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &key);
                search(root, key);
                break;
            case 4:
                printf("Inorder Traversal: ");

Leo, [22-09-2025 21:57]
inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

}
