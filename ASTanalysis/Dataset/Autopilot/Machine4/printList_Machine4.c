int list_print(node *head) {
  // Check if head is NULL
  if (head == NULL) {
    return EXIT_FAILURE;
  }

  // Else head is not NULL
  else {
    // Check if head is not at the end of the list
    if (head->next != NULL) {
      // Call list_print on head->next and print the result
      list_print(head->next);
    }

    // Else head is at the end of the list
    else {
      char *str;
      char *item_name_cpy;
      str = malloc(MAX_ITEM_PRINT_LEN);
      item_name_cpy = malloc(strlen(head->item_name) + 1);
      strcpy(item_name_cpy, head->item_name);
      // Check if list_item_to_string fails
      if (list_item_to_string(head, str) == EXIT_FAILURE) {
	return EXIT_FAILURE;
      }

      // Else list_item_to_string did not fail
      else {
	printf("%s\n", str);
      }
      free(str);
      free(item_name_cpy);
    }
  }
  return EXIT_SUCCESS;
}