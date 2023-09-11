int list_swap_item_positions(node **head, int pos1, int pos2) {
    node *curr1 = *head;
    node *prev1 = NULL;
    node *curr2 = *head;
    node *prev2 = NULL;
    int i = 1;

    if (head == NULL) {
        return EXIT_FAILURE;
    }

    if (pos1 == pos2) {
        return EXIT_SUCCESS;
    }

    while (curr1 != NULL) {
        if (i == pos1) {
            break;
        }
        prev1 = curr1;
        curr1 = curr1->next;
        i++;
    }
    i = 1;
    while (curr2 != NULL) {
        if (i == pos2) {
            break;
        }
        prev2 = curr2;
        curr2 = curr2->next;
        i++;
    }

    if (pos1 == 0) {
        curr2->next = curr1;
        prev1->next = curr2;
        *head = curr2;
        return EXIT_SUCCESS;
    }
    if (pos2 == 0) {
        curr1->next = curr2;
        prev2->next = curr1;
        *head = curr1;
        return EXIT_SUCCESS;
    }

    prev1->next = curr2;
    node *temp = curr2->next;
    curr2->next = curr1->next;
    prev2->next = curr1;
    curr1->next = temp;
    return EXIT_SUCCESS;
}