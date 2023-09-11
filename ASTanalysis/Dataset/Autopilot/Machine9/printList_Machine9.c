int list_print(node *head) {
  int i = 0;
  char *str;
  if (!head) {
    return EXIT_SUCCESS;
  }
  snprintf(str, MAX_ITEM_PRINT_LEN, "%d", i);
  // check if there is no head
  if (!head->item_name) {
    return EXIT_SUCCESS;
  }
  // check if there is no item_name
  if (!head->next) {
    // if there is only one item
    if (head->quantity > 1) {
      // if quantity is greater than 1
      printf("%s: %d * %s @ $%.2f ea\n", str, head->quantity, head->item_name, head->price);
      return EXIT_SUCCESS;
    } else {
      // if quantity is 1
      printf("%s: %s @ $%.2f ea\n", str, head->item_name, head->price);
      return EXIT_SUCCESS;
    }
  }
  // if there is more than one item
  // check if there is no next node
  if (head->quantity > 1) {
    // if quantity is greater than 1
    printf("%s: %d * %s @ $%.2f ea\n", str, head->quantity, head->item_name, head->price);
    return EXIT_SUCCESS;
  } else {
    // if quantity is 1
    printf("%s: %s @ $%.2f ea\n", str, head->item_name, head->price);
    return EXIT_SUCCESS;
  }
}