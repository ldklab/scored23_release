int list_load(node **head, char *filename) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    return EXIT_FAILURE;
  }

  node *new_node = *head;
  while (new_node != NULL && new_node->next != NULL) {
    new_node = new_node->next;
  }

  char line[100];
  while (fgets(line, 100, file) != NULL) {
    if (new_node == NULL) {
      new_node = malloc(sizeof(node));
      *head = new_node;
    } else {
      new_node->next = malloc(sizeof(node));
      new_node = new_node->next;
    }
    char *item_name = strtok(line, ",");
    new_node->item_name = malloc(strlen(item_name) + 1);
    strcpy(new_node->item_name, item_name);
    new_node->price = atof(strtok(NULL, ","));
    new_node->quantity = atoi(strtok(NULL, "\n"));
    new_node->next = NULL;
  }
  fclose(file);
  return EXIT_SUCCESS;
}