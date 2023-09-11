int list_find_highest_price_item_position(node *head, int *pos) {
	node *curr = head;
	node *next = curr->next;
	
	float highest_price = curr->price;
	int highest_price_pos = 0;
	
	int i = 0;
	while (curr && curr->item_name) {
		if (curr->price > highest_price) {
			highest_price = curr->price;
			highest_price_pos = i+1;
		}
		
		curr = next;
		next = curr->next;
		
		i++;
	}
	
	*pos = highest_price_pos;
	return EXIT_SUCCESS;
}