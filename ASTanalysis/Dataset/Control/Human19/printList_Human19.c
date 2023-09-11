int list_print(node *head) {
    char* str = malloc(sizeof(char) * MAX_ITEM_PRINT_LEN);

    while(head) 
    {
        list_item_to_string(head, str);
        printf("%s", str);
        head = head->next;
    }
    return EXIT_SUCCESS;
}