int list_init(node **head) {
	*head = malloc(sizeof(node));
	if (*head == NULL) {
		return EXIT_FAILURE;
	}
	(*head)->next = NULL;
	return EXIT_SUCCESS;
}