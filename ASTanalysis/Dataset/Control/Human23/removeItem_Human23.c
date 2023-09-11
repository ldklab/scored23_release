int list_remove_item_at_pos(node **head, int pos)
{    
    node* current = *head;
    int current_pos = 1;
    if(pos == 1){
        free(*head);
        *head = NULL;
        return EXIT_SUCCESS; 
    }
    while(current_pos < pos - 1){
        current = current->next;
        if(current->next == NULL)
            return EXIT_FAILURE;
        current_pos++;
    }
    node* before = current;
    node* to_remove = current->next;
    node* after = to_remove->next;

    before->next = after;
    free(to_remove);
    return EXIT_SUCCESS;
}