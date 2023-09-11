int list_init(node **head) {
	if (!head) return EXIT_FAILURE;
	
	*head = malloc(sizeof(node));
	if (!*head) return EXIT_FAILURE;
	
	(*head)->next = NULL;
	
	return EXIT_SUCCESS;
}