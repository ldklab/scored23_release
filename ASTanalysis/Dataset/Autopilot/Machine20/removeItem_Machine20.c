int list_remove_item_at_pos(node **head, int pos) {
	int status = EXIT_FAILURE;
	if (head != NULL && *head != NULL) {
		node *current = *head;
		node *previous = *head;
		int i = 1;
		while (current->next != NULL && i < pos) {
			previous = current;
			current = current->next;
			i++;
		}
		if (current == *head) {
			*head = (*head)->next;
		}
		else {
			previous->next = current->next;
		}
		free(current->item_name);
		free(current);
		status = EXIT_SUCCESS;
	}
	return status;
}