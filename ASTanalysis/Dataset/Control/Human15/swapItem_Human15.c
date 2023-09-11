int list_swap_item_positions(node **head, int pos1, int pos2) {
    int count1 = 0;
    int count2 = 0;
    node* first = head;
    node* sec = head;
    node* temp = head;
    while (count1 != pos1) {
        first = first->next;
        count1++;
    }

    while (count2 != pos2) {
        sec = sec->next;
        count2++;
    }

    temp = first;
    first = sec;
    sec = temp;
    temp = NULL;
    return EXIT_SUCCESS;
}