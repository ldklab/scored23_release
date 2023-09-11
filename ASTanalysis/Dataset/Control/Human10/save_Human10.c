int list_save(node *head, char *filename)
{
    FILE* fileptr = NULL;

    fileptr = fopen(filename, "w");

    if (fileptr == NULL ) {
        return EXIT_FAILURE;
    }

    while (head != NULL) {
        fprintf(fileptr, "%s,%.2f,%d\n", head->item_name, head->price, head->quantity);
        head = head->next;
    }

    fclose(fileptr);

    return EXIT_SUCCESS;
}