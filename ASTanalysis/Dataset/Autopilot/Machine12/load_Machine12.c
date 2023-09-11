int list_load(node **head, char *filename) {
  if (head == NULL || filename == NULL || filename[0] == '\0') {
    return EXIT_FAILURE;
  }
  FILE *fptr;
  fptr = fopen(filename, "r");
  if (fptr == NULL) {
    return EXIT_FAILURE;
  }
  char item_name[100];
  float price;
  int quantity;
  while (fscanf(fptr, "%[^,],%f,%d\n", item_name, &price, &quantity) != EOF) {
    node *curr = *head;
    if (curr == NULL) {
      node *new_node = (node *)malloc(sizeof(node));
      new_node->item_name = (char *)malloc(sizeof(char) * (strlen(item_name) + 1));
      strcpy(new_node->item_name, item_name);
      new_node->price = price;
      new_node->quantity = quantity;
      new_node->next = NULL;
      *head = new_node;
      continue;
    }
    while (curr->next != NULL) {
      curr = curr->next;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->item_name = (char *)malloc(sizeof(char) * (strlen(item_name) + 1));
    strcpy(new_node->item_name, item_name);
    new_node->price = price;
    new_node->quantity = quantity;
    new_node->next = NULL;
    curr->next = new_node;
  }
  fclose(fptr);
  return EXIT_SUCCESS;
}