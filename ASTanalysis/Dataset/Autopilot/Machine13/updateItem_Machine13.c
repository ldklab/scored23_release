int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if (pos == 1) {
        node *curr = *head;
        strcpy(curr->item_name, item_name);
        curr->price = price;
        curr->quantity = quantity;
        return EXIT_SUCCESS;
    }
    node *curr = *head;
    while (curr != NULL && pos > 1) {
        curr = curr->next;
        pos--;
    }
    strcpy(curr->item_name, item_name);
    curr->price = price;
    curr->quantity = quantity;
    return EXIT_SUCCESS;
}