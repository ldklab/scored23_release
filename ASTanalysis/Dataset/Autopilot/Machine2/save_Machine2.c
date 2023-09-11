int list_save(node *head, char *filename) {
	// check if head is NULL
	if(head == NULL) {
		return EXIT_FAILURE;
	}
	
	// set up temp node
	node *temp_node = head;
	
	// open file
	FILE *f = fopen(filename, "w");
	
	// check if file is NULL
	if(f == NULL) {
		return EXIT_FAILURE;
	}
	
	// write to file
	while(temp_node != NULL) {
		fprintf(f, "%s,%f,%d\n", temp_node->item_name, temp_node->price, temp_node->quantity);
		temp_node = temp_node->next;
	}
	
	// close file
	fclose(f);
	
	// return success
	return EXIT_SUCCESS;
}