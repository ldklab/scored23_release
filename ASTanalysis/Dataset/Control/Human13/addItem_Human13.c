int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
        
    struct node *newNode;
    newNode->item_name = item_name;
    newNode->price = price;
    newNode->quantity = quantity;

    struct node *newHead;
    newHead->item_name = head->item_name;
    newHead->price = head->price;
    newHead->quantity = head->quantity;
    newHead->next = head->next;

    if (pos == 1) {
        newNode->next = newHead;
        head = newNode;
        return EXIT_SUCCESS;
    }

    int counter = 1
    struct node *currNode = &head;
    struct node *prevNode = NULL;
    while (counter != pos) {
        prevNode = currNode;
        currNode = prevNode->next;
        counter++;
    }
    prevNode->next = newNode;
    newNode->next = currNode;
    return EXIT_SUCCESS;
}