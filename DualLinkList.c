#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define   OK     1
#define   ERROR  0

typedef  char  ElemType ;
typedef  int   Status ;

typedef  struct  DualNode
{
    ElemType  data ;
    struct  DualNode  *prior ;
    struct  DualNode  *next ;
}DualNode , *DuLinkList ;

Status  InitList ( DuLinkList  *L)
{
    DualNode  *p , *q ;
    int  i ;
    
    (*L) = (DualNode *)malloc(sizeof(DualNode)) ;
    if ( !(*L) )
    {
        return ERROR ;
    }
    
    (*L)->next = (*L)->prior = NULL ;
    
    p = (*L) ;
    
    for( i = 0 ; i < 26 ; i++ )
    {
        q = (DualNode *)malloc(sizeof(DualNode)) ;
        if ( !q )
        {
            return  ERROR ;
        }
        q->data = 'A' + i ;
        q->prior = p ;
        q->next = p->next ;
        p->next = q ;
        p = q ;
    }
    
    p->next = (*L)->next ;
    (*L)->next->prior = p ;
    
    return  OK ;
}

void  Caesar ( DuLinkList  *L , int  i )
{
    if ( i > 0 )
    {
        do
        {
            (*L) = (*L)->next ;
        }while ( --i );
    }
    
    if ( i < 0 )
    {
        i = i - 1 ;
        (*L) = (*L)->next ;
        do
        {
            (*L) = (*L)->prior ;
        }while ( ++i );
    }
}

int main()
{
    DuLinkList  L ;
    int  i , n ;
    
    InitList(&L) ;
    
    printf("请输入一个整数，可以是正数也可以是负数\n");
    while ( scanf("%d",&n) != EOF )
    {
        printf("\n");
    
        Caesar(&L,n);
    
        for ( i = 0 ; i < 26 ;i++ )
        {
            L = L->next ;
            printf("%c->",L->data );
        }
    
        printf("\n");
    }
    return  0;
}

#endif 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define   OK     1
#define   ERROR  0

typedef   char   ElemType ;
typedef   int    Status ;

typedef   struct  DualNode
{
    ElemType  data ;
    struct  DualNode  *prior ;
    struct  DualNode  *next ;
}DualNode , *DuLinkList ;

Status  InitList ( DuLinkList  *L )
{
    DuLinkList  p , q ;
    int  i ;

    (*L) = (DualNode *)malloc(sizeof(DualNode)) ;
    if ( !(*L) )
    {
        return  ERROR ;
    }
    (*L)->next = (*L)->prior = NULL ;
    
    q = (*L) ;

    for ( i = 0 ; i < 26 ; i++ )
    {
        p = (DualNode *)malloc(sizeof(DualNode)) ; 
        if( !p )
        {
            return  ERROR ;
        }
        p->data = 'A' + i ;

        p->prior = q ;
        p->next = q->next ;
        q->next = p ;

        q = p ;
    }

    p->next = (*L)->next ;
    (*L)->next->prior = p ;

    free(*L) ;

    return  OK ;
}

void  Caesar ( DuLinkList  *L , int  i )
{
    if ( i > 0 )
    {
        do
        {
            (*L) = (*L)->next ;
        }while ( --i );
    }
    
    if ( i < 0 )
    {
        i = i - 1 ;
        (*L) = (*L)->next ;
        do
        {
            (*L) = (*L)->prior ;
        }while ( ++i );
    }
}

int main()
{
    DuLinkList  L ;
    int  i , n ;
    
    InitList(&L) ;
    
    printf("请输入一个整数，可以是正数也可以是负数\n");
    while ( scanf("%d",&n) != EOF )
    {
        printf("\n");
    
        Caesar(&L,n);
    
        for ( i = 0 ; i < 26 ;i++ )
        {
            L = L->next ;
            printf("%c->",L->data );
        }
    
        printf("\n");
    }
    return  0;
}













