int list_save(node *head, char *filename)
{

    FILE *fptr;

    fptr = fopen(filename, "w");
    while(head != NULL) {

        fprintf(fptr,"%s,%.2f,%i\n", head->item_name, head->price, head->quantity);

        head=head->next;
    }
    fclose(fptr);

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}