int list_load(node **head, char *filename)
{
    // TODO: Implement this function, 
    node* cur;
    cur = *head;
    while(cur != NULL){
        cur = cur->next;
    }

    FILE *file;
    file = fopen(filename, "w");
    while(cur != NULL){
        fscanf(file, "%d,%s,%f", &cur->quantity, cur->item_name, &cur->price);
        cur = cur->next;
    }
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}