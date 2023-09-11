int list_init(node **head) {
    // check for NULL pointer
    if (head == NULL) return EXIT_FAILURE;

    // initialize the first node
    *head = (node *)malloc(sizeof(node));
    if (*head == NULL) return EXIT_FAILURE;

    // initialize the first node
    (*head)->item_name = NULL;
    (*head)->price = 0.0;
    (*head)->quantity = 0;
    (*head)->next = NULL;
    return EXIT_SUCCESS;
}