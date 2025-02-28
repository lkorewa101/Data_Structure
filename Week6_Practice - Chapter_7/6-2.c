#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode* insert_last(ListNode* head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    strcpy(node->data, data);
    if(head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

int main() {
    ListNode *head = NULL;

    head = insert_last(head, "KIM");
    head = insert_last(head, "JUNG");
    head = insert_last(head, "LEE");
    head = insert_last(head, "CHOI");
    head = insert_last(head, "PARK");

    ListNode* p = head->link;
    for(int i = 0; i < 10; i++) {
        printf("Current turn=%s\n", p->data);
        p = p->link;
    }
    return 0;
}