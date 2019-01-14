typedef struct {
  char name[50];
  char visualDescription[300];
  char locationDescription[300];
  int obtainable;
  bool open;
  bool edible;
} Item;

Item items[10];

Item Door = {
  "Door",
  "A shoddy wooden door.",
  "The door to Ricken's hovel is locked.",
  0,
  false,
  false
};

Item Ricken = {
  "Ricken",
  "Ricken is a seaman if there ever was one. He has wispy silver hair that matches his moustaches. The moustaches, like his eyes and nose, are thin.",
  "Ricken is standing by the fire, drinking.",
  0,
  false
};

Item Rifle = {
  "Rifle",
  "A long, wooden rifle. You don't know enough to say more about it.",
  "",
  1,
  false
};

Item Gold = {
  "Gold Bar", 
  "Solid gold is heavy and this is a lot of it. There is a trident stamped into the side.",
  "There is a gold bar here. A big one.", 
  1, 
  false
};

void buildItems() {
  items[0] = Door;
  items[1] = Ricken;
  items[2] = Rifle;
  items[3] = Gold;
}

    /*
    "Docks":{  
        "Direction":{  
            "North":{  
                "Destination":"None",
                "Access":"None"
            },
            "East":{  
                "Destination":"None",
                "Access":"None"
            },
            "South":{  
                "Destination":"None",
                "Access":"None"
            },
            "West":{  
                "Destination":"None",
                "Access":"None"
            }
        },
        "Description":{  
            "Neutral":"The entire population of the island is at the docks trying to get passage on a boat. One trawler is inundated with flesh and taking on water. Ricken's men are fending them off with spears. Ricken stands at the edge of his boat with his rifle on his hip waiting for you."
        },
        "Items":[  

        ],
        "Icon":"_",
        "Visited":false,
        "First Visit Text":"As the crowd encroahces on his boat, Ricken fires his rifle into the air. The scene goes quiet except for one woman with a baby. She sees you waiver as you board and she pleads for you to take the child. You look away and she pushes it under your arm. You throw your hands up and the kid goes into the drink. She goes onto her knees. Two of the men leap at you.",
        "Temperature":5
    },
    "Unconscious":{  
        "Direction":{  
            "North":{  
                "Destination":"None",
                "Access":"None"
            },
            "East":{  
                "Destination":"None",
                "Access":"None"
            },
            "South":{  
                "Destination":"None",
                "Access":"None"
            },
            "West":{  
                "Destination":"None",
                "Access":"None"
            }
        },
        "Description":{  
            "Neutral":"You are unconscious."
        },
        "Items":[  

        ],
        "Icon":"_",
        "Visited":false,
        "Temperature":5
    },
    "Ocean":{  
        "Direction":{  
            "North":{  
                "Destination":"None",
                "Access":"None"
            },
            "East":{  
                "Destination":"None",
                "Access":"None"
            },
            "South":{  
                "Destination":"Shore",
                "Access":"Shore"
            },
            "West":{  
                "Destination":"None",
                "Access":"None"
            }
        },
        "Description":{  
            "Neutral":"You are on a small boat on a roiling sea. The sky is blotched with dark, gray clouds. It fades into the ocean in all directions save to the south. There you see a sliver of dark between the peaks of the waves."
        },
        "Items":[  

        ],
        "Icon":"\u223F",
        "Visited":false,
        "Temperature":5
    },
    "Shore":{  
        "Direction":{  
            "North":{  
                "Destination":"Ocean",
                "Access":"Water"
            },
            "East":{  
                "Destination":"None",
                "Access":"None"
            },
            "South":{  
                "Destination":"Jungle",
                "Access":"Open"
            },
            "West":{  
                "Destination":"Delta",
                "Access":"Open"
            }
        },
        "Description":{  
            "Neutral":"The sand is gray, as is everything. The sea is north. To the east and west there is more beach. South there is a path into the jungle. A bare, black crag juts out from its center."
        },
        "Items":[  
            {  
                "Name":"Sand",
                "Visual Description":"Fine, gray sand.",
                "Location Description":"There is sand here.",
                "Obtainable":2,
                "Edible":false
            },
            {  
                "Name":"Boat",
                "Visual Description":"It's got room for four crew or some small cargo.",
                "Location Description":"There is a boat here.",
                "Obtainable":0,
                "Edible":false,
                "Holding":[  
                    {  
                        "Name":"Oar",
                        "Visual Description":"A wooden oar that has been worn smooth and shiny from use.",
                        "Location Description":"There is an oar sitting next to you.",
                        "Obtainable":1,
                        "Edible":false
                    },
                    {  
                        "Name":"Paper",
                        "Visual Description":"A blank sheet of paper. It would be perfect for drawing a map on.",
                        "Location Description":"Ther is a rolled up piece of paper here.",
                        "Obtainable":1,
                        "Edible":false
                    },
                    {  
                        "Name":"Pencil",
                        "Visual Description":"A well-used pencil. You will have to be thoughtful and conserve it.",
                        "Location Description":"There is a pencil here.",
                        "Obtainable":1,
                        "Edible":false
                    }
                ]
            }
        ],
        "Icon":"\u2592",
        "Visited":true,
        "Temperature":5
    },
    "Jungle":{  
        "Direction":{  
            "North":{  
                "Destination":"Shore",
                "Access":"Open"
            },
            "East":{  
                "Destination":"None",
                "Access":"None"
            },
            "South":{  
                "Destination":"Cave",
                "Access":"Open"
            },
            "West":{  
                "Destination":"None",
                "Access":"None"
            }
        },
        "Description":{  
            "Neutral":"The air in the jungle is thick. You can only cut a narrow path through. Huge ferns sweep past your legs as you walk. They could be hiding anything. To the south, almost hidden behind a huge, moss covered rock, you find the entrance to the cave. To the east and west there is more jungle. You can hear the ocean to the north."
        },
        "Items":[  
            {  
                "Name":"Coconut",
                "Visual Description":"A round, Harry coconut.",
                "Location Description":"There is a coconut half buried here.",
                "Obtainable":1,
                "Edible":false
            },
            {  
                "Name":"Ferns",
                "Visual Description":"The ferns are oozing a clear, sticky substance.",
                "Location Description":"There are sticky ferns here.",
                "Obtainable":2,
                "Edible":false
            },
            {  
                "Name":"Wood",
                "Visual Description":"A small bit of wood.",
                "Location Description":"There is wood here.",
                "Obtainable":2,
                "Edible":false
            },
            {  
                "Name":"Vines",
                "Visual Description":"Some long, thin vines that curl around the trees here. They are dark green and shine in the sunlight.",
                "Location Description":"There are some vines here.",
                "Obtainable":2,
                "Edible":false
            }
        ],
        "Icon":"J",
        "Visited":false,
        "Temperature":5
    },
    "Cave":{  
        "Direction":{  
            "North":{  
                "Destination":"Jungle",
                "Access":"Open"
            },
            "East":{  
                "Destination":"None",
                "Access":"None"
            },
            "South":{  
                "Destination":"None",
                "Access":"None"
            },
            "West":{  
                "Destination":"None",
                "Access":"None"
            },
            "Hidden":{  
                "Destination":"Chamber",
                "Access":"Open"
            }
        },
        "Description":{  
            "Neutral":"You are in a dark cave. The walls are wet and slick. After your eyes adjust you can see what appears to be a switch set into the wall high above you.",
            "Effected":"Everything around you is on fire. There is a large crack to the north. You can see jungle beyond it. To the south there is a low opening."
        },
        "Items":[  

        ],
        "Icon":"C",
        "Visited":false,
        "Temperature":4
    },
    "Chamber":{  
        "Direction":{  
            "North":{  
                "Destination":"Cave",
                "Access":"Open"
            },
            "East":{  
                "Destination":"None",
                "Access":"None"
            },
            "South":{  
                "Destination":"None",
                "Access":"None"
            },
            "West":{  
                "Destination":"None",
                "Access":"None"
            },
            "Hidden":{  
                "Destination":"None",
                "Access":"None"
            }
        },
        "Description":{  
            "Neutral":"This is a smaller cave. The walls are jagged and shiny.",
            "Effected":""
        },
        "Items":[  
            {  
                "Name":"Flint",
                "Visual Description":"A shiny, smooth stone with sharp edges.",
                "Location Description":"There is flint here.",
                "Obtainable":2,
                "Edible":false
            }
        ],
        "Icon":"F",
        "Visited":false,
        "Temperature":4
    },
    "Delta":{  
        "Direction":{  
            "North":{  
                "Destination":"Ocean",
                "Access":"Water"
            },
            "East":{  
                "Destination":"Shore",
                "Access":"Open"
            },
            "South":{  
                "Destination":"Waterfall",
                "Access":"Climb"
            },
            "West":{  
                "Destination":"None",
                "Access":"None"
            }
        },
        "Description":{  
            "Neutral":"A narrow but deep river meets the sea here. There is some vegetation around the edges, but nothing of any apparent use. To the east is a stretch of beach. North is the ocean. To the south is a high waterfall. It's falling from a cliff. There are hand holds in the cliff, but you have never climbed anything that didn't have rungs."
        },
        "Items":[  
            {  
                "Name":"Water",
                "Visual Description":"The water is clear and looks refreshing.",
                "Location Description":"The water appears clean and drinkable.",
                "Obtainable":2,
                "Edible":false
            },
            {  
                "Name":"Berries",
                "Visual Description":"Small, red berries.",
                "Location Description":"There are some wild berries here.",
                "Obtainable":2,
                "Edible":true
            },
            {  
                "Name":"Cloth",
                "Visual Description":"It appears to be a piece of an old ship mast.",
                "Location Description":"There is some tattered cloth here.",
                "Obtainable":1,
                "Edible":false
            }
        ],
        "Icon":"V",
        "Visited":false,
        "Temperature":5
    },
    "Waterfall":{  
        "Direction":{  
            "North":{  
                "Destination":"Delta",
                "Access":"Climb"
            },
            "East":{  
                "Destination":"None",
                "Access":"None"
            },
            "South":{  
                "Destination":"None",
                "Access":"None"
            },
            "West":{  
                "Destination":"None",
                "Access":"None"
            }
        },
        "Description":{  
            "Neutral":"You stand at the edge of a sheer cliff. It is as high as a three story building. A deep river comes from the South and flows over the cliff. The sound of the falling water is deafening. You might be able to climb down here, but the thought of it make your chest tighten up and your stomach drop."
        },
        "Items":[  
            {  
                "Name":"Water",
                "Visual Description":"The water is clear and looks refreshing.",
                "Location Description":"The water appears clean and drinkable.",
                "Obtainable":2,
                "Edible":false
            }
        ],
        "Icon":"W",
        "Visited":false,
        "Temperature":5
    }
}
*/

