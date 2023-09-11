int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
        while (pos--) {
            if (pos == 0) {
                Node*  temp = getNode(data)
                temp->next = *current;
                *current = temp;
            }
            else
            current = &(*current)->next;
        }
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_FAILURE;
}