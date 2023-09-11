int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	if (*head == NULL) {
		list_init(head);
	}
	node *current = *head;
	unsigned int i = 0;
	while (current != NULL) {
		if (i == pos - 1) {
			node *new = malloc(sizeof(node));
			if (!new) {
				fprintf(stderr, "Not enough memory!");
				return EXIT_FAILURE;
			}
			new->item_name = malloc(sizeof(char) * strlen(item_name));
			if (!new->item_name) {
				fprintf(stderr, "Not enough memory!");
				return EXIT_FAILURE;
			}
			strcpy(new->item_name, item_name);
			new->price = price;
			new->quantity = quantity;
			new->next = current->next;
			current->next = new;
			break;
		}
		current = current->next;
		i++;
	}
	return EXIT_SUCCESS;
}