int list_swap_item_positions(node **head, int pos1, int pos2) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        node *cur1 = *head;
        node *cur2 = *head;
        unsigned int k1 = 0;
        unsigned int k2 = 0;
        while (cur1 != NULL) {
            if (k1 == pos1) {
                break;
            } else {
                k1++;
                cur1 = cur1->next;
            }
        }
        while (cur2 != NULL) {
            if (k2 == pos2) {
                break;
            } else {
                k2++;
                cur2 = cur2->next;
            }
        }
        if (cur1 == NULL || cur2 == NULL) {
            return EXIT_FAILURE;
        } else {
            cur1->item_name = malloc(strlen(cur2->item_name) + 1);
            if (cur1->item_name == NULL) {
                return EXIT_FAILURE;
            }
            strcpy(cur1->item_name, cur2->item_name);
            cur1->price = cur2->price;
            cur1->quantity = cur2->quantity;
            cur2->item_name = malloc(strlen(cur1->item_name) + 1);
            if (cur2->item_name == NULL) {
                return EXIT_FAILURE;
            }
            strcpy(cur2->item_name, cur1->item_name);
            cur2->price = cur1->price;
            cur2->quantity = cur1->quantity;
            return EXIT_SUCCESS;
        }
    }
}