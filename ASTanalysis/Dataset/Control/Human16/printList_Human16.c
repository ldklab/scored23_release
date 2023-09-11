int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    int i = 1;
    while(head){
        char buffer[100];
        list_item_to_string(head, buffer);
        printf("%d: %s\n", i, buffer);
        i++;
        head = head->next;
    }
    return EXIT_SUCCESS;
}