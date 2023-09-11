int list_remove_item_at_pos(node **head, int pos)
{    
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    // pos must be an integer >= 1
    if (pos < 1) {
        return EXIT_FAILURE;
    }

    node* prev_ptr = NULL;  // node before node to be removed
    node* rem_ptr = *head; // node that will be removed (curr node at pos)

    int counter = 1;
    // loop until rem_ptr points to the node to be removed or reaches end of list
    while(counter < pos && rem_ptr != NULL) {
        prev_ptr = rem_ptr;
        rem_ptr = rem_ptr->next;
        counter++;
    }

    // cannot remove end of list/NULL
    if (rem_ptr == NULL) {
        return EXIT_FAILURE;
    }


    // case: pos is not 1, hence prev_str != NULL
    if (pos != 1) {
        prev_ptr->next = rem_ptr->next;
    } else {
        *head = rem_ptr->next; // note that rem_ptr = *head in this case
    }

    // free memory
    free(rem_ptr->item_name);
    free(rem_ptr);

    return EXIT_SUCCESS;
}