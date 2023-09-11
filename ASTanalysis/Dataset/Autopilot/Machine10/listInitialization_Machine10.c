int list_init(node **head) {
    if (head == NULL) {
        return EXIT_FAILURE;
    } else {
        *head = malloc(sizeof(node));
        if (*head == NULL) {
            return EXIT_FAILURE;
        }
        (*head)->next = NULL;
        return EXIT_SUCCESS;
    }
}