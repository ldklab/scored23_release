int list_save(node *head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    // open file and check for error
    FILE* fileptr = fopen(filename, "w");
    if (fileptr == NULL) {
        return EXIT_FAILURE;
    }

    node* ptr = head;
    char str[100];

    // loop through list and write each item in specified format
    while(ptr != NULL) {
        fprintf(fileptr, "%s,%.2f,%d\n", ptr->item_name, ptr->price, ptr->quantity);
        ptr = ptr->next;
    }

    // close file
    fclose(fileptr);

    return EXIT_SUCCESS;
}