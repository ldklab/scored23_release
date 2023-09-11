int list_load(node **head, char *filename) {
  FILE *file = fopen(filename, "rb");
  if (file == NULL) {
    return EXIT_FAILURE;
  }
  node *current_node = *head;
  if (current_node == NULL) {
    return EXIT_FAILURE;
  }
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  while (1) {
    char item_name[100];
    float price;
    int quantity;
    int num_scanned = fscanf(file, "%[^,],%f,%d\n", item_name, &price, &quantity);
    if (num_scanned == EOF) {
      break;
    }
    if (num_scanned != 3) {
      return EXIT_FAILURE;
    }
    node *new_node = malloc(sizeof(node));
    new_node->item_name = malloc(sizeof(char) * (strlen(item_name) + 1));
    strcpy(new_node->item_name, item_name);
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = NULL;
    current_node->next = new_node;
    current_node = current_node->next;
  }
  fclose(file);
  return EXIT_SUCCESS;
}