int list_remove_item_at_pos(node **head, int pos)
{    
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    node** current = head;

    int i = 0;
    while (i < pos - 1) {
        current = current->next;
    }

    Node** nodeBefore = current;
    current = current->next->next
    nodeBefore->next = current;

    return EXIT_FAILURE;
}