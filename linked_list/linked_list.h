//
// Created by OrangeTien on 2021/12/19.
//

#ifndef DATASTRUCT_LEARN_REPO_LINKED_LIST_H
#define DATASTRUCT_LEARN_REPO_LINKED_LIST_H

typedef int ElementType;
struct Node;
typedef struct Node* PtrNode; // PtrNode a; 相当于定义了一个能够指向链表节点的指针变量a
typedef PtrNode List; // List b; 定义了一个指针变量b，这个b存储的地址一般是表头header的地址
typedef PtrNode Position; // Position c; 定义了一个指针变量c, 这个c一般会遍历整个链表，所以取个position的名字

List InitList(List L);
int IsEmpty( List L );
int IsLast( Position P );
Position Find( ElementType X, List L );
void Delete( ElementType X, List L );
Position FindPrevious( ElementType X, List L );
void Insert( ElementType X, List L, Position P );
void DeleteList( List L );
void PrintList( List L );
ElementType Retrieve( Position P );

struct Node{
    ElementType Element;
    PtrNode Next;
};


#endif //DATASTRUCT_LEARN_REPO_LINKED_LIST_H
