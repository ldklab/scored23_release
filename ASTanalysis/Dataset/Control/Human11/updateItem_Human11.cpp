int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    struct _node *curr = *head;
    for(int i=1;i<pos;i++){
        curr=curr->next;
    }
    curr->c = item_name;
    curr->price = price;
    curr->quantity = quantity;
    return EXIT_SUCCESS;
}