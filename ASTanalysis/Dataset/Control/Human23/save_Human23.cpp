int list_save(node *head, char *filename)
{
    FILE* fptr = fopen(filename, "a");
    if (fptr == NULL){
        return EXIT_FAILURE;
    }

    node* current = head;

    while(current != NULL){
        fprintf(fptr, "%s,%.2f,%d\n", current->item_name, current->price, current->quantity);
        current = current->next;
    }
    
    fclose(fptr);
    return EXIT_SUCCESS;
}