int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    if(head == NULL){
        return EXIT_FAILURE;
    }

    node* curr = head;

    int n = 1;
    while(curr){
        char str[256];
        int res = list_item_to_string(curr, str);

        if(res == EXIT_FAILURE){
            return EXIT_FAILURE;
        }
        // printf(s);
        printf("%d: %s\n", n, str);
        curr = curr->next;
        n += 1;
    }

    return EXIT_SUCCESS;
}