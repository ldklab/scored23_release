int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node *curr = *head;
    node *prev = NULL;
    // allocate a new node on the heap
    node *newNode = (node *)malloc(sizeof(node));
    sprintf(newNode->item_name, "%s", item_name);
    newNode->price=price;
    newNode->quantity=quantity;
    newNode->next=NULL;
    int i = 1;

    // search for the node    
    while (i < pos) {
        if (curr == NULL) {
            printf("pos is out of range: There is not enough items!\n")
            return EXIT_FAILURE;    // Out of range: There is not enough items
        }
        prev = curr;
        curr = curr->next;
        i++;
    }
    prev->next = newNode;
    newNode->next = curr;
    return EXIT_SUCCESS;
}