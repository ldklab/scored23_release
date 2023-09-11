int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        return EXIT_FAILURE;
    }
    new_node->item_name = (char *)malloc(sizeof(char) * (strlen(item_name) + 1));
    if (new_node->item_name == NULL) {
        return EXIT_FAILURE;
    }
    strcpy(new_node->item_name, item_name);
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = NULL;
    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        return EXIT_SUCCESS;
    }
    node *prev = *head;
    node *curr = *head;
    while (curr != NULL && pos > 1) {
        prev = curr;
        curr = curr->next;
        pos--;
    }
    new_node->next = curr;
    prev->next = new_node;
    return EXIT_SUCCESS;
}