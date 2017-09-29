#include "mylist.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Create a node that holds the given data pointer,
 * and add the node to the front of the list.
 *
 * Note that this function does not manage the lifetime of the object
 * pointed to by 'data'.
 * 
 * It returns the newly created node on success and NULL on failure.
 */
struct Node *addFront(struct List *list, void *data)
{
	struct Node *p = (struct Node *)malloc( ( sizeof(void *) ) * 2 );
	if (p == NULL){
        	perror("malloc returned NULL");
		return NULL;
		exit(1);
	}

	p->next = list->head;
	list->head = p;
	p->data = data;
	return p;
}

/*
 * Traverse the list, calling f() with each data item.
 */
void traverseList(struct List *list, void (*f)(void *))
{

	struct Node *p = list->head;
	
	while(p!=NULL){
		
		(*f)(p->data);
	
		p = p->next;

	}

}

/*
 * Traverse the list, comparing each data item with 'dataSought' using
 * 'compar' function.  ('compar' returns 0 if the data pointed to by
 * the two parameters are equal, non-zero value otherwise.)
 *
 * Returns the first node containing the matching data, 
 * NULL if not found.
 */
struct Node *findNode(struct List *list, const void *dataSought,
        int (*compar)(const void *, const void *))
{

	struct Node *p = list->head;

	while(p->next){
		if( ! ((*compar)(p->data, dataSought)) ){
			return p;
		}
		p = p->next;
	}

	if( ! ((*compar)(p->data, dataSought)) ){
                        return p;
        }

	return NULL;

}

/*
 * Flip the sign of the double value pointed to by 'data' by
 * multiplying -1 to it and putting the result back into the memory
 * location.
 */
void flipSignDouble(void *data)
{
	double toFlip = ( ( * ((double *)data)) );
	toFlip = (toFlip) * (-1);
	(*(double *)data) = toFlip;
}

/*
 * Compare two double values pointed to by the two pointers.
 * Return 0 if they are the same value, 1 otherwise.
 */
int compareDouble(const void *data1, const void *data2)
{

	if (  (*((double *)data1)) == (*((double *)data2)) ){
		return 0;
	}
	return 1;
}

/*
 * Remove the first node from the list, deallocate the memory for the
 * ndoe, and return the 'data' pointer that was stored in the node.
 * Returns NULL is the list is empty.
 */
void *popFront(struct List *list)
{
	if(isEmptyList(list)){
		return NULL;
	}
	struct Node *p = list->head;
	
	list->head = p->next;
	
	void *data = p->data;
	free(p);
	return data;
}

/*
 * Remove all nodes from the list, deallocating the memory for the
 * nodes.  You can implement this function using popFront().
 */
void removeAllNodes(struct List *list)
{
	while(list->head){
		popFront(list);
	}
	
}

/*
 * Create a node that holds the given data pointer,
 * and add the node right after the node passed in as the 'prevNode'
 * parameter.  If 'prevNode' is NULL, this function is equivalent to
 * addFront().
 *
 * Note that prevNode, if not NULL, is assumed to be one of the nodes
 * in the given list.  The behavior of this function is undefined if
 * prevNode does not belong in the given list.
 *
 * Note that this function does not manage the lifetime of the object
 * pointed to by 'data'.
 * 
 * It returns the newly created node on success and NULL on failure.
 */
struct Node *addAfter(struct List *list, struct Node *prevNode, void *data)
{

	if(!prevNode){
		struct Node *p1 = addFront(list, data);
		return p1;
	}

	struct Node *p = (struct Node *)malloc( ( sizeof(void *) ) * 2 );
        if (p == NULL){
                perror("malloc returned NULL");
                return NULL;
		exit(1);
        }
	p->data = data;
	if(!prevNode){
		p->next = prevNode->next;
	}else{
		p->next = 0;
	}
	prevNode->next = p;
	return p;

}

/* 
 * Reverse the list.
 *
 * Note that this function reverses the list purely by manipulating
 * pointers.  It does NOT call malloc directly or indirectly (which
 * means that it does not call addFront() or addAfter()).
 *
 * Implementation hint: keep track of 3 consecutive nodes (previous,
 * current, next) and move them along in a while loop.  Your function
 * should start like this:


      struct Node *prv = NULL;
      struct Node *cur = list->head;
      struct Node *nxt;

      while (cur) {
          ......


 * And at the end, prv will end up pointing to the first element of
 * the reversed list.  Don't forget to assign it to list->head.
 */
void reverseList(struct List *list)
{

	struct Node *prv = NULL;
	struct Node *cur = list->head;
	struct Node *nxt;

	while(cur){
		
		nxt = ((*cur).next);
		((*cur).next) = prv;
		prv = cur;
		cur = nxt;

	}

	list->head = prv;
	
}








