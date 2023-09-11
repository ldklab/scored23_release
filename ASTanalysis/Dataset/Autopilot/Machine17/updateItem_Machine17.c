int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    if (head == NULL || item_name == NULL) {
        printf("Error: list_update_item_at_pos\n");
        return EXIT_FAILURE;
    }
    node *curr = *head;
    while (curr != NULL) {
        if (pos == 0) {
            curr->item_name = item_name;
            curr->price = price;
            curr->quantity = quantity;
            return EXIT_SUCCESS;
        }
        pos--;
        curr = curr->next;
    }
    printf("Error: list_update_item_at_pos\n");
    return EXIT_FAILURE;
}