int list_deduplicate(node **head) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        int item_name_len = strlen((*head)->item_name);
        node *cur1 = *head;
        node *prev = NULL;
        node *cur2 = *head;
        while (cur1 != NULL) {
            while (cur2 != NULL) {
                if (cur1 != cur2 && strncmp(cur1->item_name, cur2->item_name, item_name_len) == 0) {
                    cur1->quantity += cur2->quantity;
                    cur2->quantity = 0;
                }
                cur2 = cur2->next;
            }
            cur1 = cur1->next;
            cur2 = *head;
        }
        return EXIT_SUCCESS;
    }
}