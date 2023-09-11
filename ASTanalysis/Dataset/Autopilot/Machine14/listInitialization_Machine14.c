int list_init(node **head) {
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL) {
		return EXIT_FAILURE;
	}
	*head = new_node;
	new_node->next = NULL;
	return EXIT_SUCCESS;
}