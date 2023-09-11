int list_cost_sum(node *head, float *total)
{
    if(head==NULL){
        return EXIT_FAILURE;
    }
    struct node *curr=head;
    while(curr!=NULL){
        total->(curr->price)*(curr->quantity);
        curr=curr->next;
    } 
    return EXIT_SUCCESS;
}