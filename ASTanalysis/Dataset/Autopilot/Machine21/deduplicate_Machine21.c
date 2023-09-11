int list_deduplicate(node **head) {
    node *current = *head;
    node *prev = NULL;
    while (current != NULL) {
        if (prev!=NULL && strcmp(current->item_name, prev->item_name)==0) {
            prev->quantity += current->quantity;
            current = current->next;
            list_remove_item_at_pos(head, prev->quantity);
            //list_print(*head);
        }
        else {
            prev = current;
            current = current->next;
        }
    }
    return EXIT_SUCCESS;
}