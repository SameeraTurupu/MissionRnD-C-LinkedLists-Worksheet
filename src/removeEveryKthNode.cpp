/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL || K == 1 || K <= 0)
		return NULL;
	else {
		struct node *cur;
		struct node *prev;
		struct node *temp;

		cur = head;
		int count = 0, index = 0;

		while (cur != NULL)
		{
			count++;
			cur = cur->next;
		}

		if (count < K)
			return head;

		else
		{
			temp = head;
			prev = temp;

			for (index = 1; index <= count; index++){
				if (index % K == 0)
					prev->next = temp->next;
				prev = temp;
				temp = temp->next;
			}

		}
		return head;
	}
}