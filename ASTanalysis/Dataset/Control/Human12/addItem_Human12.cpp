int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos)
{
    // printf(*head);
    if (pos % 1 == 0) {
        int cur_pos = 1;
        node * current = *head;
        while (current != NULL && cur_pos < pos)
        {
            current = current->next;
        }
        
    }
    

    return EXIT_SUCCESS;
}