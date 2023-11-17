#pragma once

// ����ü type ����
typedef struct node Node;
typedef struct list List;

struct node {
    void* val;
    struct node* next;
};

struct list {
    struct node* head;
    struct node* tail;
    int len;
};

// ����Ʈ�� �ʱ�ȭ �մϴ�.
void list_init(List* list);

// ����Ʈ �� �ڿ� �����͸� �߰��մϴ�.
int list_push(List* list, void* data);

// ���ϴ� ��ġ�� �����͸� �߰��մϴ�.
int list_insert(List* list, int index, void* data);

// ��ġ�� ������� Node�� �����մϴ�.
void* list_pop(List* list, int index);

// �����͸� ������� Node�� �����մϴ�.
void* list_remove(List* list, void* data);

// ��ġ�� ������� Ž���մϴ�.
void* list_search(List* list, int index);

// ����Ʈ ��ü�� �����ϴ� �Լ�
void list_releaseList(List* list);

// ����Ʈ ��ü�� �����ϴ� �Լ�
void list_releaseListWVal(List* list);
