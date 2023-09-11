int list_swap_item_positions(node **head, int pos1, int pos2) {
    int result = EXIT_SUCCESS;
    node *pos1_node = NULL;
    node *pos2_node = NULL;
    node *prev_to_pos1 = NULL;
    node *prev_to_pos2 = NULL;
    int i = 0;

    if (pos1 == pos2) {
        return result;
    }

    if (pos1 == 0) {
        pos1_node = *head;
    } else {
        prev_to_pos1 = *head;

        while (i < pos1) {
            prev_to_pos1 = pos1_node;
            pos1_node = pos1_node->next;
            i++;
        }
    }

    if (pos2 == 0) {
        pos2_node = *head;
    } else {
        prev_to_pos2 = *head;

        while (i < pos2) {
            prev_to_pos2 = pos2_node;
            pos2_node = pos2_node->next;
            i++;
        }
    }

    if (pos1_node == NULL || pos2_node == NULL) {
        result = EXIT_FAILURE;
    } else {
        if (pos1_node == *head) {
            *head = pos2_node;
        } else {
            prev_to_pos1->next = pos2_node;
        }

        if (pos2_node == *head) {
            *head = pos1_node;
        } else {
            prev_to_pos2->next = pos1_node;
        }

        node *temp = pos1_node->next;
        pos1_node->next = pos2_node->next;
        pos2_node->next = temp;
    }

    return result;
}