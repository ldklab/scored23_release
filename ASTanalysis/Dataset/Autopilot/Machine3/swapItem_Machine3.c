int list_swap_item_positions(node **head, int pos1, int pos2) {
	if(*head == NULL) {
		fprintf(stderr, "Error: list_swap_item_positions cannot swap two items in an empty list.\n");
		return EXIT_FAILURE;
	}
	if(pos1 == 0) {
		node *head_next = (*head)->next;
		free(*head);
		*head = head_next;
		return EXIT_SUCCESS;
	}
	node *current = *head;
	for(int i = 1; i < pos1 - 1; i++) {
		current = current->next;
	}
	node *next1 = current->next;
	for(int i = 1; i < pos2 - 1; i++) {
		current = current->next;
	}
	node *next2 = current->next;
	current->next = next2;
	next1->next = next2->next;
	next2->next = next1;
	return EXIT_SUCCESS;
}