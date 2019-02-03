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
  int i = 0;
  while (str[i] != ' ' && str[i] != 0 && str[i] != '\n') {
    ++i;
  }
  return i;
}

void formatText(char * s, int maxX) {
  int i = 0;
  int currentLineLength = 0;
  while (s[i] != '\0') {
    if (s[i] == '\n') {
      currentLineLength = 0;
    } else if (s[i] == ' ') {
      if (currentLineLength + wordlen( & s[i + 1]) >= maxX) {
        s[i] = '\n';
        currentLineLength = 0;
      }
    }
    currentLineLength++;
    i++;
  }
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

Location getLocationByName(char * locationName) {
  size_t els = sizeof(locations)/sizeof(locations[0]);
  for(int i = 0; i < els; ++i) {
    if(strMatch(locations[i].name, locationName)) {
      return locations[i];
    }
  }
} 

Location *getLocationByNamePointer(char * locationName) {
  size_t els = sizeof(locations)/sizeof(locations[0]);
  for(int i = 0; i < els; ++i) {
    if(strMatch(locations[i].name, locationName)) {
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
  if(itemInInventory("Map")) {
    map[mapX][mapY] = currentLocation().icon;
  }

  if(strMatch(direction, "north")) {
    if(strMatch(currentLocation().northDestination, "None")) {
      addToPrintBuffer("You cannot.");
    } else {
      strcpy(currentLocationName, currentLocation().northDestination);
			mapY -= 1;
    }
  }
  if(strMatch(direction, "east")) {
    if(strMatch(currentLocation().eastDestination, "None")) {
      addToPrintBuffer("You cannot.");
    } else {
      strcpy(currentLocationName, currentLocation().eastDestination);
			mapX += 1;
    }
  }
  if(strMatch(direction, "south")) {
    if(strMatch(currentLocation().southDestination, "None")) {
      addToPrintBuffer("You cannot.");
    } else {
      strcpy(currentLocationName, currentLocation().southDestination);
			mapY += 1;
    }
  }
  if(strMatch(direction, "west")) {
    if(strMatch(currentLocation().westDestination, "None")) {
      addToPrintBuffer("You cannot.");
    } else {
      strcpy(currentLocationName, currentLocation().westDestination);
			mapX -= 1;
    }
  }

  if(!strMatch(currentLocation().firstVisitText, ""), currentLocation().visited == false) {
    addToPrintBuffer(currentLocation().firstVisitText);
  }

  Location *ptr_location;  
  ptr_location = currentLocationPointer();
  ptr_location->visited = true;

  if(itemInInventory("Map")) {
    map[mapX][mapY] = selfIcon;
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
    deleteLocationItem(itemName);
  }
	if(strMatch(itemName, "Map")) {
    map[mapX][mapY] = "@";
	}
}

void dropItem(char * itemName) {
  Location *ptr_location;  
  ptr_location = currentLocationPointer();
  int a;
  for(a = 0; a < sizeof(currentLocation().items) / sizeof(currentLocation().items[0]); a++) {
    if(strMatch(currentLocation().items[a], "") && getItem(itemName).obtainable != 2) {
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
}

void eatItem(char * itemname) {
  hunger = 10;
  int b;
  for(b = 0; b < sizeof(inventory) / sizeof(inventory[0]); b++) {
    if(strMatch(inventory[b], itemname)) {
      strcpy(inventory[b], "");
    }
  }
}

void drink() {
  thirst = 10;
  int b;
  for(b = 0; b < sizeof(inventory) / sizeof(inventory[0]); b++) {
    if(strMatch(inventory[b], "Water")) {
      strcpy(inventory[b], "");
    }
  }
}

void deleteLocationItem(char * itemName) {
  Location *ptr_location;  
  ptr_location = currentLocationPointer();
  int i;
  for(i = 0; i < sizeof(currentLocation().items) / sizeof(currentLocation().items[0]); i++) {
    if(strMatch(currentLocation().items[i], itemName)) {
      strcpy(ptr_location->items[i], "");
    }
  }
}

void deleteInventoryItem(char * itemName) {
  int b;
  for(b = 0; b < sizeof(inventory) / sizeof(inventory[0]); b++) {
    if(strMatch(inventory[b], itemName)) {
      strcpy(inventory[b], "");
    }
  }
}

bool itemInInventory(char * itemName) {
  int i;
  for(i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
    if(strMatch(inventory[i], itemName)) {
      return true;
    }
  }
  return false;
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

void setLocationProperty(char * locationName, char * property, char * newValue) {
  Location *ptr_location;  
  ptr_location = getLocationByNamePointer(locationName);
  if(strMatch(property, "northAccess")) {
    strcpy(ptr_location->northAccess, newValue);
  } else if (strMatch(property, "eastAccess")) {
    strcpy(ptr_location->eastAccess, newValue);
  } else if (strMatch(property, "southAccess")) {
    strcpy(ptr_location->southAccess, newValue);
  } else if (strMatch(property, "westAccess")) {
    strcpy(ptr_location->westAccess, newValue);
  } else if (strMatch(property, "description")) {
    strcpy(ptr_location->description, newValue);
  }
}

void setItemProperty(char * itemName, char * property, char * newValue) {
  Item *ptr_item;  
  ptr_item = getItemPointer(itemName);
  if(strMatch(property, "locationDescription")) {
    strcpy(ptr_item->locationDescription, "The door to Ricken's Hovel is open.");
  } else if(strMatch(property, "open")) {
    if(strMatch(newValue, "true")) {
      ptr_item->open = true;
    } else if(strMatch(newValue, "false")) {
      ptr_item->open = false;
    }
  }
}

char * makeBar(int stat) {
  char on[1] = " ";
  char *barTemp = malloc(10);
  int i;
  for(i = 0; i < stat; i++) {
    barTemp[i] = *on;
  }
  return barTemp;
}

void addStatus(char * statusName) {
  int a;
  for(a = 0; a < sizeof(status) / sizeof(status[0]); a++) {
    if(strMatch(status[a], "")) {
      strcpy(status[a], statusName);
			break;
    }
  }
}

void removeStatus(char * statusName) {
  int a;
  for(a = 0; a < sizeof(status) / sizeof(status[0]); a++) {
    if(strMatch(status[a], statusName)) {
      strcpy(status[a], "");
			break;
    }
  }
}

bool checkStatus(char * statusName) {
  int a;
  for(a = 0; a < sizeof(status) / sizeof(status[0]); a++) {
		if(strMatch(status[a], statusName)) {
			return true;
		} 
  }
  return false;
}

void die() {
  strcpy(currentLocationName, "Dead");
}

void incrementTime() {
  min+=20;
  if(min == 60) {
    min = 0;
    hour += 1;
    if(hour == 24) {
      hour = 0;
    }
  }
  if(hour < 6 || hour > 20) {
    day = false;
  } else {
    day = true;
  }

  turns += 1;
}
