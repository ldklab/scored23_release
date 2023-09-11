int list_deduplicate(node **head) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *current = *head;
	node *prev = NULL;
	while (current != NULL) {
		node *scan = current->next;
		while (scan != NULL) {
			if (strcmp(current->item_name, scan->item_name) == 0) {
				current->quantity += scan->quantity;
				prev->next = scan->next;
				free(scan);
				scan = prev->next;
			}
			else {
				prev = scan;
				scan = scan->next;
			}
		}
		prev = current;
		current = current->next;
	}
	return EXIT_SUCCESS;
}