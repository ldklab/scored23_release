int list_save(node *head, char *filename) {
    FILE *file;
    file = fopen(filename, "w");
    node *curr = head;
    char *str = malloc(MAX_ITEM_PRINT_LEN * sizeof(char));
    while (curr != NULL) {
        sprintf(str, "%s,%.2f,%d\n", curr->item_name, curr->price, curr->quantity);
        fputs(str, file);
        curr = curr->next;
    }
    free(str);
    fclose(file);
    return EXIT_SUCCESS;
}