int list_init(node **head) {
	if(*head == NULL) {
		*head = malloc(sizeof(node));
		if(!*head) {
			fprintf(stderr, "Error: list_init cannot allocate memory for head.\n");
			return EXIT_FAILURE;
		}
		(*head)->next = NULL;
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}