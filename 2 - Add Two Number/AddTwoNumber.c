#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void addNode(struct ListNode** list, int value) {
    struct ListNode* element = malloc(sizeof(struct ListNode));
    if (!element)
        return;
    element->val = value;
    element->next = NULL;

    if (*list == NULL) {
        *list = element;
    } else {
        struct ListNode* temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = element;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int value_l1 = 0, value_l2 = 0, final_value = 0, ret = 0;
    struct ListNode* returnList = NULL;

    do {
        value_l1 = 0;
        value_l2 = 0;
        final_value = ret;
        ret = 0;
        if (l1) {
            value_l1 = l1->val;
            l1 = l1->next;
        }
        if (l2) {
            value_l2 = l2->val;
            l2 = l2->next;
        }
        final_value += value_l1 + value_l2;
        if (final_value > 9) {
            ret = final_value / 10;
            final_value = final_value % 10;
        }
        addNode(&returnList, final_value);
    } while (l1 || l2 || ret != 0);
    return returnList;
}

int main(void) {
    struct ListNode *l1, *l2, *returnList;

    l1 = malloc(sizeof(struct ListNode));
    l2 = malloc(sizeof(struct ListNode)); 

    l1->val = 0;
    l1->next = NULL;

    l2->val = 0;
    l2->next = NULL;

    returnList = addTwoNumbers(l1, l2);

    while (returnList) {
        printf("%d\n", returnList->val);
        returnList = returnList->next;
    }

    return 0;
}