int list_swap_item_positions(node **head, int pos1, int pos2) {
  // Check if pos1 is 0
  if (pos1 == 0) {
    return EXIT_FAILURE;
  }

  // Check if pos2 is 0
  if (pos2 == 0) {
    return EXIT_FAILURE;
  }

  // Else pos1 and pos2 are not 0
  else {
    // Check if pos1 is 1
    if (pos1 == 1) {
      // Check if pos2 is 1
      if (pos2 == 1) {
	return EXIT_SUCCESS;
      }
      // Else pos2 is not 1
      else {
	// Call list_swap_item_positions on head->next and swap the result
	list_swap_item_positions(&((*head)->next), pos2 - 1, pos2);
	return EXIT_SUCCESS;
      }
    }
    // Else pos1 is not 1
    else {
      // Check if pos2 is 1
      if (pos2 == 1) {
	// Call list_swap_item_positions on head->next and swap the result
	list_swap_item_positions(&((*head)->next), pos1 - 1, pos1);
	return EXIT_SUCCESS;
      }
      // Else pos2 is not 1
      else {
	// Call list_swap_item_positions on head->next and swap the result
	list_swap_item_positions(&((*head)->next), pos1 - 1, pos2 - 1);
	return EXIT_SUCCESS;
      }
    }
  }
}