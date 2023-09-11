int list_swap_item_positions(node **head, int pos1, int pos2) {
    if (*head == NULL) {
        return EXIT_FAILURE;
    }

    if (pos1 == pos2) {
        return EXIT_SUCCESS;
    }

    int i = 1;
    node *prev1 = NULL;
    node *prev2 = NULL;
    node *current1 = *head;
    while (current1 != NULL) {
        if (i == pos1) {
            break;
        }
        i++;
        prev1 = current1;
        current1 = current1->next;
    }

    if (current1 == NULL) {
        return EXIT_FAILURE;
    }

    i = 1;
    node *current2 = *head;
    while (current2 != NULL) {
        if (i == pos2) {
            break;
        }
        i++;
        prev2 = current2;
        current2 = current2->next;
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
    node *temp = current1->next;
    current1->next = current2->next;
    current2->next = temp;
    return EXIT_SUCCESS;
}