int list_remove_item_at_pos(node **head, int pos)
{    
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    if(pos == 1){
        node *temp = *head;
        *head = temp->next;
        free(temp);
        return EXIT_SUCCESS;
    }
    else{
        node *curr = *head;
        for(int i = 2; i < pos; i++){
            if( curr == NULL ){ return EXIT_FAILURE; }
            curr = curr->next;
        }
        if(curr->next == NULL){ return EXIT_FAILURE; }
        node *temp = curr->next;
        curr->next = curr->next->next;
        free(temp);
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}