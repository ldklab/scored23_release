int list_load(node **head, char *filename) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        if (filename == NULL) {
            return EXIT_FAILURE;
        } else {
            FILE *f = fopen(filename, "r");
            if (f == NULL) {
                return EXIT_FAILURE;
            } else {
                char *line = malloc(MAX_ITEM_PRINT_LEN);
                if (line == NULL) {
                    return EXIT_FAILURE;
                }
                while (fgets(line, MAX_ITEM_PRINT_LEN, f)) {
                    char *item_name = strtok(line, ",");
                    char *price = strtok(NULL, ",");
                    char *quantity = strtok(NULL, ",");
                    float f_price = atof(price);
                    int i_quantity = atoi(quantity);
                    list_add_item_at_pos(head, item_name, f_price, i_quantity, 0);
                }
                free(line);
                fclose(f);
                return EXIT_SUCCESS;
            }
        }
    }
}