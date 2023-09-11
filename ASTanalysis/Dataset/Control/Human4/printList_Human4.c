int list_print(node *head) {
    if (head == NULL){
        return EXIT_FAILURE;
    }
    int item = 0;
    while(head != NULL){
        char* str;
        list_item_to_string(head,str);
        printf("%d: %s\n", item, str);
    }
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}