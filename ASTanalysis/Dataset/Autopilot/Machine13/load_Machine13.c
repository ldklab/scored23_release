int list_load(node **head, char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return EXIT_FAILURE;
    }
    char str[MAX_ITEM_PRINT_LEN];
    while (fgets(str, MAX_ITEM_PRINT_LEN, f) != NULL) {
        char item_name[MAX_ITEM_PRINT_LEN];
        float price;
        int quantity;
        sscanf(str, "%[^,],%f,%d\n", item_name, &price, &quantity);
        list_add_item_at_pos(head, item_name, price, quantity, 0);
    }
    fclose(f);
    return EXIT_SUCCESS;
}