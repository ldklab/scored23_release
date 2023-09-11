int list_item_to_string(node *head, char *str) {
    // TODO: Implement this function
    
    // str = head->quantity + " * " + head->item_name + " @ $" + head->price + " ea"

    char* firstPart = sprintf("%d * ", head->quantity);
    char* secondPart = sprintf(" @ $%d ea\0", (int) head->price);

    char* one = strcat(firstPart, head->item_name);
    str = strcat(one, secondPart);
    // str = head->quantity + " * " + head->item_name + " @ $" + head->price + " ea"
    // return EXIT_SUCCESS or EXIT_FAILURE when appropriate
    return EXIT_SUCCESS;
}