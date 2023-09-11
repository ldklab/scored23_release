int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // TODO: Implement this function, 
    node* cur = *head;
    for (int i=1; i<pos; i++){
        cur = cur->next;
    }
    cur->price = price;
    cur->quantity = quantity;
    cur->item_name = item_name;
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}