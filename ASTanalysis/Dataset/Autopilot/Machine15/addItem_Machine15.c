int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    node *curr, *new_node;
    int i;
    
    // check for invalid inputs
    if (head == NULL || item_name == NULL || quantity <= 0) return EXIT_FAILURE;
    
    // check if the list is empty
    if (*head == NULL) {
        *head = malloc(sizeof(node));
        (*head)->item_name = item_name;
        (*head)->price = price;
        (*head)->quantity = quantity;
        (*head)->next = NULL;
        return EXIT_SUCCESS;
    }
    
    // check if the position is past the size of the list
    if (pos == 0) {
        new_node = malloc(sizeof(node));
        new_node->item_name = item_name;
        new_node->price = price;
        new_node->quantity = quantity;
        new_node->next = *head;
        *head = new_node;
        return EXIT_SUCCESS;
    }
    
    curr = *head;
    for (i = 1; i < pos; i++) {
        if (curr->next == NULL) return EXIT_FAILURE;
        curr = curr->next;
    }
    
    new_node = malloc(sizeof(node));
    new_node->item_name = item_name;
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = curr->next;
    curr->next = new_node;
    
    return EXIT_SUCCESS;
}