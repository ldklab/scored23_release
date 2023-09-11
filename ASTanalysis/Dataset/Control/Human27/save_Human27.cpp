int list_save(node *head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    FILE *fptr = fopen(filename, "w");
    char buf [100];
    node *curr = head;
    while(curr != NULL){
        int i = snprintf(buf, 100, "%s,%.2f,%d\n",head->item_name, head->price, head->quantity);
        fputs(buf, fptr);
    }
    fclose(fptr);
    return EXIT_SUCCESS;
}