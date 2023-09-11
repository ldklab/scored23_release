int list_save(node *head, char *filename) {
  FILE *file = fopen(filename, "wb");
  node *current_node = head;
  if (file == NULL) {
    return EXIT_FAILURE;
  }
  while (current_node != NULL) {
    fprintf(file, "%s,%f,%d\n", current_node->item_name, current_node->price, current_node->quantity);
    current_node = current_node->next;
  }
  fclose(file);
  return EXIT_SUCCESS;
}