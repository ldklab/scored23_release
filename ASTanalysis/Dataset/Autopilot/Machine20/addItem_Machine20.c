int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
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
		node *new_node = (node *)malloc(sizeof(node));
		if (new_node != NULL) {
			new_node->item_name = strdup(item_name);
			new_node->price = price;
			new_node->quantity = quantity;
			new_node->next = current;
			if (current != *head) {
				previous->next = new_node;
			}
			else {
				*head = new_node;
			}
			status = EXIT_SUCCESS;
		}
	}
	return status;
}