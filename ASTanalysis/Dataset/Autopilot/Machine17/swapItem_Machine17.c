int list_swap_item_positions(node **head, int pos1, int pos2) {
    if (head == NULL) {
        printf("Error: list_swap_item_positions\n");
        return EXIT_FAILURE;
    }
    node *curr = *head;
    node *prev1 = NULL;
    node *prev2 = NULL;
    while (curr!= NULL) {
        if (pos1 == 0) {
            prev1 = NULL;
        }
        if (pos2 == 0) {
            prev2 = NULL;
        }
        if (pos1 == 0 && pos2 == 0) {
            node *tmp = curr->next;
            curr->next = tmp->next;
            tmp->next = curr;
            if (prev1 == NULL) {
                *head = tmp;
            } else {
                prev1->next = tmp;
            }
            if (prev2 == NULL) {
                *head = curr;
            } else {
                prev2->next = curr;
            }
            return EXIT_SUCCESS;
        }
        pos1--;
        pos2--;
        prev1 = curr;
        curr = curr->next;
    }
    printf("Error: list_swap_item_positions\n");
    return EXIT_FAILURE;
}