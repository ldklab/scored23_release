int list_cost_sum(node *head, float *total)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    *total = 0;
    struct _node *curr = head;
    while(curr != NULL){
        *total += (curr->quantity * curr->price);
    }
    return EXIT_SUCCESS;
}