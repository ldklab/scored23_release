int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    int i = 1;
    node *current = *head;
    while (current != NULL) {
        if (i == pos) {
            free(current->item_name);
            current->item_name = strdup(item_name);
            current->price = price;
            current->quantity = quantity;
            return EXIT_SUCCESS;
        }
        i++;
        current = current->next;
    }
    return EXIT_FAILURE;
}