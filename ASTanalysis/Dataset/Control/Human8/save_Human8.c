int list_save(node *head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    FILE *fptr;
    fptr = fopen(filename, "w");

    if (fptr == NULL){
        return EXIT_FAILURE;
    }

    node* curr = head;

    while(curr){
        char str[100];

        // list_item_to_string(curr, str);
        int res = sprintf(str, "%s,%.2f,%d", curr->item_name, curr->price, curr->quantity);

        if (res < 0){
            return EXIT_FAILURE;
        }

        fprintf(fptr, "%s\n", str);

        curr = curr->next;
    }
    
    fclose(fptr);

    return EXIT_SUCCESS;
}