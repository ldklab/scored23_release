node* find_prev_node(node* head, char* item_name, int pos) {
    node *curr = head;
    int i = 1;
    while (i < pos) {
        if (strcmp(curr->item_name, item_name) == 0)
            return curr;    // node with the same item_name!
        curr = curr->next;
        i++;
    }
    return NULL;
}