int list_print(node *head) {
    node* current = head;
    char* current_string = malloc(sizeof(MAX_ITEM_PRINT_LEN));
    int res, i=1;
    while(current != NULL){
        res = list_item_to_string(current,current_string);
        if(res == EXIT_FAILURE)
            return EXIT_FAILURE;
        printf("%d: %s\n", i, current_string);
        current = current->next;
        i++;
    }
    return EXIT_SUCCESS;
}