int list_save(node *head, char *filename) {
    int result = EXIT_SUCCESS;
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        result = EXIT_FAILURE;
    } else {
        node *current = head;

        while (current != NULL) {
            fprintf(file, "%s,%.2f,%d\n", current->item_name, current->price, current->quantity);
            current = current->next;
        }

        fclose(file);
    }

    return result;
}