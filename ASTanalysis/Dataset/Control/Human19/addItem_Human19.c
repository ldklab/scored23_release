int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    //created the new node
    node *created = malloc(sizeof(node));
    created->item_name = item_name;
    created->price = price;
    created->quantity = quantity;

    if(pos == 1) {
        created->next = *head, head = &created;
        return EXIT_SUCCESS;
    }

    node *prev = *head;
    while(pos > 2)
        prev = prev->next, --pos;
    
    created->next = prev->next;
    prev->next = created;

    return EXIT_SUCCESS;
}