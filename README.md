# LinkedList
A Linked List implemented in C






## Functions

**addFront(struct List *list, void *data)**: Creates a node that holds the given data pointer, and adds the node to the front of the list. Note: this function does not manage the lifetime of the object pointed to by 'data'. Returns the newly created node on success and NULL on failure.

**traverseList(struct List *list, void(*f)(void *))**: Traverse the list, calling f() with each data item.

**findNode(struct List *list, const void *dataSought, int (*compar)(const void *, const void *))**: Traverses the list comparing each data item with the 'dataSought' using 'compar' function. ('compar' returns 0 if the data pointed to by the two parameters are equal, non-zero value otherwise.) Returns the first node containing the matching data, NULL if not found.

**flipSignDouble(void *data)**: Flip the sign of the double value pointed to by 'data' by ultiplying -1 to it and putting the result back into the memory location.

**compareDouble(const void *data1, const void *data2)**: Compare two double values pointed to by the two pointer arguments. Returns 0 if same value, 1 otherwise.

**popFront(struct List *list)**: Removes the first node from the list, deallocate the memory for the node, and return the 'data' pointer that was stored in the node. Returns NULL is the list is empty.

**removeAllNodes(struct List *list)**: Remove all nodes from the list, deallocating the memory for the nodes.

**addAfter(struct List *list, struct Node *prevNode, void *data)**: Creates a node that holds the given data pointer, and adds the node right after the node passed in as the 'prevNode' parameter. If 'prevNode' is NULL, this function is equivalent to addFront(). Note that prevNode, if not NULL, is assumed to be one of the nodes in the given list.  The behavior of this function is undefined if prevNode does not belong in the given list. Note that this function does not manage the lifetime of the object pointed to by 'data'. Returns the newly created node on success and NULL on failure.

**reverseList(struct List *list)**: Reverses the list. This function reverses the list purely by manipulating pointers.




