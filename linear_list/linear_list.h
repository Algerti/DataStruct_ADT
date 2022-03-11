//
// Created by OrangeTien on 2021/11/28.
//

#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#define MAXSIZE 1024

struct _T_linear_list{
    int a[MAXSIZE];
    int a_len;
};

typedef struct _T_linear_list linear_list_t;

typedef enum _T_error_t
{NOERROR, OVERFLOW, SUBSCRIPT,NOELEMENT}
error_t;


typedef int elem_t;
typedef int position;

/* create and destroy the linear list */
linear_list_t *Create(void);
void Destroy(linear_list_t *L);

/* A set of operations */
void    Set_null(linear_list_t *L);   /* empty list*/
int     Length(linear_list_t *L);     /* length of the list */
elem_t  Get(linear_list_t *L, position i); /* get the value */
error_t Insert(linear_list_t *L, elem_t x, position i); /* insert */
error_t Remove(linear_list_t *L, position i);		    /* remove */
position    Locate(linear_list_t *L, elem_t x);/* locate the pos.*/
void    PrintList(linear_list_t* L); /* print the list */

#endif //LINEAR_LIST_H
