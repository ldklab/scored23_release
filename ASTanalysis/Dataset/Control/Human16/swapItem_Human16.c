int list_swap_item_positions(node **head, int pos1, int pos2) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    int i = 1;

    node* _head1 = *head;
    node* _prev1 = NULL;
    int small_pos = pos1 < pos2 ? pos1 : pos2;
    int large_pos = pos1 > pos2 ? pos1 : pos2;

    while(_head1->next && i < small_pos){
        i++;
        _prev1 = _head1;
        _head1 = _head1->next;
    }

    i = 1;
    node* _head2 = *head;
    node* _prev2 = NULL;
    while(_head2->next && i < large_pos){
        i++;
        _prev2 = _head2;
        _head2 = _head2->next;
    }

    _prev2->next = _head1;
    node* tmp = _head1->next;
    _head1->next = _head2->next;
    _head2->next = tmp;
    if(_prev1){
        _prev1->next = _head2;
    }
    if(small_pos==1)
        *head = _head2;
    return EXIT_SUCCESS;    
}