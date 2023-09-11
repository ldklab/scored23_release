int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if (pos <= 0) {
        return EXIT_FAILURE;
    }

    if (head == NULL) {
        return EXIT_FAILURE;
    }

    node *current = *head;
    int i = 1;
    while (current != NULL && i < pos) {
        current = current->next;
        i++;
    }

    if (current != NULL) {
        current->item_name = item_name;
        current->price = price;
        current->quantity = quantity;
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}