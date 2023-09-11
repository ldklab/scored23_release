int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    node *curr;
    int i;
    
    // check for invalid inputs
    if (head == NULL || item_name == NULL || quantity <= 0) return EXIT_FAILURE;
    
    // check if the list is empty
    if (*head == NULL) return EXIT_FAILURE;
    
    curr = *head;
    for (i = 1; i < pos; i++) {
        if (curr->next == NULL) return EXIT_FAILURE;
        curr = curr->next;
    }
    
    curr->item_name = item_name;
    curr->price = price;
    curr->quantity = quantity;
    
    return EXIT_SUCCESS;
}