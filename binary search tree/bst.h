//
// Created by Alger Tien on 11/3/2022.
//

#ifndef BST_H
#define BST_H
struct TreeNode;
typedef int ElementType;
typedef struct TreeNode* PtrToNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(SearchTree T,ElementType X);
SearchTree Delete(SearchTree T,ElementType X);
ElementType Retrieve(Position P); // 根据位置找对应的值 | Retrieve的意思是检索,获取

#endif
