int list_load(node **head, char *filename){
    node* curr;
    curr = *head;
    node* prev;
    prev = *head;
    FILE *fptr;
    fptr = fopen(filename, "r");
    float val;
    int quant;
    int pos = 1;
    while(curr != NULL) {
        prev = curr;
        curr=curr->next;
        pos++;
    }
    while(!feof(fptr)){
        char* name = (char*) malloc(100 * sizeof(char));
        fscanf(fptr,"%[^,],%f,%d ", name, &val, &quant);
        list_add_item_at_pos(head, name, val, quant, pos);
        pos++;

    }
    
    fclose(fptr);
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}