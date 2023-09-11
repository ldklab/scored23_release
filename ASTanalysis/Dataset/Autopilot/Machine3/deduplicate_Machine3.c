int list_deduplicate(node **head) {
	if(*head == NULL) {
		fprintf(stderr, "Error: list_deduplicate cannot de-duplicate an empty list.\n");
		return EXIT_FAILURE;
	}
	if((*head)->next == NULL) {
		return EXIT_SUCCESS;
	}
	node *current = *head;
	while(current->next != NULL) {
		if(strcmp(current->item_name, current->next->item_name) == 0) {
			current->quantity = current->quantity + current->next->quantity;
			current->next = current->next->next;
		}
		else {
			current = current->next;
		}
	}
	return EXIT_SUCCESS;
}