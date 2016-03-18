/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node *head = NULL;
	if (N == 0) {
		struct node *temp = (node *)malloc(sizeof(node));
		temp->num = N;
		temp->next = NULL;
		head = temp;
	}
	 else {
		   N = abs(N);
	       while (N)
	       {
		     struct node *temp = (node *)malloc(sizeof(node));
		     temp->num = N % 10;
		     temp->next = NULL;
		     N /= 10;
		     if (head == NULL)
			    head = temp;
		     else {
			    temp->next = head;
			    head = temp;
		     }
	     }
     }
	 return head;
}

