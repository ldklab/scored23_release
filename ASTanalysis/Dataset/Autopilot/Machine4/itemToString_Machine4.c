int list_item_to_string(node *head, char *str) {
  // Check if head is NULL
  if (head == NULL) {
    return EXIT_FAILURE;
  }

  // Else head is not NULL
  else {
    // Check if quantity is 0
    if (head->quantity == 0) {
      return EXIT_FAILURE;
    }

    // Else quantity is not 0
    else {
      // Check if quantity is 1
      if (head->quantity == 1) {
	sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
      }

      // Else quantity is not 1
      else {
	sprintf(str, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
      }
    }
  }
  return EXIT_SUCCESS;
}