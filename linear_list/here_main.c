//
// Created by AlgerTien on 2021/11/21.
//

#include "stdio.h"
#include "linear_list.h"

int main(){

    // debug Create()
    linear_list_t* list;
    list = Create();
    error_t info = 2;

    // debug Insert()
    info = Insert(list,10,0);
    PrintList(list);

    int j = 1;
    while(j < 7){
        Insert(list,2*j,j);
        j++;
    }

    PrintList(list);

    // debug Get()
    elem_t tmp1,tmp2;
    tmp1 = Get(list,2);
    tmp2 = Get(list,4);


    // debug Remove()
    info = Remove(list,3);
    PrintList(list);


    // debug Locate()
    position p;
    p = Locate(list,12);
    if(p == -1) {
        printf("Not Found!");
    }
    else{
        printf("Position is %d.",p);
    }

    Set_null(list);
    Destroy(list);


    return 0;
}