int list_deduplicate(node **head) {
	node *curr = *head;
	node *next = curr->next;
	node *next_next = next->next;
	int found = 0;
	
	while (curr->next) {
		if (curr->item_name == next->item_name) {
			curr->quantity += next->quantity;
			found = 1;
		}
		
		curr = next;
		next = next_next;
		if (next) next_next = next->next;
	}
	
	if (found) {
		*head = curr;
		list_remove_item_at_pos(head, 1);
	}
	
	return EXIT_SUCCESS;
}