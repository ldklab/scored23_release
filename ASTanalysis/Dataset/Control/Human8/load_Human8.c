int list_load(node **head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    FILE *fptr;
    fptr = fopen(filename, "r");

    if (fptr == NULL){
        return EXIT_FAILURE;
    }

    node* curr = NULL;
    
    int n=1;
    // while (fscanf(fptr, "%20[^,],%f[^,],%d", item_name, &price, &quantity) == 3){
    char line[256];

    while(fgets(line, 256, fptr)){
    // while (fscanf(fptr, "%20[^,],%20[^,],%d", item_name, price, &quantity) == 3){
    // while (fgets(line, sizeof(line), fptr)) {
    // while ((token = strsep(&str, ",")))
        // char *item_name = strtok(line, ",");
        // float price = atof(strtok(NULL, ","));
        // int quantity = atoi(strtok(NULL, ","));

        char* line1 = strdup(line);

        node* newnode = malloc(sizeof(node));
        newnode->item_name = (char*) strtok(line1, ",");
        newnode->price = atof(strtok(NULL, ","));
        newnode->quantity = atoi(strtok(NULL, ","));
        newnode->next = NULL;

        if(n==1){
            curr = newnode;
            *head = curr;
        }

        else{
            curr->next = newnode;
            curr = curr->next;
        }

        n += 1;
        // newnode->next= curr->next;
    }

    fclose(fptr);

    return EXIT_SUCCESS;
}