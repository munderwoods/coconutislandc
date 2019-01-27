void stats() {
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
