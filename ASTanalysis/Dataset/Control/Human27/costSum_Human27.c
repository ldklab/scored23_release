int list_cost_sum(node *head, float *total)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    float tot = 0;
    node *curr = head;
    while(curr != NULL){
        tot += curr->price;
        curr = curr->next;
    }
    *total = tot;
    return EXIT_SUCCESS;
}