int list_remove_item_at_pos(node **head, int pos)
{    
    // TODO: Implement this function, 
    node *cur = *head;
    node *prev, *temp;
    if (pos==1){
        temp = *head;
        *head = temp->next;
        temp = NULL;
        return EXIT_SUCCESS;
    }
    for (int i=1; i<pos; i++){
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;
    cur = NULL;
    
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}