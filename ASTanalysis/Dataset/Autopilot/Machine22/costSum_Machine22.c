int list_cost_sum(node *head, float *total) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *current = head;
	float sum = 0.0;
	while (current != NULL) {
		sum = sum + (current->price * current->quantity);
		current = current->next;
	}
	*total = sum;
	return EXIT_SUCCESS;
}