void action(char * command) {
  if ((strMatch(command, "n") || strContain(command, "north")) && !strMatch(currentLocation().northAccess, "None")) {
    movec("north");
  } else if ((strMatch(command, "e") || strContain(command, "east")) && !strMatch(currentLocation().eastAccess, "None")) {
    movec("east");
  } else if ((strMatch(command, "s") || strContain(command, "south")) && !strMatch(currentLocation().southAccess, "None")) {
    movec("south");
  } else if ((strMatch(command, "w") || strContain(command, "west")) && !strMatch(currentLocation().westAccess, "None")) {
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
    setItemProperty("Door", "locationDescription", "The door to Ricken's Hovel is open.");
    setItemProperty("Door", "open", "true");
    setLocationProperty("Ricken's Door", "eastAccess", "Open");
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
    setLocationProperty("Ricken's Door", "description", "You stand in front of Ricken's door. It's east of you. His home is a dilapidated shack in a row of dilapidated shacks that line the waterfront. North of you is the docks. Ricken has cleared a path through to the boats. The cobblestone is slippery under your boots");
    setLocationProperty("Ricken's Door", "northAccess", "Open");

  } else {
    addToPrintBuffer("You Cannot.");
  }
}
