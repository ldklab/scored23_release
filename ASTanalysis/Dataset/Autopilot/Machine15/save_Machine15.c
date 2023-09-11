int list_save(node *head, char *filename) {
    node *curr;
    FILE *fp;
    int i;
    
    // check for invalid inputs
    if (head == NULL || filename == NULL) return EXIT_FAILURE;
    
    // check if the list is empty
    if (head == NULL) return EXIT_FAILURE;
    
    // open the file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) return EXIT_FAILURE;
    
    curr = head;
    for (i = 0; curr!= NULL; curr = curr->next, i++) {
        fprintf(fp, "%s,%.2f,%d\n", curr->item_name, curr->price, curr->quantity);
    }
    
    fclose(fp);
    return EXIT_SUCCESS;
}