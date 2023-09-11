int list_print(node *head) {
    if (head == NULL) { 
        return EXIT_FAILURE;
    }
    int pos = 1;
    while (head != NULL) {
        char line[MAX_ITEM_PRINT_LEN];
        int len = snprintf(line, MAX_ITEM_PRINT_LEN, "%i: %s\n",
                           pos, head->item_name);
        if (len < 0) {
            return EXIT_FAILURE;
        }
        printf("%s", line);
        head = head->next;
        pos++;
    }
    return EXIT_SUCCESS;
}