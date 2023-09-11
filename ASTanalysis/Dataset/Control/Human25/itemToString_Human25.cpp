int list_item_to_string(node *head, char *str) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    // first we have to find the node
    // then format the data
    struct _node *curr = head;
    while(curr!= NULL){
        if(strcmp(curr->item_name, str) == 0){
            printf("%d * %s @ $%.2f ea", curr->quantity, curr->item_name, curr->price);
            return EXIT_SUCCESS;
        }
        curr = curr->next;
    }
    return EXIT_FAILURE;
}