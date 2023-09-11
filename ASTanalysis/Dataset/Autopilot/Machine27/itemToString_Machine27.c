int list_item_to_string(node *head, char *str) {
  if (head == NULL) {
    strcpy(str, "");
    return EXIT_FAILURE;
  }
  char str_price[MAX_ITEM_PRINT_LEN];
  sprintf(str_price, "%.2f", head->price);
  sprintf(str, "%d * %s @ $%s ea", head->quantity, head->item_name, str_price);
  return EXIT_SUCCESS;
}