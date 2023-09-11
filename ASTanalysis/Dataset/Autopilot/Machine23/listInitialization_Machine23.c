int list_init(node **head) {
    // create a new node
    *head = malloc(sizeof(node));
    if (head == NULL) {
        fprintf(stderr, "list_init: malloc failed\n");
        return EXIT_FAILURE;
    }

    // set all node members to initial values
    (*head)->item_name = NULL;
    (*head)->price = 0;
    (*head)->quantity = 0;
    (*head)->next = NULL;

    return EXIT_SUCCESS;
}