int list_load(node **head, char *filename) {
    int result = EXIT_SUCCESS;
    node *current = NULL;
    node *next = NULL;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        result = EXIT_FAILURE;
    } else {
        char buffer[128];
        while (fgets(buffer, 128, file)) {
            int pos = 0;
            int item_name_len = strlen(buffer);
            buffer[item_name_len - 1] = 0;

            while (buffer[pos] != ',') {
                pos++;
            }

            char *item_name = (char *)malloc(pos + 1);
            strncpy(item_name, buffer, pos);
            item_name[pos] = 0;
            float price = atof(buffer + pos + 1);
            int quantity = atoi(buffer + pos + 5);

            next = malloc(sizeof(node));
            next->item_name = item_name;
            next->price = price;
            next->quantity = quantity;
            next->next = NULL;

            if (current == NULL) {
                *head = next;
            } else {
                current->next = next;
            }

            current = next;
        }

        fclose(file);
    }

    return result;
}