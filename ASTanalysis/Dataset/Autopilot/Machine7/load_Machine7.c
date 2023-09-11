int list_load(node **head, char *filename) {
    // check for NULL pointer
    if (head == NULL || filename == NULL) return EXIT_FAILURE;

    // check for empty list
    if (*head == NULL || (*head)->item_name == NULL) return EXIT_SUCCESS;

    FILE *file = fopen(filename, "r");
    if (file == NULL) return EXIT_FAILURE;

    // load list from file
    node *current = *head;
    while (fscanf(file, "%s,%f,%d", current->item_name, &current->price, &current->quantity) != EOF) {
        current->next = (node *)malloc(sizeof(node));
        if (current->next == NULL) return EXIT_FAILURE;
        current = current->next;
    }

    fclose(file);
    return EXIT_SUCCESS;
}