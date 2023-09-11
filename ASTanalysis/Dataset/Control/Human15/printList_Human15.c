int list_print(node *head) {
    node* curr = head;
    int count = 0;
    while (curr != NULL) {
    count++;
    printf('%d /n', count);
    printf('%s /n', head->item_name);
    printf('%d /n', head->price);
    curr = curr->next;
    }
    return EXIT_SUCCESS;
}