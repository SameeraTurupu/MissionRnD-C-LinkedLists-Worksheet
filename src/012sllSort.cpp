/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	if (!head)
		return;
	else {
		struct node *ptr = head;
		int count0 = 0, count1 = 0, count2 = 0;
		while (ptr)
		{
			if (ptr->data == 0)
			    count0++;
			else if (ptr->data == 1)
				count1++;
			else if (ptr->data == 2)
				count2++;
			ptr = ptr->next;
		}
		ptr = head;
		while (count0 > 0)
		{
			if (ptr->data != 0) 
				ptr->data = 0;
			ptr = ptr->next;
			count0--;
		}
		while (count1 > 0)
		{
			if (ptr->data != 1)
			    ptr->data = 1;
			ptr = ptr->next;
			count1--;
		}
		while (count2 > 0)
		{
			if (ptr->data != 2)
			    ptr->data = 2;
			ptr = ptr->next;
			count2--;
		}
		head = ptr;
	}
}
