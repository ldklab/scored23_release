int list_item_to_string(node *head, char *str) {
  char *str_ptr = str;
  char *format_str = "%d * %s @ $%.2f ea\n";

  if (head == NULL) {
    return EXIT_FAILURE;
  }
  int written_chars = sprintf(str_ptr, format_str, head->quantity, head->item_name, head->price);
  if (written_chars < 0) {
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}