int list_init(node **head) {
	// create a new list
	if (!(*head = (node *)malloc(sizeof(node)))) {
		printf("[ERROR] malloc failed\n");
		return EXIT_FAILURE;
	}
	(*head)->next = NULL;

	return EXIT_SUCCESS;
}