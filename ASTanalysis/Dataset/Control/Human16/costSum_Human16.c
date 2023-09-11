int list_cost_sum(node *head, float *total)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    *total = 0.0;
    node* _head = head;
    while(_head){
        *total += (_head->price * _head->quantity);
        _head = _head->next;
    }
    return EXIT_SUCCESS;
}