int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if (*head == NULL) {
		fprintf(stderr, "Empty list!");
		return EXIT_FAILURE;
	}
	node *current = *head;
	unsigned int i = 0;
	while (current != NULL) {
		if (i == pos - 1) {
			current->item_name = malloc(sizeof(char) * strlen(item_name));
			strcpy(current->item_name, item_name);
			current->price = price;
			current->quantity = quantity;
			break;
		}
		current = current->next;
		i++;
	}
	return EXIT_SUCCESS;
}