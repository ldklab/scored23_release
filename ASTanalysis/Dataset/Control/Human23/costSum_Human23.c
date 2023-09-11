int list_cost_sum(node *head, float *total)
{
    node* current = head;
    while(current != NULL){
        *total += current->price * current->quantity;
        current = current->next;
    }
    return EXIT_SUCCESS;
}