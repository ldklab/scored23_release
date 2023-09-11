int list_load(node **head, char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        return EXIT_FAILURE;
    }
    char *line = malloc(MAX_ITEM_PRINT_LEN * sizeof(char) + 1);
    while (fgets(line, MAX_ITEM_PRINT_LEN, file) != NULL) {
        char *item_name = strtok(line, ",");
        float price = atof(strtok(NULL, ","));
        int quantity = atoi(strtok(NULL, ","));
        list_add_item_at_pos(head, item_name, price, quantity, 0);
    }
    free(line);
    fclose(file);
    return EXIT_SUCCESS;
}