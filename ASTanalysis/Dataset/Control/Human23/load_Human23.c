int list_load(node **head, char *filename)
{
    FILE* fptr = fopen(filename, "r");
    node* current = *head;
    int pos = 1;

    char* item_name = malloc(MAX_ITEM_PRINT_LEN);
    float *price = malloc(sizeof(float));
    int *quantity = malloc(sizeof(int));

    while(current != NULL && current->next != NULL){
        current = current->next;
        pos++;
        if(current->next == NULL)
            pos++;
    }
    
    int res;
    while(fscanf(fptr, "%s,%f,%d", item_name, price, quantity) != EOF){
        res = list_add_item_at_pos(head, item_name, *price, *quantity, (unsigned int) pos);
        if (res == EXIT_FAILURE)
            return EXIT_FAILURE;
        pos++;
        
    }
    free(item_name);
    free(price);
    free(quantity);
    fclose(fptr);
    return EXIT_SUCCESS;
}