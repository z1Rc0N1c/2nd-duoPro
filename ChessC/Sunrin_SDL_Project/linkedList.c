#include "pch.h"
#include "linkedList.h"
#include <stdlib.h>
#include <memory.h>

void list_init(List* list) {
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
}

int list_push(List* list, void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1; // �޸� �Ҵ� ����
    }
    newNode->next = NULL;
    newNode->val = data;

    if (list->head == NULL) {
        // ����Ʈ�� ������� ���
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        // �� �ڿ� ��带 �߰��ϴ� ���̹Ƿ�, tail�� ���� Node�� newNode�� �����մϴ�.
        // 
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->len++;
    return 1; // ������ �߰� ����
}

int list_insert(List* list, int index, void* data) {
    if (index < 0 || index > list->len) {
        return 0; // ��ȿ���� ���� �ε���
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return 0; // �޸� �Ҵ� ����
    }

    newNode->val = data;

    if (index == 0) {
        // ����Ʈ�� �� �տ� ����
        newNode->next = list->head;
        list->head = newNode;

        if (list->tail == NULL) {
            // ����Ʈ�� ����ִ� ���
            list->tail = newNode;
        }
    }
    else {
        // ����Ʈ�� �߰��̳� �� �ڿ� ����
        Node* prevNode = list->head;

        // index���� �������� �̵�
        for (int i = 1; i < index; i++) {
            prevNode = prevNode->next;
        }

        // ���� node ����
        newNode->next = prevNode->next;
        prevNode->next = newNode;

        if (newNode->next == NULL) {
            // ����Ʈ�� �� �ڿ� ����
            list->tail = newNode;
        }
    }

    list->len++;
    return 1; // ������ �߰� ����
}

void* list_pop(List* list, int index) {
    if (index < 0 || index >= list->len) {
        return NULL; // ��ȿ���� ���� �ε���
    }

    // ���� ��� ����
    Node* removedNode;

    if (index == 0) {
        // ����Ʈ�� �� �� ��� ����
        removedNode = list->head;
        list->head = removedNode->next;

        if (list->tail == removedNode) {
            // ����Ʈ�� ��尡 �ϳ��� �־��� ���
            list->tail = NULL;
        }
    }
    else {
        // ����Ʈ�� �߰��̳� �� �� ��� ����
        Node* prevNode = list->head;

        // �ش� �ε��� ���� �̵�
        for (int i = 1; i < index; i++) {
            prevNode = prevNode->next;
        }

        // ��峢�� ����
        removedNode = prevNode->next;
        prevNode->next = removedNode->next;

        if (removedNode == list->tail) {
            // ����Ʈ�� �� �� ��� ����
            list->tail = prevNode;
        }
    }

    void* val = removedNode->val;
    free(removedNode);
    list->len--;
    return val; // ��� ���� ����, val�� ��ȯ�մϴ�.
}

void* list_remove(List* list, void* data) {
    Node* prevNode = NULL;
    Node* currentNode = list->head;

    while (currentNode != NULL) {
        if (currentNode->val == data) {
            if (prevNode == NULL) {
                // ���� ��尡 head�� ���
                // ����Ʈ�� �� �� ��� ����
                list->head = currentNode->next;

                if (list->tail == currentNode) {
                    // ����Ʈ�� ��尡 �ϳ��� �־��� ���
                    list->tail = NULL;
                }
            }
            else {
                // ����Ʈ�� �߰��̳� �� �� ��� ����
                prevNode->next = currentNode->next;

                if (currentNode == list->tail) {
                    // ����Ʈ�� �� �� ��� ����
                    list->tail = prevNode;
                }
            }

            void* val = currentNode->val;
            free(currentNode);
            list->len--;
            return val; // ��� ���� ����, val�� ��ȯ�մϴ�.
        }

        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    return NULL; // �����͸� ã�� ����
}

void* list_search(List* list, int index) {
    if (index < 0 || index >= list->len) {
        return NULL; // ��ȿ���� ���� �ε���
    }

    Node* currentNode = list->head;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }

    return currentNode->val;
}

void list_releaseList(List* list) {
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        Node* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
}

void list_releaseListWVal(List* list)
{
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        Node* nextNode = currentNode->next;
        free(currentNode->val);
        free(currentNode);
        // free(currentNode->val);
        currentNode = nextNode;
    }
    list->head = NULL;
    list->tail = NULL;
    list->len = 0;
}
