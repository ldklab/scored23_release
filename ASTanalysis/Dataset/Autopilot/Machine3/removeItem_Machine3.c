int list_remove_item_at_pos(node **head, int pos) {
	if(*head == NULL) {
		fprintf(stderr, "Error: list_remove_item_at_pos cannot remove an item from an empty list.\n");
		return EXIT_FAILURE;
	}
	if(pos == 0) {
		node *head_next = (*head)->next;
		free(*head);
		*head = head_next;
		return EXIT_SUCCESS;
	}
	node *current = *head;
	for(int i = 1; i < pos - 1; i++) {
		current = current->next;
	}
	node *next = current->next->next;
	free(current->next);
	current->next = next;
	return EXIT_SUCCESS;
}