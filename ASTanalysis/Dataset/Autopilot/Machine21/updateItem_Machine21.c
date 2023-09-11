int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    node *current = *head;
    int i=0;
    while (current != NULL && i<pos) {
        if (i+1==pos) {
            current->item_name = item_name;
            current->price = price;
            current->quantity = quantity;
            return EXIT_SUCCESS;
        }
        current = current->next;
        i++;
    }
    return EXIT_FAILURE;
}