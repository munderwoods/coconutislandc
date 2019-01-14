#include "links.c"
#include "declarations.c"
#include "functions.c"

int main(int argc, char * argv[]) {
  buildLocations();
  buildItems();

  initscr();
  scrollok(stdscr, true);

//  thunder();

  while (!strMatch(command, "quit")) {
    clear();

    strcpy(locationBuffer, currentLocation().neutralDescription);
    printLocalItems();

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
    action(command);
    refresh();
  }

  endwin();
}
