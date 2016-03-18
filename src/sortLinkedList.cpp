/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include <malloc.h>
struct node {
	int num;
	struct node *next;
};
struct node*mergesort(struct node *head);
struct node *merge(struct node *one, struct node *two);

struct node *mergesort(struct node *head){

	struct node *head_left;
	struct node *head_right;
	if ((head == NULL) || (head->next == NULL))
		return head;
	head_left = head;
	head_right = head->next;
	while ((head_right != NULL) && (head_right->next != NULL)){
		head = head->next;
		head_right = head->next->next;
	}
	head_right = head->next;
	head->next = NULL;
	return merge(mergesort(head_left), mergesort(head_right));
}
struct node *merge(struct node*head_left, struct node*head_right){

	struct node *head_mid;
	if (head_left == NULL)
		return head_right;
	if (head_right == NULL)
		return head_left;
	if (head_left->num <head_right->num ){

		head_mid = head_left;
		head_mid->next = merge(head_left->next, head_right);
	}
	else
	{

		head_mid = head_right;
		head_mid->next = merge(head_left, head_right->next);


	}

	return head_mid;
}
struct node * sortLinkedList(struct node *head) {
	head = mergesort(head);
	return head;
}