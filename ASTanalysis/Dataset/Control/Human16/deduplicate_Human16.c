int list_deduplicate(node **head) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node* _head1 = *head;
    while(_head1 && _head1->next){
        node* _head2 = _head1->next;
        node* _prev = _head1;
        while(_head2){
            int to_free = 0;
            if(!strcmp(_head1->item_name, _head2->item_name)){
                _head1->quantity += _head2->quantity;
                _prev->next = _head2->next;
                to_free = 1;
            }
            if(to_free){
                node* tmp = _head2;
                _head2 = _head2->next;
                free(tmp);
            } else {
                _prev = _head2;
                _head2 = _head2->next;
            }
        }
        _head1 = _head1->next;
    }   
    return EXIT_SUCCESS;
}