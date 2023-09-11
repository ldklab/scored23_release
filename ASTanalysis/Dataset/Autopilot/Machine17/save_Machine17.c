int list_save(node *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: list_save\n");
        return EXIT_FAILURE;
    }
    node *curr = head;
    while (curr!= NULL) {
        fprintf(fp, "%s,%f,%d\n", curr->item_name, curr->price, curr->quantity);
        curr = curr->next;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}