  if(turn % robotB[i].turn == 0 && robotB[i].alive){
        for(int j = 0; j < n; j++){
            if(robotA[j].alive){
                double dmg = calDmg(robotB[i].atk, robotA[j].def);
                robotA[j].health -= dmg;
                if(robotA[j].health <= 0) robotA[j].alive = false;
                break;
                    }
                }
             }
        }