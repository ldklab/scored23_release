int list_save(node *head, char *filename)
{
    // TODO: Implement this function, 
    node* cur;
    cur = head;

    FILE *file;
    file = fopen(filename, "w");
    while(cur != NULL){
        fprintf(file, "%d,%s,%.2f", cur->quantity, cur->item_name, cur->price);
        cur = cur->next;
    }

    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
} 