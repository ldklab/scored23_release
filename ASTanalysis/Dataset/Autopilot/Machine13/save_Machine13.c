int list_save(node *head, char *filename) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        return EXIT_FAILURE;
    }
    char str[MAX_ITEM_PRINT_LEN];
    while (head != NULL) {
        fprintf(f, "%s,%.2f,%d\n", head->item_name, head->price, head->quantity);
        head = head->next;
    }
    fclose(f);
    return EXIT_SUCCESS;
}