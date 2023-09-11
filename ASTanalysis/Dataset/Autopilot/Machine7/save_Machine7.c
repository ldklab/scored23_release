int list_save(node *head, char *filename) {
    // check for NULL pointer
    if (head == NULL || filename == NULL) return EXIT_FAILURE;

    // check for empty list
    if (head->item_name == NULL) return EXIT_SUCCESS;

    FILE *file = fopen(filename, "w");
    if (file == NULL) return EXIT_FAILURE;

    // save list to file
    node *current = head;
    while (current->next != NULL) {
        fprintf(file, "%s,%.2f,%d\n", current->item_name, current->price, current->quantity);
        current = current->next;
    }
    fprintf(file, "%s,%.2f,%d\n", current->item_name, current->price, current->quantity);

    fclose(file);
    return EXIT_SUCCESS;
}