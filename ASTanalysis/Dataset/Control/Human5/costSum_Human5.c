int list_cost_sum(node *head, float *total)
{

    float val = 0;
    while(head != NULL) {
        val = val + (head->price * head->quantity);
        head=head->next;
    }
    *total = val;

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}