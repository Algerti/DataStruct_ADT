//
// Created by OrangeTien on 2021/11/28.
//

#include "linear_list.h"
#include <stdlib.h>
#include <stdio.h>

/* create and destroy the linear list */
linear_list_t *Create(void){

   linear_list_t* list = malloc(sizeof(linear_list_t));
   if(list){
       list->a_len = 0;
       // 使用 memset(a, 0, sizeof(a)) 可以重置定义后的数组为0
   }
   return list;
}

void Destroy(linear_list_t *L){
    free(L);
}

/* A set of operations */
void    Set_null(linear_list_t *L){
    // 数据变为0
    int i = 0;
    while(i < L->a_len){
        L->a[i] = 0; // L->a+i = 0;
        i++;
    }

    // 长度变为0
    L->a_len = 0;

}   /* empty list*/
int     Length(linear_list_t *L){

    return L->a_len;

}     /* length of the list */
elem_t  Get(linear_list_t *L, position i){

    if(i<0 || i>L->a_len)
        printf("i is illegal!");

    return L->a[i];

} /* get the value */
error_t Insert(linear_list_t *L, elem_t x, position i){
    if(i<0 || i>L->a_len)
        return SUBSCRIPT;

    int j = L->a_len-1;
    while(j > i){
        L->a[j] = L->a[j-1];
        j--;
    }
    L->a[i] = x;
    L->a_len++;
    return NOERROR;

} /* insert */
error_t Remove(linear_list_t *L, position i){
    if(i<0 || i>L->a_len)
        return SUBSCRIPT;
    if(L->a_len == 0)
        return NOELEMENT;

    while(i < L->a_len-1){
        L->a[i] = L->a[i+1];
        i++;
    }
    L->a[L->a_len-1] = 0;
    L->a_len--;
    return NOERROR;
}		    /* remove */
position    Locate(linear_list_t *L, elem_t x){ // 只支持找到第一个element的位置
    int i = 0;
    while(i < L->a_len){
        if(L->a[i] == x) return i;
        i++;
    }
    return -1; // Not Found!

}/* locate the pos.*/
void    PrintList(linear_list_t* L){
    int i = 0;
    printf("List is: ");

    while(i < L->a_len){
        printf("%d ",L->a[i]);
        i++;
    }

    printf("\n");
}