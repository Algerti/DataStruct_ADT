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
/*
查找方法：
    第一看树是不是为空，为空则直接返回NULL,停止查找
    第二看查找的值X与根节点比较
        如果比根节点内的值大，则在右子树中递归查找
        如果比根节点内的值小，则在左子树中递归查找
        如果等于根节点内的值，直接返回根节点地址即可
    第三,如果遍历结束后并没有查找到对应的位置,那么递归例程会从第一步设置的出口中跳出来
注意：对于一种数据结构，如果想要查询其中的数据，首先我们能想到的就是直接遍历这个数据结构，然后一个个的分析比对
     对于bst，这里查找的方法跟之前的查找方法有所不同，主要是与bst的特性以及树的遍历方法有关
 */
Position Find(ElementType X,SearchTree T){
    if (T == NULL)
        return NULL;
    else if (X < T->Element){ // 注意：为什么要return,这个问题要想清楚（不return的话，即使能找到对应位置，也无法将位置传递出来）
        return Find(X,T->Left); // 在一个返回值非void的函数中，必须要return回对应类型的值，否则会报错
    }
    else if (X > T->Element){
        return Find(X,T->Right);
    }
    else
        return T;
}

/*
查最小值：
    根据二叉树的特性，最小值肯定存在于左子树的最左端，所以：
        1.设置递归出口，也是 T->Left == NULL 的时候（说明此节点为树叶）
        2.一直递归遍历左子树，找到此树中最左端的节点
        3.获取该节点地址，并且通过return一层层的将此地址传出去
 */
Position FindMin(SearchTree T){
    if (T == NULL) // 此处并非递归出口，只是预防空树的情况，
        return NULL;
    else if (T->Left == NULL) // 此处也是递归出口，寻找最左边的树叶，寻找到之后返回树叶的地址
        return T;
    else
        return FindMin(T->Left);
}
Position FindMax(SearchTree T){ // 为了凸显递归与循环遍历的不同之处，此处的FindMax的实现采用非递归
    if (T == NULL)
        return NULL;

}
SearchTree Insert(SearchTree T,ElementType X){

}
SearchTree Delete(SearchTree T,ElementType X);
ElementType Retrieve(Position P);
