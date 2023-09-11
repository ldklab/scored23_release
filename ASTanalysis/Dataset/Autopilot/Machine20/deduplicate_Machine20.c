int list_deduplicate(node **head) {
	int status = EXIT_FAILURE;
	if (head!= NULL && *head!= NULL) {
		node *current = *head;
		node *previous = *head;
		node *next = current->next;
		while (current->next!= NULL) {
			if (strcmp(previous->item_name, current->item_name)==0) {
				previous->quantity += current->quantity;
				previous->next = next;
				free(current->item_name);
				free(current);
				current = previous;
				next = current->next;
			}
			else {
				previous = current;
				current = current->next;
				next = current->next;
			}
		}
		status = EXIT_SUCCESS;
	}
	return status;
}