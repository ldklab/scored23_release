int list_swap_item_positions(node **head, int pos1, int pos2) {
    if (pos1 == pos2) {
        return EXIT_SUCCESS;
    }
    if (pos1 == 1 && pos2 == 2) {
        node *curr = *head;
        node *next = curr->next;
        curr->next = next->next;
        next->next = curr;
        *head = next;
        return EXIT_SUCCESS;
    }
    node *prev1 = *head;
    node *curr1 = *head;
    while (curr1 != NULL && pos1 > 1) {
        prev1 = curr1;
        curr1 = curr1->next;
        pos1--;
    }
    node *prev2 = *head;
    node *curr2 = *head;
    while (curr2 != NULL && pos2 > 1) {
        prev2 = curr2;
        curr2 = curr2->next;
        pos2--;
    }
    if (curr1 == NULL || curr2 == NULL) {
        return EXIT_FAILURE;
    }
    if (pos1 == 1) {
        prev2->next = curr1;
        prev1->next = curr2;
        node *temp = curr1->next;
        curr1->next = curr2->next;
        curr2->next = temp;
        *head = curr2;
        return EXIT_SUCCESS;
    }
    if (pos2 == 1) {
        prev1->next = curr2;
        prev2->next = curr1;
        node *temp = curr2->next;
        curr2->next = curr1->next;
        curr1->next = temp;
        *head = curr1;
        return EXIT_SUCCESS;
    }
    prev1->next = curr2;
    prev2->next = curr1;
    node *temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
    return EXIT_SUCCESS;
}