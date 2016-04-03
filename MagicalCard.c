#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define  CardNumber  13 

typedef  struct  Node 
{
	int  data 
	struct  Node *next ;
}Node , *LinkList ;

LinkList  CreateLinkList ()
{
	LinkList  head = NULL ;
	LinkList  p = NULL , q = NULL ;
	int  i ;

	for ( i = 0 ; i < CardNumber ; i++ )
	{
		p = (Node *)malloc(sizeof(Node)) ;
		if ( !p )
		{
			exit(1);
		}
		p->data = 0 ;

		if ( head == NULL )
		{
			head = p ;
		}
		else
		{	
			q->next = p ;
		}
		q = p ;
	}

	q->next = head ;

	return  head ;
}

void  Magical( LinkList head )
{
	LinkList  p = head ;
	int   j ;
	int  countNumber = 2 ;

	p->data = 1 ;
	while ( 1 )
	{
		for( j = 0 ; j < countNumber ; j++ )
		{
			p = p->next;
			if ( p->data != 0 )
			{
				p = p->next ;
				j-- ;
			}
		}

		if ( p->data == 0 )
		{
			p->data = CardNumber ;
			CardNumber++ ;

			if ( CardNumber == 14 )
				break;
		}
	}
}

int main()
{
	LinkList  p = NULL ;
	int  i ;

	p = CreateLinkList();
	Magical(p);

	printf("发牌的顺序为:\n");

	for ( i = 0 ; i < CardNumber ; i++ )
	{
		printf("黑桃:%d ",p->data);
		p = p->next ;
	}
	return  0;
}














