int list_cost_sum(node *head, float *total) {
  // Check if head is NULL
  if (head == NULL) {
    *total = 0;
    return EXIT_FAILURE;
  }
  // Else head is not NULL
  else {
    // Check if head->next is NULL
    if (head->next == NULL) {
      *total = head->price * head->quantity;
      return EXIT_SUCCESS;
    }
    // Else head->next is not NULL
    else {
      // Call list_cost_sum on head->next and get the result
      list_cost_sum(head->next, total);
      // Check if the result is EXIT_FAILURE
      if (*total == 0) {
	return EXIT_FAILURE;
      }
      // Else the result is EXIT_SUCCESS
      else {
	// Add head->price * head->quantity to the result
	*total = *total + head->price * head->quantity;
	return EXIT_SUCCESS;
      }
    }
  }
}