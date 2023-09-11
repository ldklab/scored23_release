int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    node *curr = *head;
    for(unsigned int i = 1; i < pos; i++){
        if(curr == NULL){
            return EXIT_FAILURE;
        }
        curr = curr->next;
    }
    curr->item_name = item_name;
    curr->price = price;
    curr->quantity = quantity;
    return EXIT_SUCCESS;
}