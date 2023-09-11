int list_load(node **head, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return EXIT_FAILURE;
    }
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (read <= 3) {
            continue;
        }
        if (line[read-1] == '\n') {
            line[read-1] = '\0';
        }
        char *token = strtok(line, ",");
        char *item_name = malloc(strlen(token) + 1);
        strcpy(item_name, token);
        token = strtok(NULL, ",");
        float price = atof(token);
        token = strtok(NULL, ",");
        int quantity = atoi(token);
        if (*head == NULL) {
            *head = (node *)malloc(sizeof(node));
            (*head)->item_name = item_name;
            (*head)->price = price;
            (*head)->quantity = quantity;
            (*head)->next = NULL;
        } else {
            node *cur = *head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = (node *)malloc(sizeof(node));
            cur->next->item_name = item_name;
            cur->next->price = price;
            cur->next->quantity = quantity;
            cur->next->next = NULL;
        }
    }
    fclose(fp);
    if (line) {
        free(line);
    }
    return EXIT_SUCCESS;
}