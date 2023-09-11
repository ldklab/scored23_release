int list_swap_item_positions(node **head, int pos1, int pos2) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node *curr1 = *head;
    node *prev1 = NULL;
    int i1 = 1;
    node *curr2 = *head;
    node *prev2 = NULL;
    int i2 = 1;
    
    // search for the 2 nodes
    while (i1 < pos1) {
        if (curr == NULL) {
            printf("pos1 is out of range: There is not enough items!\n")
            return EXIT_FAILURE;    // Out of range: There is not enough items
        }
        prev1 = curr1;
        curr1 = curr1->next;
        i1++;
    }
    while (i2 < pos2) {
        if (curr == NULL) {
            printf("pos is out of range: There is not enough items!\n")
            return EXIT_FAILURE;    // Out of range: There is not enough items
        }
        prev2 = curr2;
        curr2 = curr2->next;
        i2++;
    }

    // swap
    if ((curr1 == NULL) || (curr2 == NULL)) {
        printf("At least one of the positions does not have an item!\n");
        return EXIT_FAILURE;        // Nothing is done/changed: success
    }
    prev1->next=curr2;
    prev2->next=curr1;

    node *temp = curr2->next;
    curr2->next = curr1->next;  //change curr2->next
    curr1->next = temp;
    return EXIT_SUCCESS;
}