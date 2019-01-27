void render() {
  formatText(locationBuffer, (COLS * .5) - 3);
  formatText(printBuffer, (COLS * .5) - 3);

  attron(A_BOLD);
  mvprintw(1, 0, currentLocation().name);
  attroff(A_BOLD);
  mvprintw(2, 0, locationBuffer);
  mvprintw(LINES * .5, 0, printBuffer);

  strcpy(inventoryBuffer, "");
  int i;
  for(i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
    if(!strMatch(inventory[i], "")){
      strcat(inventoryBuffer, inventory[i]);
      strcat(inventoryBuffer, ", ");
    }
  }
  
  formatText(inventoryBuffer, (COLS * .5) - 3);
  attron(A_BOLD | A_REVERSE);
  mvprintw(LINES * .5, (COLS * .5) + 5, "  I N V E N T O R Y  ");
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 1, (COLS * .5) + 5, inventoryBuffer);

  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 3, (COLS * .5) + 5, "  S T A T U S  ");
  attroff(A_BOLD | A_REVERSE);

  mvprintw((LINES * .5) + 4, (COLS * .5) + 5, "BLOOD");
  mvhline((LINES * .5) + 5, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 5, (COLS * .5) + 5, makeBar(blood));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 6, (COLS * .5) + 5, "STAMINA");
  mvhline((LINES * .5) + 7, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 7, (COLS * .5) + 5, makeBar(stamina));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 8, (COLS * .5) + 5, "MOBILITY");
  mvhline((LINES * .5) + 9, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 9, (COLS * .5) + 5, makeBar(mobility));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 10, (COLS * .5) + 5, "TEMPERATURE");
  mvhline((LINES * .5) + 11, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 11, (COLS * .5) + 5, makeBar(temperature));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 12, (COLS * .5) + 5, "THIRST");
  mvhline((LINES * .5) + 13, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 13, (COLS * .5) + 5, makeBar(thirst));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 14, (COLS * .5) + 5, "HUNGER");
  mvhline((LINES * .5) + 15, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 15, (COLS * .5) + 5, makeBar(hunger));
  attroff(A_BOLD | A_REVERSE);

  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 17, (COLS * .5) + 5, "  T I M E  ");
  attroff(A_BOLD | A_REVERSE);
  if(min !=0) {
    mvprintw((LINES * .5) + 19, (COLS * .5) + 5, "%ld:%ld", hour, min);
  } else {
    mvprintw((LINES * .5) + 19, (COLS * .5) + 5, "%ld:%ld%ld", hour, min, min);
  }
  if(day) {
    attron(A_BOLD | A_REVERSE);
    mvprintw((LINES * .5) + 18, (COLS * .5) + 5, "It is Day");
    attroff(A_BOLD | A_REVERSE);
  } else {
    mvprintw((LINES * .5) + 18, (COLS * .5) + 5, "It is Night");
  }

  mvhline(0, 0, ACS_CKBOARD, COLS);
  mvvline(0, COLS * .5, ACS_CKBOARD, LINES);
  mvhline(LINES - 1, 0, ACS_CKBOARD, COLS);

  attron(A_BOLD | A_REVERSE);
  mvprintw(0, 5, "Coconut Island");
  mvprintw(LINES - 1, 5, "By Matthew S Underwood");
  attroff(A_BOLD | A_REVERSE);

  mvprintw(LINES - 2, 1, "What do you do?");
  mvgetstr(LINES - 2, 17, command);
  command[strcspn(command, "\n")] = '\0';
  toLower(command);

  strcpy(printBuffer, "");
}
