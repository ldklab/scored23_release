int list_deduplicate(node **head) {
	if (*head == NULL) {
		return EXIT_FAILURE;
	}
	node *current = *head;
	while (current->next!= NULL) {
		node *next = current->next;
		while (next!= NULL) {
			if (strcmp(current->item_name, next->item_name)== 0) {
				current->quantity += next->quantity;
				list_remove_item_at_pos(head, 2);
			}
			next = next->next;
		}
		current = current->next;
	}
	return EXIT_SUCCESS;
}