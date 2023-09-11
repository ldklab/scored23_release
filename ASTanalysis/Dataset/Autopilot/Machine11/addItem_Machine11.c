int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->item_name = strdup(item_name);
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return EXIT_SUCCESS;
    }

    if (pos == 1) {
        new_node->next = *head;
        *head = new_node;
        return EXIT_SUCCESS;
    }

    int i = 1;
    node *prev = NULL;
    node *current = *head;
    while (current != NULL) {
        if (i == pos) {
            prev->next = new_node;
            new_node->next = current;
            return EXIT_SUCCESS;
        }
        i++;
        prev = current;
        current = current->next;
    }
    if (i == pos) {
        prev->next = new_node;
    }
    return EXIT_SUCCESS;
}