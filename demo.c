#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ncurses.h> 
#include <unistd.h> 
#include <SDL2/SDL.h> 
#include "locations.c"

char printBuffer[1000] = "Welcome to coconut island. Travel is limited to cardinal directions, N, S, E, W.";
char locationBuffer[1000] = "";
char command[20] = "INITIAL_COMMAND";
char currentLocationName[20] = "Ricken's Door";

int thunder();
void toLower(char * str);
int wordlen(const char * str); 
void wrap(char * s, const int wrapline); 
int formatText(char * text, int maxX);
void addToPrintBuffer(char * text); 
Location currentLocation();

void movec(char * direction); 
void action(char * command); 

int main(int argc, char * argv[]) {
	buildLocations();

  initscr();
  scrollok(stdscr, true);

//  thunder();

  while (strcmp(command, "quit")) {
    clear();

		strcpy(locationBuffer, currentLocation().neutralDescription);

    if (strcmp(command, "INITIAL_COMMAND")) {
      mvprintw(LINES - 2 + 1, 1, "You entered: %s\n", command);
    }

    formatText(locationBuffer, (COLS * .5) - 3);
    formatText(printBuffer, (COLS * .5) - 3);

    attron(A_BOLD);
    mvprintw(1, 0, currentLocation().name);
    attroff(A_BOLD);
    mvprintw(2, 0, locationBuffer);
    mvprintw(LINES * .5, 0, printBuffer);

    mvhline(0, 0, ACS_CKBOARD, COLS);
    mvvline(0, COLS * .5, ACS_CKBOARD, LINES);
    mvhline(LINES - 1, 0, ACS_CKBOARD, COLS);

    attron(A_BOLD | A_REVERSE);
    mvprintw(0, 5, "Coconut Island");
    mvprintw(LINES - 1, 5, "By Matthew S Underwood");
    attroff(A_BOLD | A_REVERSE);

    mvprintw(LINES - 3, 1, "What do you do?");
    mvgetstr(LINES - 3, 17, command);
    command[strcspn(command, "\n")] = '\0';
		toLower(command);

    strcpy(printBuffer, "");
    action(command);
    refresh();
  }

  endwin();
}

int thunder() {
	SDL_Init(SDL_INIT_AUDIO);
	SDL_AudioSpec wavSpec;
	Uint32 wavLength;
	Uint8 * wavBuffer;

	SDL_LoadWAV("thunder.wav", & wavSpec, & wavBuffer, & wavLength);
	SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, & wavSpec, NULL, 0);
	int success = SDL_QueueAudio(deviceId, wavBuffer, wavLength);
	SDL_PauseAudioDevice(deviceId, 0);
	SDL_Delay(3000);
	SDL_CloseAudioDevice(deviceId);
	SDL_FreeWAV(wavBuffer);
	SDL_Quit();

	return 0;
}

void toLower(char * str) {
	for(int i = 0; str[i]; i++){
		str[i] = tolower(str[i]);
	}
}

int wordlen(const char * str) {
  int tempindex = 0;
  while (str[tempindex] != ' ' && str[tempindex] != 0 && str[tempindex] != '\n') {
    ++tempindex;
  }
  return (tempindex);
}

void wrap(char * s, const int wrapline) {

  int index = 0;
  int curlinelen = 0;
  while (s[index] != '\0') {

    if (s[index] == '\n') {
      curlinelen = 0;
    } else if (s[index] == ' ') {

      if (curlinelen + wordlen( & s[index + 1]) >= wrapline) {
        s[index] = '\n';
        curlinelen = 0;
      }

    }

    curlinelen++;
    index++;
  }

}

int formatText(char * text, int maxX) {
  wrap(text, maxX);
}

void addToPrintBuffer(char * text) {
    strcat(printBuffer, " ");
    strcat(printBuffer, text);
}

Location currentLocation() {
	size_t els = sizeof(locations)/sizeof(locations[0]);
	for(int i = 0; i < els; ++i) {
		if(strcmp(locations[i].name, currentLocationName) == 0) {
			return locations[i];
		}
	}
} 

void movec(char * direction) {
	if(strcmp(direction, "north") == 0) {
		if(strcmp(currentLocation().northDestination, "None") == 0) {
			addToPrintBuffer("You cannot.");
		} else {
			strcpy(currentLocationName, currentLocation().northDestination);
		}
	}
	if(strcmp(direction, "east") == 0) {
		if(strcmp(currentLocation().eastDestination, "None") == 0) {
			addToPrintBuffer("You cannot.");
		} else {
			strcpy(currentLocationName, currentLocation().eastDestination);
		}
	}
	if(strcmp(direction, "south") == 0) {
		if(strcmp(currentLocation().southDestination, "None") == 0) {
			addToPrintBuffer("You cannot.");
		} else {
			strcpy(currentLocationName, currentLocation().southDestination);
		}
	}
	if(strcmp(direction, "west") == 0) {
		if(strcmp(currentLocation().westDestination, "None") == 0) {
			addToPrintBuffer("You cannot.");
		} else {
			strcpy(currentLocationName, currentLocation().westDestination);
		}
	}
}

void action(char * command) {
  if (strstr(command, "n") != NULL || strstr(command, "north") != NULL) {
    movec("north");
  } else if (strcmp(command, "e") == 0 || strstr(command, "east") != NULL) {
    movec("east");
  } else if (strcmp(command, "s") == 0 || strstr(command, "south") != NULL) {
    movec("south");
  } else if (strcmp(command, "w") == 0 || strstr(command, "west") != NULL) {
    movec("west");
  } else {
    addToPrintBuffer("You Cannot.");
  }
}

