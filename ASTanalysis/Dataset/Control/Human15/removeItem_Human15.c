int list_remove_item_at_pos(node **head, int pos)
{   node * prev = head;
    head = *head->next;
    int count = 0;
    while (head != NULL && count != pos) {
        head = *head->next;
        prev = prev->next;
        count++;
    }
    prev->next = *head->next;
    *head->next = NULL;
    return EXIT_SUCCESS;
}