int list_remove_item_at_pos(node **head, int pos)
{    
    node *temp = *head, *prev;
    int i = 1;
    if(temp!=NULL&&i==pos) {
        *head = temp->next;
        free (temp);
        return EXIT_SUCCESS;
    }

    while(temp!=NULL&&i!=pos) {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL) {
        return EXIT_SUCCESS;
    }
    prev->next = temp->next;
    free(temp);
    return EXIT_SUCCESS;

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}