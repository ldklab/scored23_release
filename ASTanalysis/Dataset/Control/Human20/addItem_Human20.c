int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{

    node *ptr;
    ptr = malloc(sizeof(node));
    ;
    head[pos] = ptr;
    //head[pos]->next = NULL;
    // if (pos != 0){
    //     head[pos - 1]->next = head[pos];
    // }
    return EXIT_SUCCESS;
}