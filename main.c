#include "links.c"

int main(int argc, char * argv[]) {
  buildLocations();
  buildItems();

  initscr();
  scrollok(stdscr, true);

//  thunder();

  while (!strMatch(command, "quit")) {
    clear();

    strcpy(locationBuffer, currentLocation().description);
    printLocalItems();

    render();

    action(command);
    incrementTime();
    stats();
    refresh();
  }

  endwin();
}
