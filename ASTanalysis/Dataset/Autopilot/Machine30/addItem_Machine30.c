int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if (pos <= 0) {
        return EXIT_FAILURE;
    }

    if (head == NULL) {
        return EXIT_FAILURE;
    }

    node *prev = NULL;
    node *current = *head;
    int i = 1;
    while (current != NULL && i < pos) {
        prev = current;
        current = current->next;
        i++;
    }

    if (current != NULL) {
        if (prev == NULL) {
            prev = (node *) malloc(sizeof(node));
            *head = prev;
        } else {
            prev->next = (node *) malloc(sizeof(node));
            prev = prev->next;
        }
        prev->item_name = item_name;
        prev->price = price;
        prev->quantity = quantity;
        prev->next = current;
        return EXIT_SUCCESS;
    } else {
        current = (node *) malloc(sizeof(node));
        current->item_name = item_name;
        current->price = price;
        current->quantity = quantity;
        current->next = NULL;
        if (prev == NULL) {
            *head = current;
        } else {
            prev->next = current;
        }
        return EXIT_SUCCESS;
    }
}