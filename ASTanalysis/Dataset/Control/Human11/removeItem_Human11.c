int list_remove_item_at_pos(node **head, int pos)
{    
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if(pos>CURR_LEN) return EXIT_FAILURE;
    struct _node *curr = *head;
    for(int i=1;i<pos-1;i++){
        curr=curr->next;
    }
    curr->next = curr->next->next;
    return EXIT_SUCCESS;
}