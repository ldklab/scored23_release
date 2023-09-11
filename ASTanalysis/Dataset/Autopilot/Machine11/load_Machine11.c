int list_load(node **head, char *filename) {
    if (*head == NULL) {
        return EXIT_FAILURE;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return EXIT_FAILURE;
    }
    char line[MAX_ITEM_PRINT_LEN];
    while (fgets(line, MAX_ITEM_PRINT_LEN, file) != NULL) {
        char *item_name = strdup(strtok(line, ","));
        float price = strtof(strtok(NULL, ","), NULL);
        int quantity = strtol(strtok(NULL, ","), NULL, 10);
        list_add_item_at_pos(head, item_name, price, quantity, -1);
    }
    fclose(file);
    return EXIT_SUCCESS;
}