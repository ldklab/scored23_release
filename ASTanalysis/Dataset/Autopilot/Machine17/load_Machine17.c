int list_load(node **head, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: list_load\n");
        return EXIT_FAILURE;
    }
    char line[200];
    char *token;
    while (fgets(line, 200, fp) != NULL) {
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
        }
        token = strtok(line, ",");
        char *item_name = token;
        token = strtok(NULL, ",");
        float price = atof(token);
        token = strtok(NULL, ",");
        int quantity = atoi(token);
        list_add_item_at_pos(head, item_name, price, quantity, 0);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}