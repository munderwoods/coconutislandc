#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ncurses.h> 
#include <unistd.h> 
#include <SDL2/SDL.h> 

struct Location {
  char name[50];
  char northDestination[50];
  char northAccess[50];
  char eastDestination[50];
  char eastAccess[50];
  char southDestination[50];
  char southAccess[50];
  char westDestination[50];
  char westAccess[50];
  char hiddenDestination1[50];
  char hiddenAccess1[50];
  char hiddenDestination2[50];
  char hiddenAccess2[50];
  char neutralDescription[300];
  char effectedDescription1[300];
  char effectedDescription2[300];
  char firstVisitText[300];
  char icon;
  bool visited;
  int temperature;
};

void getLocation(struct Location *location) {
  FILE * fpointer = fopen("locations", "r"); 

  char line[1000];

  while (strcmp(line, "***")) {

    fgets(line, 1000, fpointer);
    line[strcspn(line, "\n")] = '\0';

    if(strcmp(line, "[name]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->name, line);
    }
  
    if(strcmp(line, "[northDestination]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->northDestination, line);
    }
  
    if(strcmp(line, "[northAccess]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->northAccess, line);
    }
  
    if(strcmp(line, "[eastDestination]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->eastDestination, line);
    }
  
    if(strcmp(line, "[eastAccess]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->eastAccess, line);
    }
  
    if(strcmp(line, "[westDestination]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->westDestination, line);
    }
  
    if(strcmp(line, "[westAccess]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->westAccess, line);
    }
  
    if(strcmp(line, "[hiddenDestination1]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->hiddenDestination1, line);
    }
  
    if(strcmp(line, "[hiddenAccess1]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->hiddenAccess1, line);
    }
  
    if(strcmp(line, "[hiddenDestination2]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->hiddenDestination2, line);
    }
  
    if(strcmp(line, "[hiddenAccess2]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->hiddenAccess2, line);
    }
  
    if(strcmp(line, "[neutralDescription]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->neutralDescription, line);
    }
  
    if(strcmp(line, "[effectedDescription1]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->effectedDescription1, line);
    }
  
    if(strcmp(line, "[effectedDescription2]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->effectedDescription2, line);
    }
  
    if(strcmp(line, "[firstVisitText]") == 0) {
      fgets(line, 1000, fpointer);
      strcpy(location->firstVisitText, line);
    }
  
    if(strcmp(line, "[icon]") == 0) {
      fgets(line, 1000, fpointer);
      location->icon = line[0];
    }
  
    if(strcmp(line, "[visited]") == 0) {
      fgets(line, 1000, fpointer);
      location->visited = line == "true";
    }
  
    if(strcmp(line, "[temperature]") == 0) {
      fgets(line, 1000, fpointer);
      location->temperature = line[0] - '0';
    }
  }

  fclose(fpointer);
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

int wordlen(const char * str) {
  int tempindex = 0;
  while (str[tempindex] != ' ' && str[tempindex] != 0 && str[tempindex] != '\n') {
    ++tempindex;
  }
  return (tempindex);
}

void wrap(char * s,
  const int wrapline) {

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

int formatText(char * text, int y, int x, int maxX) {
  wrap(text, maxX);
}

int main(int argc, char * argv[]) {

  char command[20] = "INITIAL_COMMAND";

  struct Location currentLocation;

  getLocation(&currentLocation);

  initscr();
  scrollok(stdscr, true);

  thunder();

  while (strcmp(command, "quit")) {
    clear();

    if (strcmp(command, "INITIAL_COMMAND")) {
      mvprintw(LINES * .5 + 1, 1, "You entered: %s\n", command);
    }

    formatText(currentLocation.neutralDescription, 1, 1, (COLS * .5) - 3);
    attron(A_BOLD);
    mvprintw(1, 0, currentLocation.name);
    attroff(A_BOLD);
    mvprintw(2, 0, currentLocation.neutralDescription);

    mvhline(0, 0, ACS_BOARD, COLS);
    mvvline(0, COLS * .5, ACS_BOARD, LINES);
    mvhline(LINES - 1, 0, ACS_BOARD, COLS);

    attron(A_BOLD | A_REVERSE);

    mvprintw(0, 5, "Coconut Island");
    mvprintw(LINES - 1, 5, "By Matthew S Underwood");
    attroff(A_BOLD | A_REVERSE);

    mvprintw(LINES * .5, 1, "What do you do?");
    mvgetstr(LINES * .5, 17, command);
    command[strcspn(command, "\n")] = '\0';
    refresh();

  }

  endwin();
}
