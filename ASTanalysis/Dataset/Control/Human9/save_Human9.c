int list_save(node *head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    
    // open file for writing
    node *curr = head;
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening the file %s\n", filename);
        return EXIT_FAILURE;
    }
    while (curr != NULL) {
        fprintf(fp, "%s,%.2f,%i\n", curr->item_name, curr->price, curr->quantity);
        curr = curr->next;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}