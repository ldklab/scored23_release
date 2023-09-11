int list_load(node **head, char *filename)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node *curr = *head;
    node *prev = NULL;
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening the file %s\n", filename);
        return EXIT_FAILURE;
    }
    // go to the end of the list
    if (curr == NULL) {
        printf("Need to pass in a singly linked list!\n");
        return EXIT_FAILURE;    // need to pass in a singly linked list!
    }
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
    }
    curr = prev;    // last item of list
    char *item_name;
    float price;
    int quantity;
    // read the lines and load the nodes at the end of the list
    while (fscanf(fp, "%s,%.2f,%i\n", item_name, price, quantity) != EOF) {
        node *newNode = (node *)malloc(sizeof(node));
        sprintf(newNode->item_name, "%s", item_name);
        newNode->price = price;
        newNode->quantity = quantity;
        newNode->next = NULL;
        curr->next = newNode;
        curr = curr->next;
    }
    fclose(fp);
    return EXIT_SUCCESS;
}