#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode *left, *right;
} TreeNode;

// 노드를 생성하는 함수
TreeNode* createNode(char data) {
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 전위 순회 함수
void preorder(TreeNode *root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 중위 순회 함수
void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

// 후위 순회 함수
void postorder(TreeNode *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

// 노드를 트리에 추가하는 함수
void insertNode(TreeNode **nodes, char parent, char left, char right) {
    if (left != '.') {
        nodes[parent - 'A']->left = nodes[left - 'A'];
    }
    if (right != '.') {
        nodes[parent - 'A']->right = nodes[right - 'A'];
    }
}

int main() {
    int N;
    scanf("%d", &N);

    TreeNode *nodes[26]; // A-Z 까지의 노드를 저장할 포인터 배열
    for(int i = 0; i < N; i++) {
        nodes[i] = createNode('A' + i);
    }

    for(int i = 0; i < N; i++) {
        char parent, left, right;
        scanf(" %c %c %c", &parent, &left, &right);
        insertNode(nodes, parent, left, right);
    }

    preorder(nodes[0]); // 전위 순회
    printf("\n");
    inorder(nodes[0]); // 중위 순회
    printf("\n");
    postorder(nodes[0]); // 후위 순회
    printf("\n");

    // 동적 할당된 메모리 해제
    for(int i = 0; i < N; i++) {
        free(nodes[i]);
    }

    return 0;
}