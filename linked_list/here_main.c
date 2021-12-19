//
// Created by OrangeTien on 2021/12/19.
//

#include<stdio.h>
#include "linked_list.h"

int main(){

    // 先生成一个表头
    List L;
    L = InitList(L);

    // 有了表头就可以插入数据
    Position P;
    Insert(1,L,P);
    P = L->Next;

    int i = 2;
    while(i <= 10){
        Insert(i,L,P);
        P = P->Next;
        i++;
    }

    PrintList(L);

    // 现在是有了一条表,测试一下 Find()
    P = Find(5,L); // 调试观察地址以测试Find()正确性

    // 测试一下 FindPrevious()
    P = FindPrevious(5,L); // 调试观察

    // 测试一下 Delete()
    Delete(5,L);
    PrintList(L);

    // 测试一下 DeleteList()
    DeleteList(L); // 调试观察

    return 0;
}