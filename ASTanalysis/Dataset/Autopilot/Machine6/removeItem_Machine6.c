int list_remove_item_at_pos(node **head, int pos) {
	if (*head == NULL) {
		fprintf(stderr, "Empty list!");
		return EXIT_FAILURE;
	}
	node *current = *head;
	unsigned int i = 0;
	while (current != NULL) {
		if (i == pos - 1) {
			node *next = current->next;
			free(current);
			current = next;
			break;
		}
		current = current->next;
		i++;
	}
	return EXIT_SUCCESS;
}