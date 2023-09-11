int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node *curr = *head;
    node *prev = NULL;
    int i = 1;
    
    while (i < pos) {
        if (curr == NULL) {
            printf("pos is out of range: There is not enough items!\n")
            return EXIT_FAILURE;    // Out of range: There is not enough items
        }
        prev = curr;
        curr = curr->next;
        i++;
    }
    if (curr == NULL) {
        // allocate on heap and point to newNode
        node *newNode = (node *)malloc(sizeof(node));
        newNode->next = NULL;
        prev->next = newNode;
        curr = newNode;
    }
    // update the node
    sprintf(curr->item_name, "%s", item_name);
    curr->price = price;
    curr->quantity = quantity;

    return EXIT_SUCCESS;
}