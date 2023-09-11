int list_save(node *head, char *filename) {
    // check if node is null
    if (head == NULL) {
        fprintf(stderr, "list_save: node is null\n");
        return EXIT_FAILURE;
    }

    // check if string is null
    if (filename == NULL) {
        fprintf(stderr, "list_save: filename is null\n");
        return EXIT_FAILURE;
    }

    // set up variables
    int pos = 1;
    node *current = head;
    FILE *fp = fopen(filename, "w");
    while (current != NULL) {
        char item_str[MAX_ITEM_PRINT_LEN];
        list_item_to_string(current, item_str);
        fprintf(fp, "%s\n", item_str);

        pos++;
        current = current->next;
    }

    fclose(fp);

    return EXIT_SUCCESS;
}