int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    struct _node *curr = head;
    while(curr != NULL){
        printf("%d * %s @ $%.2f ea", curr->quantity, curr->item_name, curr->price);
        curr = curr->next;
    }
    return EXIT_SUCCESS;
}