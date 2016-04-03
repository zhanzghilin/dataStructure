#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef  struct Node
{
	int  data ;
	struct  Node *next ;
}Node;

void  ds_init( Node **pNode )
{
	Node  *target , *temp ;
	int  item ;

	printf("请输入要插入节点的值，插入0表示结束输入：");

	while ( 1 ) 
	{
		scanf("%d",&item) ;
		fflush(stdin);

		if ( 0 == item )
		{
			return ;
		}

		if ( NULL == (*pNode) )
		{
			(*pNode) = (Node *)malloc(sizeof(Node)) ;
			if ( !(*pNode) )
			{
				exit(1) ;
			}
			(*pNode)->data = item ;
			(*pNode)->next = (*pNode) ;
		}
		else
		{
			for ( target = (*pNode) ; target->next != (*pNode) ; target = target->next )
				;
			temp = (Node *)malloc(sizeof(Node)) ;
			if ( !temp )
			{
				exit(1);
			}
			temp->data = item ;
			target->next = temp ;
			temp->next = (*pNode) ;
		}
	}
}

void  ds_insert(Node  **pNode , int  i , int  elem)
{
	Node  *target , *temp , *p ;
	int   j = 1;
	int   item ;

	printf("请输入要插入的节点的值:\n");
	scanf("%d",&item);

	if ( 1 == i )
	{
		for ( target = (*pNode) ; target->next != (*pNode) ; target = target->next )
			;
		temp = (Node *)malloc(sizeof(Node)) ;
		if ( !temp )
		{
			exit(1);
		}
		temp->data = item ;
		temp->next = (*pNode) ;
		target->next = temp ;
		(*pNode) = temp ;
 	}
 	else
 	{
 		target = (*pNode) ;
 		for ( ; j < (i-1) ; j++ )
 		{
 			target = target->next ;
 		}

 		temp = (Node *)malloc(sizeof(Node)) ;
 		if ( !temp )
 		{
 			exit(1) ;
 		}
 		temp->data = item ;
 		p = target->next ;
 		target->next = temp ;
 		temp->next = p ;
 	}
}

void  ds_delete( Node **pNode  , int  i )
{
	Node  *target , *temp ;
	int  j = 1 ;

	if ( 1 == i )
	{
		for ( target = (*pNode) ; target->next != (*pNode) ; target = target->next )
			;
		temp = (*pNode) ;
		target->next = (*pNode)->next ;
		free(temp) ;
	}
	else
	{
		target = (*pNode) ;
		for ( ; j < (i-1) ; j++ )
		{
			target = target->next ;
		}

		temp  = target->next ;
		target->next = temp->next ;
		free(temp) ;
	}
}

int  ds_search (Node  *pNode , int  elem )
{
	node  *target ;
	int  i = 1 ;
	for ( target = (*pNode); target->data != elem && target->next != pNode ; i++ )
	{
		target = target->next ;
	}

	if ( target->next == pNode )
		return  0 ;
	else
		return  1 ;
}

void  ds_traverse (Node  *pNode )
{
	Node  *temp ;
	temp = pNode ;

	printf("*****************链表中的元素*****************\n");
	do
	{
		printf("%4d\n", temp->data );
	}while ((temp = temp->next) != pNode );

	printf("\n");
}

int int main(int argc, char const *argv[])
{
	Node  *pHead = NULL ;
	char  opp ;
	int  find ;
	printf("1:初始化链表\n\n2:插入节点\n\n3:删除节点\n\n4:返回节点的位置\n\n5:遍历链表\n\n0:退出\n\n");

	while ( opp != '0' )
	{
		scanf("%d",&opp) ;

		switch( opp )
		{
			case '1' :
				ds_init(&pHead) ;
				printf("\n");
				ds_traverse(pHead) ;
				break;
			case '2' :
				printf("请输入要插入节点的位置？\n");
				scanf("%d",&find) ;
				ds_insert(&pHead,find);
				printf("\n");
				ds_traverse(pHead) ;
				break;
			case '3' :
				printf("请输入要删除节点的位置？\n");
				scanf("%d",&find) ;
				ds_delete(&pHead,find);
				printf("删除地%d个节点后：\n",find );
				ds_traverse(pHead) ;
				break;
			case '4' :
				printf("你要查找的节点的值\n");
				scanf("%d",&find);
				printf("元素的位置在\n",ds_search(pHead,find));
				printf("\n");
				break;
			case '5' :
				ds_traverse(pHead) ;
				printf("\n");
				break;
			case '0' :
				exit(0);
		}
	}
	return 0;
}












