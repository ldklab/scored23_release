int list_save(node *head, char *filename) {
  // Check if head is NULL
  if (head == NULL) {
    return EXIT_FAILURE;
  }
  // Else head is not NULL
  else {
    // Check if head->next is NULL
    if (head->next == NULL) {
      FILE *fp;
      fp = fopen(filename, "w");
      if (fp == NULL) {
	return EXIT_FAILURE;
      }
      fprintf(fp, "%s,%f,%d\n", head->item_name, head->price, head->quantity);
      fclose(fp);
      return EXIT_SUCCESS;
    }
    // Else head->next is not NULL
    else {
      // Call list_save on head->next and save the result
      list_save(head->next, filename);
      // Check if head->next->next is NULL
      if (head->next->next == NULL) {
	FILE *fp;
	fp = fopen(filename, "a");
	if (fp == NULL) {
	  return EXIT_FAILURE;
	}
	fprintf(fp, "%s,%f,%d\n", head->item_name, head->price, head->quantity);
	fclose(fp);
	return EXIT_SUCCESS;
      }
      // Else head->next->next is not NULL
      else {
	// Call list_save on head->next->next and save the result
	list_save(head->next->next, filename);
	return EXIT_SUCCESS;
      }
    }
  }
}