#include "stdsneezy.h"
#include "obj_cookware.h"
#include "task_cook.h"
#include "obj_pool.h"
#include "obj_corpse.h"
#include "obj_food.h"


bool check_ingredients(TCookware *pot, int recipe){
  int found=0;
  TThing *t;
  TPool *pool;
  TCorpse *corpse;
  TObj *obj;

  // check basic ingredients
  for(int i=0;ingredients[i].recipe>=0;++i){
    if(ingredients[i].recipe!=recipe)
      continue;
    
    // look for this ingredient
    found=0;
    for(t=pot->getStuff();t;t=t->nextThing){
      switch(ingredients[i].type){
	case TYPE_VNUM:
	  if(obj_index[t->number].virt==ingredients[i].num)
	    found++;
	  break;
	case TYPE_LIQUID:
	  if((pool=dynamic_cast<TPool *>(t)) &&
	     pool->getDrinkType() == ingredients[i].num)
	      found += pool->getDrinkUnits();
	  break;
	case TYPE_MATERIAL:
	  if(t->getMaterial() == ingredients[i].num)
	    found++;
	  break;
	case TYPE_CORPSE:
	  if((corpse=dynamic_cast<TCorpse *>(t)) &&
	     corpse->getCorpseRace() == ingredients[i].num)
	    found++;
	  break;
	case TYPE_ITEM:
	  if((obj=dynamic_cast<TObj *>(t)) &&
	     obj->itemType() == ingredients[i].num)
	    found++;
	  break;
      }
    }

    if(found < ingredients[i].amt){
      return false;
    }
  }

  return true;
}



TCookware *find_pot(TBeing *ch, const char *cookware){
  TThing *tpot=NULL;
  TCookware *pot=NULL;
  int count=0;

  if((tpot=searchLinkedListVis(ch, cookware, ch->getStuff(), &count))){
    pot=dynamic_cast<TCookware *>(tpot);
  }

  return pot;
}

int find_recipe(sstring recipearg){
  int recipe=-1;

  // find which recipe
  for(int i=0;recipes[i].recipe>=0;++i){
    if(isname(recipearg, recipes[i].keywords))
      recipe=recipes[i].recipe;
  }
  
  return recipe;
}

void TBeing::doCook(sstring arg)
{
  int recipe=-1;
  TCookware *pot=NULL;
  sstring cookware, recipearg, tmparg=arg;

  tmparg=one_argument(tmparg, cookware);
  tmparg=one_argument(tmparg, recipearg);

  if(!(pot=find_pot(this, cookware.c_str()))){
    sendTo("You need to specify a piece of cookware to use.\n\r");
    return;
  }

  if((recipe=find_recipe(recipearg))==-1){
    sendTo("You need to specify a recipe.\n\r");
    return;
  }

  //  if(isImmortal())
  //    show_recipe(this, recipe);

  // check ingredients
  if(!check_ingredients(pot, recipe)){
    sendTo("You seem to be missing an ingredient.\n\r");
    return;
  }


  // delete the ingredients and then place the finished product in the pot
  // if the cooking fails we delete the finished product later
  TThing *t2, *t=pot->getStuff();
  while(t){
    t2=t->nextThing;
    delete t;
    t=t2;
  }
  TObj *o;
  if((o=read_object(recipes[recipe].vnum, VIRTUAL)))
    *pot+=*o;
  else {
    sendTo("Error loading food, alert an admin.\n\r");
    return;
  }
    

  sendTo(COLOR_BASIC, fmt("You begin to cook %s.\n\r") % recipes[recipe].name);
  start_task(this, pot, NULL, TASK_COOK, "", 2, inRoom(), 0, 0, 5);
}


int task_cook(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *pot)
{
  // basic tasky safechecking
  if (ch->isLinkdead() || (ch->in_room != ch->task->wasInRoom) || !pot){
    act("You stop cooking.",
        FALSE, ch, 0, 0, TO_CHAR);
    act("$n stops cooking.",
        TRUE, ch, 0, 0, TO_ROOM);
    ch->stopTask();

    if(pot)
      delete pot->getStuff();

    return FALSE; // returning FALSE lets command be interpreted
  }

  if (ch->utilityTaskCommand(cmd) ||
      ch->nobrainerTaskCommand(cmd)){
    return FALSE;
  }


  if (ch->task->timeLeft < 0){
    act("You finish cooking.",
	FALSE, ch, pot, 0, TO_CHAR);
    act("$n finishes cooking.",
	TRUE, ch, pot, 0, TO_ROOM);
    ch->stopTask();
    
    return FALSE;
  }

  switch (cmd) {
    case CMD_TASK_CONTINUE:
      ch->task->calcNextUpdate(pulse, PULSE_MOBACT * 3);

      switch (ch->task->timeLeft) {
	case 2:
          act("You prepare the ingredients in $p.",
              FALSE, ch, pot, 0, TO_CHAR);
          act("$n prepares $s ingredients.",
              TRUE, ch, pot, 0, TO_ROOM);
          ch->task->timeLeft--;
          break;
	case 1:
          act("You cook the ingredients in $p.",
              FALSE, ch, pot, 0, TO_CHAR);
          act("$n cooks the ingredients in $p.",
              TRUE, ch, pot, 0, TO_ROOM);
          ch->task->timeLeft--;

          break;
	case 0:
	  act("You continue cooking the ingredients in $p.",
              FALSE, ch, pot, 0, TO_CHAR);
	  act("$n continues cooking.",
	      TRUE, ch, pot, 0, TO_ROOM);
	  ch->task->timeLeft--;
	  break;
      }
      break;
    case CMD_ABORT:
    case CMD_STOP:
      act("You stop cooking.",
          FALSE, ch, 0, 0, TO_CHAR);
      act("$n stops cooking.",
          TRUE, ch, 0, 0, TO_ROOM);
      ch->stopTask();

      delete pot->getStuff();

      break;
    case CMD_TASK_FIGHTING:
      ch->sendTo("You can't properly cook while under attack.\n\r");
      ch->stopTask();
      delete pot->getStuff();
      break;
  default:
      if (cmd < MAX_CMD_LIST)
        warn_busy(ch);
      delete pot->getStuff();
      break;                    // eat the command
  }
  return TRUE;


}

