int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if(*head == NULL) {
		fprintf(stderr, "Error: list_update_item_at_pos cannot update an item in an empty list.\n");
		return EXIT_FAILURE;
	}
	if(pos == 0) {
		(*head)->item_name = item_name;
		(*head)->price = price;
		(*head)->quantity = quantity;
		return EXIT_SUCCESS;
	}
	node *current = *head;
	for(int i = 1; i < pos; i++) {
		current = current->next;
	}
	current->item_name = item_name;
	current->price = price;
	current->quantity = quantity;
	return EXIT_SUCCESS;
}