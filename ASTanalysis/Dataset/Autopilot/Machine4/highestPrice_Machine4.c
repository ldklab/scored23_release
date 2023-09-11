int list_find_highest_price_item_position(node *head, int *pos) {
  // Check if head is NULL
  if (head == NULL) {
    *pos = 0;
    return EXIT_FAILURE;
  }
  // Else head is not NULL
  else {
    // Check if head->next is NULL
    if (head->next == NULL) {
      *pos = 1;
      return EXIT_SUCCESS;
    }
    // Else head->next is not NULL
    else {
      // Call list_find_highest_price_item_position on head->next and get the result
      list_find_highest_price_item_position(head->next, pos);
      // Check if the result is EXIT_FAILURE
      if (*pos == 0) {
	return EXIT_FAILURE;
      }
      // Else the result is EXIT_SUCCESS
      else {
	// Check if head->price is higher than head->next->price
	if (head->price > head->next->price) {
	  // Check if head->price is higher than head->next->next->price
	  if (head->price > (head->next->next)->price) {
	    // Check if head->price is higher than head->next->next->next->price
	    if (head->price > (head->next->next->next)->price) {
	      *pos = 1;
	      return EXIT_SUCCESS;
	    }
	    // Else head->price is not higher than head->next->next->next->price
	    else {
	      *pos = 2;
	      return EXIT_SUCCESS;
	    }
	  }
	  // Else head->price is not higher than head->next->next->price
	  else {
	    *pos = 2;
	    return EXIT_SUCCESS;
	  }
	}
	// Else head->price is not higher than head->next->price
	else {
	  *pos = 1;
	  return EXIT_SUCCESS;
	}
      }
    }
  }
}