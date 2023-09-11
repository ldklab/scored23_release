int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    node *current = *head;
    node *new_node = malloc(sizeof(node));
    new_node->item_name = item_name;
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = NULL;
    int i=0;
    if (pos==0) {
        new_node->next = *head;
        *head = new_node;
        return EXIT_SUCCESS;
    }
    while (current != NULL && i<pos) {
        if (i+1==pos) {
            new_node->next = current->next;
            current->next = new_node;
            return EXIT_SUCCESS;
        }
        current = current->next;
        i++;
    }
    return EXIT_FAILURE;
}