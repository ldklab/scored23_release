int list_remove_item_at_pos(node **head, int pos) {
	// If pos is 0, return EXIT_FAILURE
	if (pos == 0) {
		return EXIT_FAILURE;
	}

	// If pos is 1, remove the head
	if (pos == 1) {
		node *temp = *head;
		*head = (*head)->next;
		free(temp->item_name);
		free(temp);
		return EXIT_SUCCESS;
	}

	// If pos is greater than 1, find the node at pos - 1
	int i;
	node *current = *head;
	for (i = 1; i < pos - 1; i++) {
		current = current->next;
		if (current == NULL) {
			return EXIT_FAILURE;
		}
	}

	// Remove the node
	node *temp = current->next;
	current->next = temp->next;
	free(temp->item_name);
	free(temp);
	return EXIT_SUCCESS;
}