int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node* ptr = head;
    char str[100];
    int counter = 1;
    
    // loop until end of list and print each item
    while (ptr != NULL) {
        int status = list_item_to_string(ptr, str);
        if (status == EXIT_FAILURE) { // check for error
            return EXIT_FAILURE;
        }

        printf("%d: %s\n", counter, str);
        ptr = ptr->next;
        counter++;
    }

    return EXIT_SUCCESS;
}