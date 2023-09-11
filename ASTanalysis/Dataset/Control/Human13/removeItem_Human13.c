int list_remove_item_at_pos(node **head, int pos)
{    
    struct node *currNode = &head;
    struct node *prevNode = NULL;
    int counter = 1;
    while (currNode != NULL) {
        if (counter == pos) {
            prevNode->next = currNode->next;
            return EXIT_SUCCESS;
        }
        counter++;
        prevNode = currNode;
        currNode = prevNode->next;
    }
    return EXIT_FAILURE;
}