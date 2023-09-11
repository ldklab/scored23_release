int list_init(node **head) {
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Error: malloc failed\n");
        return EXIT_FAILURE;
    }
    new_node->item_name = NULL;
    new_node->price = 0;
    new_node->quantity = 0;
    new_node->next = *head;
    *head = new_node;
    return EXIT_SUCCESS;
}