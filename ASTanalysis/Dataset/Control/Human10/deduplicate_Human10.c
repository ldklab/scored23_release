int list_deduplicate(node **head) 
{
    node* n = *head;
    int pos_n = 1;

    while (n != NULL) {
        node* m = n->next;
        int pos_m = pos_n+1;
        while (m != NULL) {
            if (strcmp(n->item_name, m->item_name) == 0) {
                n->quantity += m->quantity;
                list_remove_item_at_pos(head, pos_m);
            }
            m = m->next;
            pos_m++;
        }
        n = n->next;
        pos_n++;
    }

    return EXIT_SUCCESS;
}