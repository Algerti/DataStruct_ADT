//
// Created by OrangeTien on 2021/12/19.
//

#include "linked_list.h"
#include<stdlib.h>
#include<stdio.h>

List InitList(List L){
        L = malloc(sizeof(struct Node));
        L->Next = NULL;  // 返回的是表头，表头的值我们不care，后续的操作会绕开表头
        return L;
}
int IsEmpty( List L ){
    return (L->Next == NULL);
}
int IsLast( Position P ){
    return (P->Next == NULL);
}
Position Find( ElementType X, List L ){
    Position P;
    P = L->Next;
    while( P != NULL && P->Element != X) // 注意看这是怎么写的，非常精炼的写法
        P = P->Next;
    return P;
}
/*
    - 要考虑会不会删除到表头，也就是得绕开表头来删除（插入同理）
    - 要找前驱节点
    正常情况下删除节点的基本思想：先将被删除节点的前驱节点，然后前驱节点的Next指针指向被删除节点的Next指针指向的地址
                             说人话就是：把被删除节点的前一个节点和后一个节点接起来，然后free掉被删除的节点
 */
void Delete( ElementType X, List L ){ // 不过不算 FindPrevious 的时间，Delete的时间复杂度是常数
    Position  previous_node,current_node;
    previous_node = FindPrevious(X,L);
    if(previous_node == L){ // 如果FindPrevious()返回了表头，说明这个链表没有节点
        return;
    }
    if(IsLast(previous_node)){ // 如果FindPrevious()返回了尾节点，说明链表中不存在值为X的节点
        return;
    }
    // 如果返回为正常节点，则正常删除
    current_node = previous_node->Next;
    previous_node->Next = current_node->Next;
    free(current_node);
}
Position FindPrevious( ElementType X, List L ){ // 只可能返回表头，尾节点，以及含有X的节点
    Position P;
    P = L;
    while( P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}
/*
    正常情况下的插入基本思想：先创建一个能指向节点的指针，然后malloc变成一块更大的空间，然后接起来
 */
void Insert( ElementType X, List L, Position P ){ // 插入到p位置之后，时间复杂度是常熟
    Position TmpCell; // 本来TmpCell只是一块存地址的指针变量

    TmpCell= malloc(sizeof(struct Node)); // malloc一下之后，TmpCell存放的仍然是地址，存的是新分配的空间的首地址（OS malloc本质）

    if(TmpCell == NULL){ // 分配失败的话，不知道malloc是不是会返回NULL，这里存疑
            return;
    }
    TmpCell->Element = X;

    if( L->Next == NULL){
        L->Next = TmpCell;
        TmpCell->Next = NULL;
    }
    else{
        TmpCell->Next = P->Next;
        P->Next = TmpCell;
    }
}
void DeleteList( List L ){
    Position P;
    PtrNode Tmp;
    P = L->Next;
    L->Next = NULL; // 表头是不回收的
    while(P != NULL){
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}
void PrintList( List L ){
    Position P;
    P = L->Next;
    while( P != NULL ){
        printf("%d ",P->Element);
        P = P->Next;
    }
    printf("\n");
}

ElementType Retrieve( Position P ){ // Retrieve 是取值的意思
    return P->Element;
}