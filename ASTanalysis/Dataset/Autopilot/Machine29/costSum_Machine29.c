int list_cost_sum(node *head, float *total) {
	if (head == NULL) {
		return EXIT_FAILURE;
	}
	node *current = head;
	*total = 0;
	while (current != NULL) {
		*total += current->price * current->quantity;
		current = current->next;
	}
	return EXIT_SUCCESS;
}