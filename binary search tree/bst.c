//
// Created by Alger Tien on 11/3/2022.
//

#include "bst.h"
#include "stdlib.h"

struct TreeNode{
    ElementType Element;
    PtrToNode Left;
    PtrToNode Right;
};

SearchTree MakeEmpty(SearchTree T){
    PtrToNode Current_Node = T; // 这里可以不需要这一步定义，我这这么写纯属为了方便自己理解
    if(Current_Node != NULL){ // 得益于递归的使用，本来是单个节点的操作变成了对于一个整体的操作，非常的精妙
        MakeEmpty(Current_Node->Left);
        MakeEmpty(Current_Node->Right);
        free(Current_Node);
    }
    return NULL;
}
Position Find(ElementType X){

}
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(SearchTree T,ElementType X);
SearchTree Delete(SearchTree T,ElementType X);
ElementType Retrieve(Position P);
