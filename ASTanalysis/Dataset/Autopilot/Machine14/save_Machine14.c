int list_save(node *head, char *filename) {
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {
		return EXIT_FAILURE;
	}
	node *cur_node = head;
	while (cur_node != NULL) {
		fprintf(fp, "%s,%.2f,%d\n", cur_node->item_name, cur_node->price, cur_node->quantity);
		cur_node = cur_node->next;
	}
	fclose(fp);
	return EXIT_SUCCESS;
}