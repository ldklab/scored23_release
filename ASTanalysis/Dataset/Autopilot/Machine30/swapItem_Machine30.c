int list_swap_item_positions(node **head, int pos1, int pos2) {
    if (pos1 <= 0 || pos2 <= 0) {
        return EXIT_FAILURE;
    }

    if (head == NULL) {
        return EXIT_FAILURE;
    }

    if (pos1 == pos2) {
        return EXIT_SUCCESS;
    }

    if (pos1 > pos2) {
        int tmp = pos1;
        pos1 = pos2;
        pos2 = tmp;
    }

    node *prev1 = NULL;
    node *prev2 = NULL;
    node *current1 = *head;
    node *current2 = *head;
    int i = 1;
    while (current1 != NULL && i < pos1) {
        prev1 = current1;
        current1 = current1->next;
        i++;
    }

    if (current1 == NULL) {
        return EXIT_FAILURE;
    }

    i = 1;
    while (current2 != NULL && i < pos2) {
        prev2 = current2;
        current2 = current2->next;
        i++;
    }

    if (current2 == NULL) {
        return EXIT_FAILURE;
    }

    if (prev1 == NULL) {
        *head = current2;
    } else {
        prev1->next = current2;
    }

    if (prev2 == NULL) {
        *head = current1;
    } else {
        prev2->next = current1;
    }

    node *tmp = current1->next;
    current1->next = current2->next;
    current2->next = tmp;
    
    return EXIT_SUCCESS;
}