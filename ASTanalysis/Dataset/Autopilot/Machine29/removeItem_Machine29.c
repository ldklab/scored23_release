int list_remove_item_at_pos(node **head, int pos) {
	if (pos < 1) {
		return EXIT_FAILURE;
	}

	if (*head == NULL) {
		return EXIT_FAILURE;
	}
	if (pos == 1) {
		node *removed_node = *head;
		*head = (*head)->next;
		free(removed_node->item_name);
		free(removed_node);
		return EXIT_SUCCESS;
	}
	unsigned int current_pos = 1;
	node *current = *head;
	while (current->next != NULL && current_pos < pos - 1) {
		current = current->next;
		current_pos += 1;
	}
	if (current_pos != pos - 1) {
		return EXIT_FAILURE;
	}
	node *removed_node = current->next;
	current->next = current->next->next;
	free(removed_node->item_name);
	free(removed_node);
	return EXIT_SUCCESS;
}