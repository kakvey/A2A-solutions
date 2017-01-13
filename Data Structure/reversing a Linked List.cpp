#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>

/* structure containing a data part and link part */
struct node
{
	int data ;
	struct node *link ;
} ;

void addatbeg ( struct node **, int ) ;
void reverse ( struct node ** ) ;
void display ( struct node * ) ;
int count ( struct node * ) ;

int main( )
{
	struct node *p ;
	p = NULL ;  /* empty linked list */

	addatbeg ( &p, 7 ) ;
	addatbeg ( &p, 43 ) ;
	addatbeg ( &p, 17 ) ;
	addatbeg ( &p, 3 ) ;
	addatbeg ( &p, 23 ) ;
	addatbeg ( &p, 5 ) ;

	system ( "cls" ) ;

	display ( p ) ;
	printf ( "No. of elements in the linked list = %d\n", count ( p ) ) ;

	reverse ( &p ) ;
	display ( p ) ;
	printf ( "No. of elements in the linked list = %d\n", count ( p ) ) ;
	return 0 ;
}

/* adds a new node at the beginning of the linked list */
void addatbeg ( struct node **q, int num )
{
	struct node *temp ;

	/* add new node */
	temp = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
	temp -> data = num ;
	temp -> link = *q ;
	*q = temp ;
}

void reverse ( struct node **x )
{
	struct node *q, *r, *s ;

	q = *x ;
	printf("%d \n",q);
	r = NULL ;
	
		printf("%d \n",r);

	/* traverse the entire linked list */
	while ( q != NULL )
	{
		s = r ;
		printf("%d \n",s);
		r = q ;
		printf("%d \n",r);
		q = q -> link ;
		printf("%d \n",q -> link);
		r -> link = s ;
	//	printf("%d \n",s);
		printf("%d \n",r -> link);
	}

	*x = r ;
	printf("%d \n",r);
}

/* displays the contents of the linked list */
void display ( struct node *q )
{
	/* traverse the entire linked list */
	while ( q != NULL )
	{
		printf ( "%d ", q -> data ) ;
		q = q -> link ;
	}
	printf ( "\n" ) ;
}

/* counts the number of nodes present in the linked list */
int count ( struct node * q )
{
	int c = 0 ;

	/* traverse the entire linked list */
	while ( q != NULL )
	{
		q = q -> link ;
		c++ ;
	}

	return c ;
}


