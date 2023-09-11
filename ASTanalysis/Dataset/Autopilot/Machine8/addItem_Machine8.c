int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    int result = EXIT_SUCCESS;
    node *new_node = NULL;

    if (pos == 0) {
        new_node = malloc(sizeof(node));
        new_node->next = *head;
        *head = new_node;
    } else {
        node *current = *head;
        node *prev = NULL;
        int i = 0;

        while (i < pos) {
            prev = current;
            current = current->next;
            i++;
        }

        new_node = malloc(sizeof(node));
        new_node->next = current;
        prev->next = new_node;
    }

    if (new_node != NULL) {
        new_node->item_name = (char *)malloc(strlen(item_name) + 1);
        strcpy(new_node->item_name, item_name);
        new_node->price = price;
        new_node->quantity = quantity;
    } else {
        result = EXIT_FAILURE;
    }

    return result;
}