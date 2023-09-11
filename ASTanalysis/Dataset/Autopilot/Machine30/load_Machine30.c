int list_load(node **head, char *filename) {
    if (head == NULL) {
        return EXIT_FAILURE;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return EXIT_FAILURE;
    }
    char *line = NULL;
    size_t line_len = 0;
    ssize_t read;
    while ((read = getline(&line, &line_len, file)) != -1) {
        char item_name[MAX_ITEM_PRINT_LEN];
        float price;
        int quantity;
        sscanf(line, "%[^,],%f,%d", item_name, &price, &quantity);
        list_add_item_at_pos(head, item_name, price, quantity, -1);
    }
    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}