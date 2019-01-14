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

bool strMatch(char * str1, char * str2) {
  return strcmp(str1, str2) == 0;
}

bool strContain(char * str, char * key) {
  strstr(str, key) != NULL;
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
  strcat(printBuffer, text);
  strcat(printBuffer, " ");
}

Location currentLocation() {
  size_t els = sizeof(locations)/sizeof(locations[0]);
  for(int i = 0; i < els; ++i) {
    if(strMatch(locations[i].name, currentLocationName)) {
      return locations[i];
    }
  }
} 

Location *currentLocationPointer() {
  size_t els = sizeof(locations)/sizeof(locations[0]);
  for(int i = 0; i < els; ++i) {
    if(strMatch(locations[i].name, currentLocationName)) {
      return &locations[i];
    }
  }
} 

Item getItem(char * itemName) {
  size_t els = sizeof(items)/sizeof(items[0]);
  for(int i = 0; i < els; ++i) {
    if(strMatch(items[i].name, itemName)) {
      return items[i];
    }
  }
} 

Item *getItemPointer(char * itemName) {
  size_t els = sizeof(items)/sizeof(items[0]);
  for(int i = 0; i < els; ++i) {
    if(strMatch(items[i].name, itemName)) {
      return &items[i];
    }
  }
} 

void movec(char * direction) {
  if(strMatch(direction, "north")) {
    if(strMatch(currentLocation().northDestination, "None")) {
      addToPrintBuffer("You cannot.");
    } else {
      strcpy(currentLocationName, currentLocation().northDestination);
    }
  }
  if(strMatch(direction, "east")) {
    if(strMatch(currentLocation().eastDestination, "None")) {
      addToPrintBuffer("You cannot.");
    } else {
      strcpy(currentLocationName, currentLocation().eastDestination);
    }
  }
  if(strMatch(direction, "south")) {
    if(strMatch(currentLocation().southDestination, "None")) {
      addToPrintBuffer("You cannot.");
    } else {
      strcpy(currentLocationName, currentLocation().southDestination);
    }
  }
  if(strMatch(direction, "west")) {
    if(strMatch(currentLocation().westDestination, "None")) {
      addToPrintBuffer("You cannot.");
    } else {
      strcpy(currentLocationName, currentLocation().westDestination);
    }
  }
}

void obtainItem(char * itemName, int obtainability) {
  int a;
  for(a = 0; a < sizeof(inventory) / sizeof(inventory[0]); a++) {
    if(strMatch(inventory[a], "")) {
      strcpy(inventory[a], itemName);
      break;
    }
  }

  if(obtainability != 2) {
    deleteItem(itemName);
  }

  addToPrintBuffer("Added to inventory.");
}

void dropItem(char * itemName) {
  Location *ptr_location;  
  ptr_location = currentLocationPointer();
  int a;
  for(a = 0; a < sizeof(currentLocation().items) / sizeof(currentLocation().items[0]); a++) {
    if(strMatch(currentLocation().items[a], "")) {
      strcpy(ptr_location->items[a], itemName);
      break;
    }
  }

  int b;
  for(b = 0; b < sizeof(inventory) / sizeof(inventory[0]); b++) {
    if(strMatch(inventory[b], itemName)) {
      strcpy(inventory[b], "");
    }
  }

  addToPrintBuffer("Removed from inventory.");
}

void deleteItem(char * itemName) {
  Location *ptr_location;  
  ptr_location = currentLocationPointer();
  int i;
  for(i = 0; i < sizeof(currentLocation().items) / sizeof(currentLocation().items[0]); i++) {
    if(strMatch(currentLocation().items[i], itemName)) {
      strcpy(ptr_location->items[i], "");
    }
  }
}

