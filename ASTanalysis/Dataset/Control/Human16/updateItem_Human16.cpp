int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    int i = 1;

    node* _head = *head;
    while(_head && i < pos){
        i++;
        _head = _head->next;
    }
    if(!_head && i < pos){
        return EXIT_FAILURE;
    }

    _head->item_name = item_name;
    _head->price = price;
    _head->quantity = quantity;

    return EXIT_SUCCESS;
}