int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // check the list and the item name
    if (*head == NULL || item_name == NULL) {
        return EXIT_FAILURE;
    }
    // check the pos
    if (pos == 0) {
        return EXIT_FAILURE;
    }
    // if the pos is 1, update the head
    if (pos == 1) {
        (*head)->item_name = strdup(item_name);
        (*head)->price = price;
        (*head)->quantity = quantity;
        return EXIT_SUCCESS;
    }
    // else, update the tail
    node *tail = *head;
    for (int i = 1; i < pos - 1; i++) {
        if (tail->next == NULL) {
            return EXIT_FAILURE;
        }
        tail = tail->next;
    }
    tail->next->item_name = strdup(item_name);
    tail->next->price = price;
    tail->next->quantity = quantity;
    return EXIT_SUCCESS;
}