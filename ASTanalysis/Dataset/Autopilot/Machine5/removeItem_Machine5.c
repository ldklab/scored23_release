int list_remove_item_at_pos(node **head, int pos) {
	node *curr = *head;
	node *next = curr->next;
	
	int i = 0;
	while (curr && curr->item_name) {
		if (i == pos-1) {
			curr->next = next->next;
			free(next);
			return EXIT_SUCCESS;
		}
		
		curr = next;
		next = curr->next;
		
		i++;
	}
	
	return EXIT_FAILURE;
}