int list_update_item_at_pos(node **head, char *item_name, float price, int quantity, unsigned int pos) {
	node *curr = *head;
	node *next = curr->next;
	
	int i = 0;
	while (curr && curr->item_name) {
		if (i == pos-1) {
			curr->item_name = item_name;
			curr->price = price;
			curr->quantity = quantity;
			return EXIT_SUCCESS;
		}
		
		curr = next;
		next = curr->next;
		
		i++;
	}
	
	return EXIT_FAILURE;
}