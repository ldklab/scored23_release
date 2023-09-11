int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
    struct node *currNode = &head;
    struct node *prevNode = NULL;
    int counter = 1;
    while (currNode != NULL) {
        if (counter == pos) {
            currNode->item_name = item_name;
            currNode->price = price;
            currNode->quantity = quantity;
            return EXIT_SUCCESS;
        }
        counter++;
        prevNode = currNode;
        currNode = prevNode->next;
    }
    // Never found
    return EXIT_FAILURE;
}