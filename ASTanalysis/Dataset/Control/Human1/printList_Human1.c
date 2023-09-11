int list_print(node *head) {
    // TODO: Implement this function, 
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    if (head == NULL) {
        return EXIT_FAILURE;
    } 
    char out[100];
    node *item = head;
    int cnt = 0;
    // struct _node === node
    while (list_item_to_string(item, out) != EXIT_FAILURE) {
        printf("%d %s\n", cnt, out);
        item = item->next;
        cnt++;
    }
    //puts(out);
    return EXIT_SUCCESS;
}