int list_load(node **head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate

    // open file and check for error
    FILE* fileptr = fopen(filename, "r");
    if (fileptr == NULL) {
        return EXIT_FAILURE;
    }

    node* ptr = *head;
    int counter = 1;

    // loop through list and until it reaches end to set counter
    while(ptr != NULL) {
        counter++;
        ptr = ptr->next;
    }

    char name[100];
    float price;
    int quantity;

    // scan through file and set the attributes (note %*c to ignore , delimiter)
    while(fscanf(fileptr, "%[^,],%f%*c%d\n", name, &price, &quantity) != EOF) {
        // add item to end of list
        int status = list_add_item_at_pos(head, name, price, quantity, counter);
        if (status == EXIT_FAILURE) { // check item added correctly
            return EXIT_FAILURE;
        }

        counter++;
    }

    // close file
    fclose(fileptr);

    return EXIT_SUCCESS;
}