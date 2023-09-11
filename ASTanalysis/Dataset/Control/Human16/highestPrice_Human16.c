int list_find_highest_price_item_position(node *head, int *pos) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node* _head = head;
    float max_price = head->price;
    *pos = 1;
    int i = 0;
    while(_head){
        i++;
        if(max_price < _head->price){
            max_price = _head->price;
            *pos = i;
        }
        _head = _head->next;
    }
    return EXIT_SUCCESS;
}