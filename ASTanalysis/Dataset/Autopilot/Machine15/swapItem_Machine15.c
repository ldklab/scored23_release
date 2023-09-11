int list_swap_item_positions(node **head, int pos1, int pos2) {
    node *curr1, *curr2, *prev1, *prev2;
    int i;
    
    // check for invalid inputs
    if (head == NULL) return EXIT_FAILURE;
    
    // check if the list is empty
    if (*head == NULL) return EXIT_FAILURE;
    
    // check if the position is past the size of the list
    if (pos1 == 0 || pos2 == 0) return EXIT_FAILURE;
    
    if (pos1 == pos2) return EXIT_SUCCESS;
    
    curr1 = *head;
    for (i = 1; i < pos1; i++) {
        if (curr1->next == NULL) return EXIT_FAILURE;
        prev1 = curr1;
        curr1 = curr1->next;
    }
    
    curr2 = *head;
    for (i = 1; i < pos2; i++) {
        if (curr2->next == NULL) return EXIT_FAILURE;
        prev2 = curr2;
        curr2 = curr2->next;
    }
    
    prev1->next = curr2;
    prev2->next = curr1;
    curr1->next = curr2->next;
    curr2->next = curr1->next;
    curr1->next = curr2;
    
    return EXIT_SUCCESS;
}