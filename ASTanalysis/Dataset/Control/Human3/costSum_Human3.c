int list_cost_sum(node *head, float *total)
{
    // TODO: Implement this function, 
    node* cur;
    cur = head;
    int cost = 0;

    while (1){
        if (cur == NULL){
            break;
        }
        cost += cur->price * cur->quantity;
        cur = cur->next;
    }
    *total = cost;
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}