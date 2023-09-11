int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    char buffer[MAX_ITEM_PRINT_LEN];
    if(head == NULL){ return EXIT_FAILURE; }
    node *curr = head;
    while(curr != NULL){
        list_item_to_string(curr, buffer);
        printf("%s\n", buffer);
    }
    return EXIT_SUCCESS;
}