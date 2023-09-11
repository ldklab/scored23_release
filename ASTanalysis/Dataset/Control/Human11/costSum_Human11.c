int list_cost_sum(node *head, float *total)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    float sum =0.0;
    node *curr = head;
    while(curr){
        sum = sum + (curr->price)*(curr->quantity);
        curr=curr->next;
    }
    *total = sum;
    return EXIT_SUCCESS;
}