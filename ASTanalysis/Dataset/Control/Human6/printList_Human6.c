int list_print(node *head) {
    char* print_str;
    while (head != NULL) {
        list_item_to_string(head, print_str);
        printf("%s\n", print_str);
        head = head->next;
    }
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}