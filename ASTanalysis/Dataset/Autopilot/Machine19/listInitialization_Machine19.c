int list_init(node **head) {
	if(head == NULL) {
		return EXIT_FAILURE;
	}

	*head = NULL;
	return EXIT_SUCCESS;
}