void action(char * command) {
  if (strMatch(command, "n") || strContain(command, "north")) {
    movec("north");
  } else if (strMatch(command, "e") || strContain(command, "east")) {
    movec("east");
  } else if (strMatch(command, "s") || strContain(command, "south")) {
    movec("south");
  } else if (strMatch(command, "w") || strContain(command, "west")) {
    movec("west");
  } else if (strMatch(command, "h") || strContain(command, "help")) {
    addToPrintBuffer("Welcome to coconut island. Travel is limited to cardinal directions, N, S, E, W.");
  } else if (strContain(command, "look")) {
    int a;
    int b;
    for (a = 0; a < sizeof(currentLocation().items) / sizeof(currentLocation().items[0]); a++) {
      char currentItem[200]; 
      strcpy(currentItem, currentLocation().items[a]);
      toLower(currentItem);
      if(strContain(command, currentItem)) {
        for (b = 0; b < sizeof(items) / sizeof(items[0]); b++) {
          if(strMatch(currentLocation().items[a], items[b].name) && !strMatch(currentLocation().items[a], "")) {
            addToPrintBuffer(items[b].visualDescription);
            return;
          } 
        }
      }
    }
    for (a = 0; a < sizeof(inventory) / sizeof(inventory[0]); a++) {
      char currentItem[200]; 
      strcpy(currentItem, inventory[a]);
      toLower(currentItem);
      if(strContain(command, currentItem)) {
        for (b = 0; b < sizeof(items) / sizeof(items[0]); b++) {
          if(strMatch(inventory[a], items[b].name) && !strMatch(inventory[a], "")) {
            addToPrintBuffer(items[b].visualDescription);
            return;
          } 
        }
      }
    }
  } else if (strContain(command, "get") || strContain(command, "take") || strContain(command, "pick")) {
    int a;
    int b;
    for (a = 0; a < sizeof(currentLocation().items) / sizeof(currentLocation().items[0]); a++) {
      char currentItem[200]; 
      strcpy(currentItem, currentLocation().items[a]);
      toLower(currentItem);
      if(strContain(command, currentItem)) {
        for (b = 0; b < sizeof(items) / sizeof(items[0]); b++) {
          if(strMatch(currentLocation().items[a], items[b].name) && !strMatch(currentLocation().items[a], "") && items[b].obtainable > 0) {
            obtainItem(items[b].name, items[b].obtainable);
          } 
        }
      }
    }
  } else if (strContain(command, "drop") || strContain(command, "leave")) {
    int a;
    int b;
    for (a = 0; a < sizeof(inventory) / sizeof(inventory[0]); a++) {
      char currentItem[200]; 
      strcpy(currentItem, inventory[a]);
      toLower(currentItem);
      if(strContain(command, currentItem)) {
        for (b = 0; b < sizeof(items) / sizeof(items[0]); b++) {
          if(strMatch(inventory[a], items[b].name) && !strMatch(inventory[a], "")) {
            dropItem(items[b].name);
          } 
        }
      }
    }
  } else if (
      strMatch(currentLocation().name, "Ricken's Door") && 
      !getItem("Door").open && 
      (strContain(command, "knock") || strContain(command, "rap") || strContain(command, "tap"))
    ){
    addToPrintBuffer("You rap on Ricken's door twelve times before he opens it and bids you come in.");
    Item *ptr_door;  
    ptr_door = getItemPointer("Door");
    strcpy(ptr_door->locationDescription, "The door to Ricken's Hovel is open.");
    ptr_door->open = true; 
    Location *ptr_location;  
    ptr_location = currentLocationPointer();
    strcpy(ptr_location->eastDestination, "Ricken's Hovel");
    strcpy(ptr_location->eastAccess, "Open");
  } else if (strMatch(currentLocation().name, "Ricken's Hovel") && strContain(command, "talk")) {
    addToPrintBuffer("\"Take me with you,\" you plead. The storm bursts the window and sheets of rain crash on your faces. Ricken's voice is plodding. \"Boat holds four.\" \"Leave the others,\" you stammer, \"Just take me. I'm a doctor. Who knows how long it'll be until you get picked up?\" Ricken's face doesn't change. He says, \"Show it to me.\"");
  } else if (
      strMatch(currentLocation().name, "Ricken's Hovel") &&
      strContain(command, "gold") && 
      (strContain(command, "give") || strContain(command, "hand") || strContain(command, "show") || strContain(command, "ricken"))
    ){
    addToPrintBuffer("You stare at eachother. Your body shakes. The place is coming down around you. You start to pull the gold bar from your pocket. The orange light from the fire gleams against the trident emblem stamped into the side of the bar. When Ricken sees it he pushes the bar back into your pocket and retrieves two rifles from a case over the mantle. He hands you one of them then walks out to the docks.");
    obtainItem("Rifle", 1);
    deleteItem("Ricken");
  } else {
    addToPrintBuffer("You Cannot.");
  }
}

void printLocalItems() {
  int a;
  int b;
  for (a = 0; a < sizeof(currentLocation().items) / sizeof(currentLocation().items[0]); a++) {
    for (b = 0; b < sizeof(items) / sizeof(items[0]); b++) {
      if(strMatch(currentLocation().items[a], items[b].name)) {
        addToPrintBuffer(items[b].locationDescription);
      }
    }
  }
}
