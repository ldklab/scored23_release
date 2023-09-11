int list_cost_sum(node *head, float *total)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    node* ptr = head;
    float total_cost = 0;

    // loop through list and sum total cost
    while(ptr != NULL) {
        total_cost += (ptr->price * ptr->quantity);
        ptr = ptr->next;
    }

    // set total cost
    *total = total_cost;

    return EXIT_SUCCESS;
}