int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    int toPos = 0;
    node* current = *head;
    while (toPos < pos) {
        if (current == NULL) 
        {
            return EXIT_FAILURE;
        }
        current = current->next;
        toPos++;
    }

    node* nope;
    nope->item_name = item_name;
    nope->price = price;
    nope->quantity = quantity;

    current->next = nope;

    return EXIT_SUCCESS;

}