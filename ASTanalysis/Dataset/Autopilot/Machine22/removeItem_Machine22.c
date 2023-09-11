int list_remove_item_at_pos(node **head, int pos) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *current = *head;
	int count = 1;
	while (current != NULL && count != pos) {
		count++;
		current = current->next;
	}

	if (current == NULL) {
		return EXIT_FAILURE;
	}

	node *prev = current->next;
	free(current);
	current = prev;
	return EXIT_SUCCESS;
}