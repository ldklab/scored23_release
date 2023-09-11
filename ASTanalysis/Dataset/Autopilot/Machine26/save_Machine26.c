int list_save(node *head, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return EXIT_FAILURE;
    }
    while (head) {
        fprintf(fp, "%s,%f,%d\n", head->item_name, head->price, head->quantity);
        head = head->next;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}