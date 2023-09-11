int list_add_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	node *curr = *head;
	node *new_item;
	
	if (!head || !item_name) return EXIT_FAILURE;
	
	if (pos == 0) {
		new_item = malloc(sizeof(node));
		if (!new_item) return EXIT_FAILURE;
		
		new_item->item_name = item_name;
		new_item->price = price;
		new_item->quantity = quantity;
		new_item->next = NULL;
		
		*head = new_item;
		
		return EXIT_SUCCESS;
	}
	
	int i = 0;
	while (curr) {
		if (i == pos-1) {
			new_item = malloc(sizeof(node));
			if (!new_item) return EXIT_FAILURE;
			
			new_item->item_name = item_name;
			new_item->price = price;
			new_item->quantity = quantity;
			new_item->next = curr->next;
			
			curr->next = new_item;
			
			return EXIT_SUCCESS;
		}
		
		curr = curr->next;
		i++;
	}
	
	return EXIT_FAILURE;
}