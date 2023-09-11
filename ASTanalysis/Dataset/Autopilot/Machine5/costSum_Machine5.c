int list_cost_sum(node *head, float *total) {
	node *curr = head;
	node *next = curr->next;
	float sum = 0;
	
	while (curr) {
		sum += curr->price * curr->quantity;
		curr = next;
		next = curr->next;
	}
	
	*total = sum;
	return EXIT_SUCCESS;
}