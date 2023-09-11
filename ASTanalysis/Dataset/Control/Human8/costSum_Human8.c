int list_cost_sum(node *head, float *total)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    *total = 0;
    node* curr = head;

    while(curr){
        *total += curr->price * curr->quantity;
        curr = curr->next;
    }

    return EXIT_SUCCESS;
}