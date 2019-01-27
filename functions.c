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

  if(!strMatch(currentLocation().firstVisitText, ""), currentLocation().visited == false) {
    addToPrintBuffer(currentLocation().firstVisitText);
  }

  Location *ptr_location;  
  ptr_location = currentLocationPointer();
  ptr_location->visited = true;
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

void setStats() {
  mobility = 10;

  temperature = currentLocation().temperature;
  if(day) {
    temperature += 2;
  } else {
    temperature -= 2;
  }

  if(blood < 10 && hunger > 2 && min == 0) {
    blood += 1;
  }

  if(stamina < 10 && hunger > 2 && min == 0) {
    stamina += 1;
  }

  if(hunger > 0 && turns % 10 == 0) {
    hunger -= 1;
  }

  if(thirst > 0 && turns % 5 == 0) {
    thirst -= 1;
  }

	if(thirst<1) {
		blood-=2;
	}

	if(hunger<1) {
		blood-=1;
	}

	if(stamina<5) {
		mobility -=4;
	}

  if(temperature < 4) {
    if(hunger > 0 && turns % 7 == 0) {
      hunger -= 1;
    }
		if(!checkStatus("Cold")) {
			addStatus("Cold");
		}
  }

  if(temperature > 3) {
		if(checkStatus("Cold")) {
			removeStatus("Cold");
		}
  }

	if(temperature <= 1) {
		blood -= 1;
		if(!checkStatus("Freezing")) {
			addStatus("Freezing");
		}
		if(checkStatus("Cold")) {
			removeStatus("Cold");
		}
	}
        
	if(temperature > 1) {
		if(checkStatus("Freezeing")) {
			removeStatus("Freezing");
		}
	}
          
	if(temperature > 7) {
		thirst -= 1;
		if(!checkStatus("Hot")) {
			addStatus("Hot");
		}
	}

	if(temperature <= 7) {
		if(checkStatus("Hot")) {
			removeStatus("Hot");
		}
	}
          
          
	if(temperature >= 10) {
		blood-=2;
		if(!checkStatus("Burning")) {
			addStatus("Burning");
		}
		if(checkStatus("Hot")) {
			removeStatus("Hot");
		}
	}
            
	if(temperature < 10) {
		if(checkStatus("Burning")) {
			removeStatus("Burning");
		}
	}
            
	if(thirst < 3) {
		stamina -= 1;
		if(!checkStatus("Thirsty")) {
			addStatus("Thirsty");
		}
	}
            
	if(thirst >= 3) {
		if(checkStatus("Thirsty")) {
			removeStatus("Thirsty");
		}
	}
            
	if(hunger < 3) {
		stamina -= 1;
		if(!checkStatus("Hungry")) {
			addStatus("Hungry");
		}
	}
            
	if(hunger >= 3) {
		if(checkStatus("Hungry")) {
			removeStatus("Hungry");
		}
	}
            
	if(checkStatus("Laceration")) {
		if(blood > 5) {
			blood = 5;
		}
		if(mobility > 5) {
			mobility = 5;
		}
	}

	if(checkStatus("Broken Bone")) {
		if(mobility > 3) {
			mobility -= 7;
		}
	}

	if(blood<0) {
			blood=0;
  }
	if(blood ==0) {
			dead();
  }
	if(blood>10) {
			blood=10;
  }
	if(stamina<0) {
			stamina=0;
  }
	if(stamina>10) {
			stamina=10;
  }
	if(mobility < 0) {
			mobility = 0;
  }
	if(temperature<0) {
			temperature=0;
  }
	if(temperature>10) {
			temperature=10;
  }
	if(thirst<0) {
			thirst=0;
  }
	if(thirst>10) {
			thirst=10;
  }
	if(hunger<0) {
			hunger=0;
  }
	if(hunger>10) {
			hunger=10;
  }

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
		} else if(strMatch(status[a], "")) {
			return false;
		}
  }
}

void dead() {
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
