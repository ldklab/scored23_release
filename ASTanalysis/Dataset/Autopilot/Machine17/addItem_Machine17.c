int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if (head == NULL || item_name == NULL) {
        printf("Error: list_add_item_at_pos\n");
        return EXIT_FAILURE;
    }
    node *curr = *head;
    node *prev = NULL;
    while (curr != NULL) {
        if (pos == 0) {
            node *new_node = malloc(sizeof(node));
            new_node->item_name = item_name;
            new_node->price = price;
            new_node->quantity = quantity;
            new_node->next = curr;
            *head = new_node;
            return EXIT_SUCCESS;
        }
        pos--;
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) {
        printf("Error: list_add_item_at_pos\n");
        return EXIT_FAILURE;
    }
    node *new_node = malloc(sizeof(node));
    new_node->item_name = item_name;
    new_node->price = price;
    new_node->quantity = quantity;
    prev->next = new_node;
    new_node->next = curr;
    return EXIT_SUCCESS;
}