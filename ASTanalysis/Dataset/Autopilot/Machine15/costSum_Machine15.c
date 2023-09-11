int list_cost_sum(node *head, float *total) {
    node *curr;
    int i;
    float sum = 0;
    
    // check for invalid inputs
    if (head == NULL || total == NULL) return EXIT_FAILURE;
    
    // check if the list is empty
    if (head == NULL) return EXIT_FAILURE;
    
    curr = head;
    for (i = 0; curr!= NULL; curr = curr->next, i++) {
        sum += curr->price*curr->quantity;
    }
    
    *total = sum;
    return EXIT_SUCCESS;
}