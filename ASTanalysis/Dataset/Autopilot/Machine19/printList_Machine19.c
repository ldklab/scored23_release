int list_print(node *head) {
	if(head == NULL) {
		return EXIT_FAILURE;
	}

	node *temp = head;
	int pos = 1;
	while(temp != NULL) {
		char str[MAX_ITEM_PRINT_LEN];
		list_item_to_string(temp, str);
		printf("%d: %s\n", pos, str);
		
		temp = temp->next;
		pos++;
	}
	return EXIT_SUCCESS;
}