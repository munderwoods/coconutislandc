void render() {
  formatText(locationBuffer, (COLS * .5) - 3);
  formatText(printBuffer, (COLS * .5) - 3);

  attron(A_BOLD);
  mvprintw(1, 0, currentLocation().name);
  attroff(A_BOLD);
  mvprintw(2, 0, locationBuffer);
  mvprintw(LINES * .5, 0, printBuffer);

  if(itemInInventory("Map")) {
    attron(A_BOLD | A_REVERSE);
    mvprintw(2, (COLS * .5) + 5, "            M A P            ");
    attroff(A_BOLD | A_REVERSE);
    int x;
    int y;
    for(x = 0; x < sizeof(map) / sizeof(map[0]); x++) {
      for(y = 0; y < sizeof(map[0]) / sizeof(map[0][0]); y++) {
        mvprintw(3 + y, (COLS * .5) + 6 + (x*2), map[x][y]);
      }
    }

    mvvline(3, (COLS * .5) + 5, ACS_VLINE, 15);
    mvvline(3, (COLS * .5) + 33, ACS_VLINE, 15);
    mvhline(18, (COLS * .5) + 6, ACS_HLINE, 27);
    mvhline(18, (COLS * .5) + 5, ACS_LLCORNER, 1);
    mvhline(18, (COLS * .5) + 33, ACS_LRCORNER, 1);
  }

  strcpy(inventoryBuffer, "");
  int a;
  for(a = 0; a < sizeof(inventory) / sizeof(inventory[0]); a++) {
    if(!strMatch(inventory[a], "")){
      strcat(inventoryBuffer, inventory[a]);
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

  strcpy(statusBuffer, "");
  int b;
  for(b = 0; b < sizeof(status) / sizeof(status[0]); b++) {
    if(!strMatch(status[b], "")){
      strcat(statusBuffer, status[b]);
      strcat(statusBuffer, ", ");
    }
  }
  
  mvprintw((LINES * .5) + 4, (COLS * .5) + 5, statusBuffer);

  mvprintw((LINES * .5) + 7, (COLS * .5) + 5, "BLOOD");
  mvhline((LINES * .5) + 8, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 8, (COLS * .5) + 5, makeBar(blood));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 9, (COLS * .5) + 5, "STAMINA");
  mvhline((LINES * .5) + 10, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 10, (COLS * .5) + 5, makeBar(stamina));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 11, (COLS * .5) + 5, "MOBILITY");
  mvhline((LINES * .5) + 12, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 12, (COLS * .5) + 5, makeBar(mobility));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 13, (COLS * .5) + 5, "TEMPERATURE");
  mvhline((LINES * .5) + 14, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 14, (COLS * .5) + 5, makeBar(temperature));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 15, (COLS * .5) + 5, "THIRST");
  mvhline((LINES * .5) + 16, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 16, (COLS * .5) + 5, makeBar(thirst));
  attroff(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 17, (COLS * .5) + 5, "HUNGER");
  mvhline((LINES * .5) + 18, (COLS * .5) + 5, ACS_CKBOARD, 10);
  attron(A_BOLD | A_REVERSE);
  mvprintw((LINES * .5) + 18, (COLS * .5) + 5, makeBar(hunger));
  attroff(A_BOLD | A_REVERSE);

  attron(A_BOLD | A_REVERSE);
  mvprintw(LINES - 4, (COLS * .5) + 5, "  T I M E  ");
  attroff(A_BOLD | A_REVERSE);
  if(min !=0) {
    mvprintw(LINES - 3, (COLS * .5) + 5, "%ld:%ld", hour, min);
  } else {
    mvprintw(LINES - 3, (COLS * .5) + 5, "%ld:%ld%ld", hour, min, min);
  }
  if(day) {
    attron(A_BOLD | A_REVERSE);
    mvprintw(LINES - 2, (COLS * .5) + 5, "It is Day");
    attroff(A_BOLD | A_REVERSE);
  } else {
    mvprintw(LINES - 2, (COLS * .5) + 5, "It is Night");
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
