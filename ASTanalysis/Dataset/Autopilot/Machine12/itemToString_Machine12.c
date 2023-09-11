int list_item_to_string(node *head, char *str) {
  if (head == NULL || str == NULL) {
    return EXIT_FAILURE;
  }
  snprintf(str, MAX_ITEM_PRINT_LEN, "%d * %s @ $%.2f ea", head->quantity, head->item_name, head->price);
  return EXIT_SUCCESS;
}