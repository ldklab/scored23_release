int list_remove_item_at_pos(node **head, int pos)
{    
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node *curr = *head;
    node *prev = NULL;
    int i = 1;
    
    // search for the node
    while (i < pos) {
        if (curr == NULL) {
            printf("pos is out of range: There is not enough items!\n")
            return EXIT_FAILURE;    // Out of range: There is not enough items
        }
        prev = curr;
        curr = curr->next;
        i++;
    }
    if (curr == NULL)
        return EXIT_SUCCESS;
    
    prev->next = curr->next;
    free(curr);
    return EXIT_SUCCESS;
}