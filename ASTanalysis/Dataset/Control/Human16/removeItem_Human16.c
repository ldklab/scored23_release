int list_remove_item_at_pos(node **head, int pos)
{    
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    int i = 1;

    node* _head = *head;
    node* _prev = NULL;
    while(_head && i < pos){
        i++;
        _prev = _head;
        _head = _head->next;
    }
    if(!_head && i < pos){
        return EXIT_FAILURE;
    }

    if(!_prev){
        *head = _head->next;
        return EXIT_SUCCESS;
    }

    _prev->next = _head->next;
    return EXIT_SUCCESS;
}