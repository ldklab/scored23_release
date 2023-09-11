int list_swap_item_positions(node **head, int pos1, int pos2) {
	node *curr = *head;
	node *next = curr->next;
	node *swap_1 = NULL;
	node *swap_2 = NULL;
	
	int i = 0;
	while (curr && curr->item_name) {
		if (i == pos1-1) {
			swap_1 = curr;
		}
		if (i == pos2-1) {
			swap_2 = curr;
		}
		
		curr = next;
		next = curr->next;
		
		i++;
	}
	
	node *temp = swap_1->next;
	swap_1->next = swap_2->next;
	swap_2->next = temp;
	
	return EXIT_SUCCESS;
}