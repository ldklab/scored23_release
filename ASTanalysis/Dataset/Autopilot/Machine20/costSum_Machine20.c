int list_cost_sum(node *head, float *total) {
	int status = EXIT_FAILURE;
	if (head!= NULL && total!= NULL) {
		node *current = head;
		float sum = 0.0;
		while (current->next!= NULL) {
			sum += current->price * current->quantity;
			current = current->next;
		}
		*total = sum;
		status = EXIT_SUCCESS;
	}
	return status;
}