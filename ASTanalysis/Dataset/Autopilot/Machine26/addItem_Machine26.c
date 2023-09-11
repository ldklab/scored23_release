int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if (*head == NULL || pos == 0) {
        return EXIT_FAILURE;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->item_name = malloc(strlen(item_name) + 1);
    strcpy(new_node->item_name, item_name);
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = NULL;
    int cur_pos = 1;
    node *cur = *head;
    while (cur->next && cur_pos < pos-1) {
        cur = cur->next;
        cur_pos++;
    }
    if (cur_pos == pos-1) {
        new_node->next = cur->next;
        cur->next = new_node;
    } else {
        free(new_node);
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}