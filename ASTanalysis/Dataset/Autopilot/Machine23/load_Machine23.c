int list_load(node **head, char *filename) {
    // check if node is null
    if (*head == NULL) {
        fprintf(stderr, "list_load: node is null\n");
        return EXIT_FAILURE;
    }

    // check if string is null
    if (filename == NULL) {
        fprintf(stderr, "list_load: filename is null\n");
        return EXIT_FAILURE;
    }

    // set up variables
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    FILE *fp = fopen(filename, "r");
    if (fp == 0) {
        fprintf(stderr, "list_load: fopen failed\n");
        return EXIT_FAILURE;
    }

    // load the list
    while ((read = getline(&line, &len, fp)) != -1) {
        char *item_name = strtok(line, ",");
        float price = atof(strtok(NULL, ","));
        int quantity = atoi(strtok(NULL, "\n"));
        node *new_node = malloc(sizeof(node));
        new_node->item_name = item_name;
        new_node->price = price;
        new_node->quantity = quantity;
        new_node->next = (*head);
        (*head) = new_node;
    }
    free(line);
    fclose(fp);

    return EXIT_SUCCESS;
}