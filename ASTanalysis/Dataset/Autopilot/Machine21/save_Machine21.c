int list_save(node *head, char *filename) {
    FILE *fp = fopen(filename,"w");
    if (fp == NULL) {
        return EXIT_FAILURE;
    }
    node *current = head;
    while (current != NULL) {
        fprintf(fp, "%s,%.2f,%d\n", current->item_name, current->price, current->quantity);
        current = current->next;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}