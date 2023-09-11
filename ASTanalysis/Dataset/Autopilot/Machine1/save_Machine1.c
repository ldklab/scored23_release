int list_save(node *head, char *filename) {
    // check the list
    if (head == NULL) {
        return EXIT_FAILURE;
    }
    // check the filename
    if (filename == NULL) {
        return EXIT_FAILURE;
    }
    // open the file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        return EXIT_FAILURE;
    }
    // write the list to the file
    node *tail = head;
    while (tail!= NULL) {
        fprintf(file, "%s,%f,%d\n", tail->item_name, tail->price, tail->quantity);
        tail = tail->next;
    }
    // close the file
    fclose(file);
    return EXIT_SUCCESS;
}