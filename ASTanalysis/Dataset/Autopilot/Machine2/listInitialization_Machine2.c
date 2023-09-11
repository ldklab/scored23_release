int list_init(node **head) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// allocate memory for node
	*head = malloc(sizeof(node));
	
	// check if malloc failed
	if(*head == NULL) {
		return EXIT_FAILURE;
	}
	
	// set members to NULL
	(*head)->item_name = NULL;
	(*head)->price = 0.0;
	(*head)->quantity = 0;
	(*head)->next = NULL;
	
	// return success
	return EXIT_SUCCESS;
}