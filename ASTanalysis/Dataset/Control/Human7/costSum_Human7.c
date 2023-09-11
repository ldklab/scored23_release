int list_cost_sum(node *head, float *total)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node *temp = head;
    *total = 0.00;
    while(temp!=NULL){
        *total += (temp->price * temp->quantity);
        temp = temp->next;
    }
    return EXIT_SUCCESS;
}