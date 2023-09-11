int list_cost_sum(node *head, float *total) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// set up temp node
	node *temp_node = head;
	int i = 0;
	float sum = 0;
	
	// traverse to end of list
	while(temp_node!= NULL) {
		sum += ((temp_node->price) * (temp_node->quantity));
		temp_node = temp_node->next;
		i++;
	}
	
	// set total to sum
	*total = sum;
	
	// return success
	return EXIT_SUCCESS;
}