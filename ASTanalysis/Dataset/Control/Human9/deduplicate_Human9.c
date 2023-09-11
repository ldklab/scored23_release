int list_deduplicate(node **head) 
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node *curr = *head;
    node *prev = NULL;
    node *orig_name = NULL;
    node *temp = NULL;
    int pos = 1;
    if (curr == NULL) {
        printf("Need to pass in a singly linked list!\n");
        return EXIT_FAILURE;
    }
    prev = curr;
    curr = curr->next;
    // go through the list
    while (curr != NULL) {
        orig_name = find_prev_node(head, curr->item_name, pos);
        if (orig_name != NULL) {
            orig_name->quantity += curr->quantity;
            temp = curr;
            curr = curr->next;
            prev->next = curr;
            free(temp);
        }
        else {
            prev = curr;
            curr = curr->next;
            pos++;
        }
    }
    return EXIT_SUCCESS;
}