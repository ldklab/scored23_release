int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    unsigned int counter = 1;
    node* n = *head;
    while(n != NULL) {
        if (counter == pos) {
            n->item_name = item_name;
            n->price = price;
            n->quantity = quantity;
            return EXIT_SUCCESS;
        }
        n = n->next;
    }
    return EXIT_SUCCESS;
}