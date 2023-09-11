int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // check the list and the item name
    if (*head == NULL || item_name == NULL) {
        return EXIT_FAILURE;
    }
    // check the pos
    if (pos == 0) {
        return EXIT_FAILURE;
    }
    // create a new node
    node *new_node = malloc(sizeof(node));
    new_node->item_name = strdup(item_name);
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = NULL;
    // if the pos is 1, add the node to the head
    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        return EXIT_SUCCESS;
    }
    // else, add the node to the tail
    node *tail = *head;
    for (int i = 1; i < pos - 1; i++) {
        if (tail->next == NULL) {
            return EXIT_FAILURE;
        }
        tail = tail->next;
    }
    new_node->next = tail->next;
    tail->next = new_node;
    return EXIT_SUCCESS;
}