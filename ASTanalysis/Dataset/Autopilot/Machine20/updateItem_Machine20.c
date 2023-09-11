int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	int status = EXIT_FAILURE;
	if (head != NULL && *head != NULL) {
		node *current = *head;
		int i = 1;
		while (current->next != NULL && i < pos) {
			current = current->next;
			i++;
		}
		current->item_name = strdup(item_name);
		current->price = price;
		current->quantity = quantity;
		status = EXIT_SUCCESS;
	}
	return status;
}