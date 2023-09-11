int list_find_highest_price_item_position(node *head, int *pos) {
    node *curr;
    int i, highest_price_pos = 0;
    float highest_price = 0;
    
    // check for invalid inputs
    if (head == NULL || pos == NULL) return EXIT_FAILURE;
    
    // check if the list is empty
    if (head == NULL) return EXIT_FAILURE;
    
    curr = head;
    for (i = 0; curr != NULL; curr = curr->next, i++) {
        if (curr->price > highest_price) {
            highest_price = curr->price;
            highest_price_pos = i;
        }
    }
    
    *pos = highest_price_pos;
    return EXIT_SUCCESS;
}