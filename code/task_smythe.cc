//////////////////////////////////////////////////////////////////////////
//
// SneezyMUD - All rights reserved, SneezyMUD Coding Team
//
// $Log: task_smythe.cc,v $
// Revision 5.13  2002/07/04 19:38:48  dash
// repair cost changes, reenabled wearntear, lengthened repai times
//
// Revision 5.12  2002/07/04 18:34:11  dash
// added new repair skills
//
// Revision 5.11  2002/06/13 23:06:40  peel
// fixed another bug in object finding
// probably needs to be redone
//
// Revision 5.10  2002/06/13 05:38:53  peel
// fixed up smything a bit
//
// Revision 5.9  2002/06/13 04:39:20  peel
// depreciation code was buggy, so I just removed it
// probably ok for players to repair to brand new anyway, gies them an
// advantage over repair shop
//
// Revision 5.8  2002/03/14 15:43:13  jesus
// *** empty log message ***
//
// Revision 5.7  2002/03/14 15:30:38  jesus
// *** empty log message ***
//
// Revision 5.6  2002/03/14 15:22:37  jesus
// made move drain skill dependant
//
// Revision 5.5  2002/01/10 00:45:49  peel
// more splitting up of obj2.h
//
// Revision 5.4  2001/09/25 12:44:43  jesus
// smythe fix
//
// Revision 5.3  2001/09/07 07:07:35  peel
// changed TThing->stuff to getStuff() and setStuff()
//
// Revision 5.2  2001/07/23 00:33:30  jesus
// added goofers dust
//
// Revision 5.1.1.4  2000/12/21 20:15:35  jesus
// *** empty log message ***
//
// Revision 5.1.1.3  2000/11/19 22:20:48  jesus
// smythe update
//
// Revision 5.1.1.2  2000/11/19 13:44:19  jesus
// smythe fixed
//
// Revision 5.1.1.1  1999/10/16 04:32:20  batopr
// new branch
//
// Revision 5.1  1999/10/16 04:31:17  batopr
// new branch
//
// Revision 1.1  1999/09/12 17:24:04  sneezy
// Initial revision
//
//
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
//
//      SneezyMUD 4.0 - All rights reserved, SneezyMUD Coding Team
//      "task.cc" - All functions related to tasks that keep mobs/PCs busy
//
//////////////////////////////////////////////////////////////////////////

#include "stdsneezy.h"
#include "obj_tool.h"

void TTool::findSmytheTools(TTool **forge, TTool **anvil)
{
  if (!*forge && getToolType() == TOOL_FORGE)
    *forge = this;
  else if (!*anvil && getToolType() == TOOL_ANVIL)
    *anvil = this;
}

int smythe_tools_in_room(int room, TTool **forge, TTool **anvil)
{
  TRoom *rp;
  TThing *t;

  if (!(rp = real_roomp(room)))
    return FALSE;

  for (t = rp->getStuff(); t; t = t->nextThing) {
    t->findSmytheTools(forge, anvil);
  }
  return (*forge && *anvil);
}

int TBeing::get_metal_tools(TTool **forge, TTool **anvil, TTool **hammer, TTool **tongs)
{
  TRoom *rp;
  TThing *t;
  TTool *tt;
  if (!(rp = real_roomp(in_room)))
    return FALSE;
  for (t = rp->getStuff(); t; t = t->nextThing) {
    if ((tt = dynamic_cast<TTool *>(t))) {
      if (!*forge && tt->getToolType() == TOOL_FORGE)
	*forge = tt;
      else if (!*anvil && tt->getToolType() == TOOL_ANVIL)
	*anvil = tt;
    }
  }
  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*hammer && tt->getToolType() == TOOL_HAMMER)
      *hammer = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*tongs && tt->getToolType() == TOOL_TONGS)
      *tongs = tt;
  }

  return (*forge && *anvil && *hammer && *tongs);
}

int TBeing::get_wood_tools(TTool **ladel, TTool **soil)
{
  TTool *tt;

  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*ladel && tt->getToolType() == TOOL_LADEL)
      *ladel = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*soil && tt->getToolType() == TOOL_SOIL)
      *soil = tt;
  }

  return (*ladel && *soil);
}

int TBeing::get_shell_tools(TTool **ladel, TTool **oils)
{

  TTool *tt;

  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*ladel && tt->getToolType() == TOOL_LADEL)
      *ladel = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*oils && tt->getToolType() == TOOL_PLANT_OIL)
      *oils = tt;
  }

  return (*ladel && *oils);
}

int TBeing::get_magic_tools(TTool **pentagram, TTool **runes, TTool **energy)
{
  TRoom *rp;
  TThing *t;
  TTool *tt;
  if (!(rp = real_roomp(in_room)))
    return FALSE;
  for (t = rp->getStuff(); t; t = t->nextThing) {
    if ((tt = dynamic_cast<TTool *>(t))) {
      if (!*pentagram && tt->getToolType() == TOOL_PENTAGRAM)
        *pentagram = tt;
    }
  }
  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*runes && tt->getToolType() == TOOL_RUNES)
      *runes = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*energy && tt->getToolType() == TOOL_ENERGY)
      *energy = tt;
  }

  return (*pentagram && *runes && *energy);

}

int TBeing::get_dead_tools(TTool **operatingtable, TTool **scalpel, TTool **forceps)
{
  TRoom *rp;
  TThing *t;
  TTool *tt;
  if (!(rp = real_roomp(in_room)))
    return FALSE;
  for (t = rp->getStuff(); t; t = t->nextThing) {
    if ((tt = dynamic_cast<TTool *>(t))) {
      if (!*operatingtable && tt->getToolType() == TOOL_OPERATING_TABLE)
        *operatingtable = tt;
    }
  }
  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*scalpel && tt->getToolType() == TOOL_SCALPEL)
      *scalpel = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*forceps && tt->getToolType() == TOOL_FORCEPS)
      *forceps = tt;
  }

  return (*operatingtable && *scalpel && *forceps);

}


int TBeing::get_rock_tools(TTool **pentagram, TTool **chisel, TTool **silica)
{

  TRoom *rp;
  TThing *t;
  TTool *tt;
  if (!(rp = real_roomp(in_room)))
    return FALSE;
  for (t = rp->getStuff(); t; t = t->nextThing) {
    if ((tt = dynamic_cast<TTool *>(t))) {
      if (!*pentagram && tt->getToolType() == TOOL_PENTAGRAM)
	*pentagram = tt;
    }
  }
  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*chisel && tt->getToolType() == TOOL_CHISEL)
      *chisel = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*silica && tt->getToolType() == TOOL_SILICA)
      *silica = tt;
  }
  
  return (*pentagram && *silica && *chisel);
}

int TBeing::get_gemmed_tools(TTool **workbench, TTool **loupe, TTool **pliers)
{
  TRoom *rp;
  TThing *t;
  TTool *tt;
  if (!(rp = real_roomp(in_room)))
    return FALSE;
  for (t = rp->getStuff(); t; t = t->nextThing) {
    if ((tt = dynamic_cast<TTool *>(t))) {
      if (!*workbench && tt->getToolType() == TOOL_WORKBENCH)
        *workbench = tt;
    }
  }
  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*loupe && tt->getToolType() == TOOL_LOUPE)
      *loupe = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*pliers && tt->getToolType() == TOOL_PLIERS)
      *pliers = tt;
  }

  return (*workbench && *loupe && *pliers);

}

int TBeing::get_leather_tools(TTool **punch, TTool **cording)
{

  TTool *tt;

  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*punch && tt->getToolType() == TOOL_PUNCH)
      *punch = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*cording && tt->getToolType() == TOOL_CORDING)
      *cording = tt;
  }

  return (*punch && *cording);
}

int TBeing::get_paper_tools(TTool **tape)
{

  TTool *tt;

  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*tape && tt->getToolType() == TOOL_TAPE)
      *tape = tt;
  }

  return (int)(*tape);
}

int TBeing::get_melt_tools(TTool **candle)
{

  TTool *tt;

  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*candle && tt->getToolType() == TOOL_CANDLE)
      *candle = tt;
  }

  return (int)(*candle);

}

int TBeing::get_weave_tools(TTool **needle)
{

  TTool *tt;

  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*needle && tt->getToolType() == TOOL_NEEDLE)
      *needle = tt;
  }

  return (int)(*needle);
}

int TBeing::get_sew_tools(TTool **needle, TTool **thread)
{

  TTool *tt;

  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*needle && tt->getToolType() == TOOL_NEEDLE)
      *needle = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*thread && tt->getToolType() == TOOL_THREAD)
      *thread = tt;
  }

  return (*needle && *thread);
}

int TBeing::get_ceramic_tools(TTool **glue)
{

  TTool *tt;

  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*glue && tt->getToolType() == TOOL_GLUE)
      *glue = tt;
  }

  return (int)(*glue);

}

int TBeing::get_spirit_tools(TTool **altar, TTool **brush, TTool **resin)
{
  TRoom *rp;
  TThing *t;
  TTool *tt;
  if (!(rp = real_roomp(in_room)))
    return FALSE;
  for (t = rp->getStuff(); t; t = t->nextThing) {
    if ((tt = dynamic_cast<TTool *>(t))) {
      if (!*altar && tt->getToolType() == TOOL_ALTAR)
        *altar = tt;
    }
  }
  if ((tt = dynamic_cast<TTool *>(heldInPrimHand()))) {
    if (!*brush && tt->getToolType() == TOOL_BRUSH)
      *brush = tt;
  }
  if ((tt = dynamic_cast<TTool *>(heldInSecHand()))) {
    if (!*resin && tt->getToolType() == TOOL_ASTRAL_RESIN)
      *resin = tt;
  }

  return (*altar && *brush && *resin);

}


void smythe_stop(TBeing *ch)
{
  if (ch->getPosition() < POSITION_SITTING) {
    act("You stop smything, and look about confused.  Are you missing something?",
         FALSE, ch, 0, 0, TO_CHAR);
    act("$n stops smything, and looks about confused and embarrassed.",
        FALSE, ch, 0, 0, TO_ROOM);
  }
  ch->stopTask();
}

void TThing::smythePulse(TBeing *ch, TObj *)
{
  smythe_stop(ch);
}


void TTool::smythePulse(TBeing *ch, TObj *o)
{
  TTool *forge = NULL, *anvil = NULL;
  int percent;
  int movemod = ::number(10,25);
  int movebonus = ::number(1,((ch->getSkillValue(SKILL_SMYTHE) / 10)));
  const int HEATING_TIME = 3;

  // sanity check
  if ((getToolType() != TOOL_HAMMER) ||
      !smythe_tools_in_room(ch->in_room, &forge, &anvil) ||
      (ch->getPosition() < POSITION_RESTING)) {
    smythe_stop(ch);
    return;
  }

  if (movebonus > movemod) {
    movebonus = 5;
  }

  if (ch->getRace() == RACE_DWARF) {
    ch->addToMove(-movemod);
    ch->addToMove(movebonus);
    ch->addToMove(4);
  } else {
    ch->addToMove(-movemod);
    ch->addToMove(movebonus);
  }
  if (ch->getMove() < 10) {
    act("You are much too tired to continue repairing $p.", FALSE, ch, o, this, TO_CHAR);
    act("$n stops repairing, and wipes sweat from $s brow.", FALSE, ch, o, this, TO_ROOM);
    ch->stopTask();
    return;
  }
  if (ch->task->status < HEATING_TIME) {
    if (!ch->task->status) {

    // task can continue forever, so don't bother decrementing 
      act("$n allows $p to heat in $P.", FALSE, ch, o, forge, TO_ROOM);
      act("You allow $p to heat in $P.", FALSE, ch, o, forge, TO_CHAR);
    } else {
      act("$n continues to let $p heat in $P.", FALSE, ch, o, forge, TO_ROOM);
      act("You continue to let $p heat in $P.", FALSE, ch, o, forge, TO_CHAR);
    }
    ch->task->status++;
  } else if (ch->task->status == HEATING_TIME) {
    act("$n removes $p from $P, as it glows red hot.", FALSE, ch, o, forge, TO_ROOM);
    act("You remove $p from $P, as it glows red hot.", FALSE, ch, o, forge, TO_CHAR);
    ch->task->status++;
  } else {
    act("$n pounds $p on an anvil with $s hammer.",
            FALSE, ch, o, 0, TO_ROOM);
    act("You pound $p on an anvil with your hammer.",
            FALSE, ch, o, 0, TO_CHAR);
    addToToolUses(-1);
    if (getToolUses() <= 0) {
      ch->sendTo("Your %s breaks due to overuse.\n\r", fname(name).c_str());
      act("$n looks startled as $e breaks $P while hammering.", FALSE, ch, o, this, TO_ROOM);
      makeScraps();
      ch->stopTask();
      delete this;
      return;
    }
    if (o->getMaxStructPoints() <= o->getStructPoints()) {
      act("$n finishes repairing $p and proudly smiles.", FALSE, ch, o, forge, TO_ROOM);
      act("You finish repairing $p and smile triumphantly.", FALSE, ch, o, forge, TO_CHAR);
      act("You let $p cool down.", FALSE, ch, o, 0, TO_CHAR);
      act("$n lets $p cool down.", FALSE, ch, o, 0, TO_ROOM);
      ch->stopTask();
      return;
    }
    if ((percent = ::number(1, 101)) != 101)    // 101 is complete failure
      percent -= ch->getDexReaction() * 3;

    if (percent < ch->getSkillValue(SKILL_SMYTHE))
      o->addToStructPoints(1);
    else
      o->addToStructPoints(-1);

    if (o->getStructPoints() <= 1) {
      act("$n screws up repairing $p and utterly destroys it.", FALSE, ch, o, forge, TO_ROOM);
      act("You screw up repairing $p and utterly destroy it.", FALSE, ch, o, forge, TO_CHAR);
      makeScraps();
      ch->stopTask();
      delete o;
      return;
    }
    // task can continue forever, so don't bother decrementing the timer
  }
}


// generic smythe: generic metal (150) through steel (176)
// tools: forge (in room), hammer (in primary), tongs? (in secondary)

int task_smythe(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *)
{
  TThing *t;
  TTool *forge = NULL, *anvil = NULL, *hammer = NULL, *tongs = NULL;
  TObj *o = NULL;
  int learning;
  int percent;
  const int HEATING_TIME = 3;
  bool didSucceed = FALSE;

  for(t=ch->getStuff();t;t=t->nextThing){
    if((o=dynamic_cast<TObj *>(t)) && isname(ch->task->orig_arg, o->name))
      break;
    o=NULL;
  }

  // sanity check
  if (ch->isLinkdead() || (ch->in_room < 0) || !o || !isname(ch->task->orig_arg, o->name)) {
    smythe_stop(ch);
    return FALSE;  // returning FALSE lets command be interpreted
  }
  if(ch->utilityTaskCommand(cmd) || ch->nobrainerTaskCommand(cmd))
    return FALSE;

  switch (cmd) {
    case CMD_TASK_CONTINUE:
      if (!ch->get_metal_tools(&forge, &anvil, &hammer, &tongs) || (ch->getPosition() < POSITION_RESTING)) {
	smythe_stop(ch);
	return FALSE;
      }
      learning = ch->getSkillValue(SKILL_SMYTHE);
      didSucceed = bSuccess(ch, learning, SKILL_SMYTHE);
      ch->task->calcNextUpdate(pulse, 2 * PULSE_MOBACT);
      if (ch->task->status && didSucceed || !ch->task->status) {

	if (ch->getRace() == RACE_DWARF) {
	  ch->addToMove(min(-1, ::number(-10,-25) + ::number(1,((ch->getSkillValue(SKILL_SMYTHE) / 10))) + 4));
	} else {
	  ch->addToMove(min(-1, ::number(-10,-25) + ::number(1,((ch->getSkillValue(SKILL_SMYTHE) / 10)))));
	}

	if (ch->getMove() < 10) {
	  act("You are much too tired to continue repairing $p.", FALSE, ch, o, hammer, TO_CHAR);
	  act("$n stops repairing, and wipes sweat from $s brow.", FALSE, ch, o, hammer, TO_ROOM);
	  ch->stopTask();
	  return FALSE;
	}
	if (ch->task->status < HEATING_TIME) {
	  if (!ch->task->status) {
	    act("$n allows $p to heat in $P.", FALSE, ch, o, forge, TO_ROOM);
	    act("You allow $p to heat in $P.", FALSE, ch, o, forge, TO_CHAR);
	  } else {
	    act("$n continues to let $p heat in $P.", FALSE, ch, o, forge, TO_ROOM);
	    act("You continue to let $p heat in $P.", FALSE, ch, o, forge, TO_CHAR);
	  }
	  ch->task->status++;
	} else if (ch->task->status == HEATING_TIME) {
	  act("$n removes $p with $P, as it glows red hot.", FALSE, ch, o, tongs, TO_ROOM);
	  act("You remove $p with $P, as it glows red hot.", FALSE, ch, o, tongs, TO_CHAR);
	  tongs->addToToolUses(-1);
	  if (tongs->getToolUses() <= 0) {
	    act("Your $O break with a loud *snap* as you remove the $o from the flames!", FALSE, ch, o, tongs, TO_CHAR);
	    act("$n's $O break with a loud *snap* as $e removes the $o from the flames!", FALSE, ch, o, tongs, TO_ROOM);
	    tongs->makeScraps();
	    ch->stopTask();
	    delete tongs;
	    return FALSE;
	  }
	  ch->task->status++;
	} else {
	  act("$n pounds $p on an anvil with $s $o.", FALSE, ch, o, hammer, TO_ROOM);
	  act("You pound $p on an anvil with your $o.", FALSE, ch, o, hammer, TO_CHAR);
	  hammer->addToToolUses(-1);
	  if (hammer->getToolUses() <= 0) {
	    act("Your $o breaks due to overuse.", FALSE, ch, o, hammer, TO_CHAR);
	    act("$n looks startled as $e breaks $P while hammering.", FALSE, ch, o, hammer, TO_ROOM);
	    hammer->makeScraps();
	    ch->stopTask();
	    delete hammer;
	    return FALSE;
	  }
	  if (o->getMaxStructPoints() <= o->getStructPoints()) {
	    act("$n finishes repairing $p and proudly smiles.", FALSE, ch, o, forge, TO_ROOM);
	    act("You finish repairing $p and smile triumphantly.", FALSE, ch, o, forge, TO_CHAR);
	    act("You let $p cool down.", FALSE, ch, o, 0, TO_CHAR);
	    act("$n lets $p cool down.", FALSE, ch, o, 0, TO_ROOM);
	    ch->stopTask();
	    return FALSE;
	  }
	  if ((percent = ::number(1, 101)) != 101)    // 101 is complete failure
	    percent -= ch->getDexReaction() * 3;

	  if (percent < ch->getSkillValue(SKILL_SMYTHE))
	    o->addToStructPoints(1);
	  else
	    o->addToStructPoints(-1);

	  if (o->getStructPoints() < 1) {
	    act("$n screws up repairing $p and utterly destroys it.", FALSE, ch, o, forge, TO_ROOM);
	    act("You screw up repairing $p and utterly destroy it.", FALSE, ch, o, forge, TO_CHAR);
	    o->makeScraps();
	    ch->stopTask();
	    delete o;
	    return FALSE;
	  }
	  // task can continue forever, so don't bother decrementing the timer
	}
	
	if (::number(0,1)) {
	  act("$n examines $p carefully.", FALSE, ch, o, 0, TO_ROOM);
	  act("You carefully examine $p.", FALSE, ch, o, 0, TO_CHAR);
	}
	return FALSE;
      }
    case CMD_ABORT:
    case CMD_STOP:
      act("You stop trying to repair $p.", FALSE, ch, o, 0, TO_CHAR);
      ch->sendTo("Isn't there a professional around here somewhere?\n\r");
      act("$n stops repairing $p.", FALSE, ch, o, 0, TO_ROOM);
      if (ch->task->status > 0) {
        act("You let $p cool down.", FALSE, ch, o, 0, TO_CHAR);
        act("$n lets $p cool down.", FALSE, ch, o, 0, TO_ROOM);
      }
      ch->stopTask();
      break;
    case CMD_TASK_FIGHTING:
      ch->sendTo("You are unable to continue repairing while under attack!\n\r");
      ch->stopTask();
      break;
    default:
      if (cmd < MAX_CMD_LIST)
        warn_busy(ch);
      break;                    // eat the command
  }
  return TRUE;
}

// repair body parts: ash/powder (17), flesh (68), ogre hide (76), ivory (107), skull/bone (107), dragonbone (121)
// tools: an operating table (in room), scalpel (primary), forceps (secondary)

int task_repair_dead(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *)
{

  TThing *t;
  TTool *operatingtable = NULL, *scalpel = NULL, *forceps = NULL;
  TObj *o = NULL;
  int learning;
  int percent;
  bool didSucceed = FALSE;

  for(t=ch->getStuff();t;t=t->nextThing){
    if((o=dynamic_cast<TObj *>(t)) && isname(ch->task->orig_arg, o->name))
      break;
    o=NULL;
  }

  // sanity check
  if (ch->isLinkdead() || (ch->in_room < 0) || !o || !isname(ch->task->orig_arg, o->name)) {
    smythe_stop(ch);
    return FALSE;  // returning FALSE lets command be interpreted
  }
  if(ch->utilityTaskCommand(cmd) || ch->nobrainerTaskCommand(cmd))
    return FALSE;
  
  switch (cmd) {
    case CMD_TASK_CONTINUE:
      if (!ch->get_dead_tools(&operatingtable, &scalpel, &forceps) || (ch->getPosition() < POSITION_RESTING)) {
        smythe_stop(ch);
        return FALSE;
      }
      learning = ch->getSkillValue(SKILL_REPAIR_SHAMAN);
      didSucceed = bSuccess(ch, learning, SKILL_REPAIR_SHAMAN);
      ch->task->calcNextUpdate(pulse, 2 * PULSE_MOBACT);
      if (ch->task->status && didSucceed || !ch->task->status) {

 
	ch->addToMove(min(-1, ::number(-10,-15) + ::number(1,((ch->getSkillValue(SKILL_REPAIR_SHAMAN) / 20)))));
        if (ch->getMove() < 10) {
          act("You are much too tired to continue operating on $p.", FALSE, ch, o, 0, TO_CHAR);
          act("$n stops operating on $p, and wipes sweat from $s brow.", FALSE, ch, o, 0, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }
        if (!ch->task->status) {
	  act("$n carefully places $p atop $P.", FALSE, ch, o, operatingtable, TO_ROOM);
	  act("You carefully place $p atop $P.", FALSE, ch, o, operatingtable, TO_CHAR);	  
          ch->task->status++;
        } else if (::number(0,4)) {
	  if (::number(0,1)) {
	    act("$n delicately operates on $p with $P.", FALSE, ch, o, scalpel, TO_ROOM);
	    act("You delicately operate on $p with $P.", FALSE, ch, o, scalpel, TO_CHAR);
	    scalpel->addToToolUses(-1);
	    if (scalpel->getToolUses() <= 0) {
	      act("Your $O snaps in half as your operate on the $o!", FALSE, ch, o, scalpel, TO_CHAR);
	      act("$n's $O snaps in half as $e operates on the $o!", FALSE, ch, o, scalpel, TO_ROOM);
	      scalpel->makeScraps();
	      ch->stopTask();
	      delete scalpel;
	      return FALSE;
	    }
          } else { 
            act("$n removes a damaged piece from $p with $s $O.", FALSE, ch, o, forceps, TO_ROOM);
            act("You remove a damaged piece from $p with your $O.", FALSE, ch, o, forceps, TO_CHAR);
            forceps->addToToolUses(-1);
            if (forceps->getToolUses() <= 0) {
              act("Your $O break with a loud *snap* as you operate on the $o!", FALSE, ch, o, forceps, TO_CHAR);
              act("$n's $O break with a loud *snap* as $e operates on the $o!", FALSE, ch, o, forceps, TO_ROOM);
              forceps->makeScraps();
              ch->stopTask();
              delete forceps;
              return FALSE;
	    }
	  }
          ch->task->status++;
        } else {
          act("$n focuses $s lifeforce, regrowing the damaged part of $p.", FALSE, ch, o, 0, TO_ROOM);
	  act("You focus your lifeforce, regrowing the damaged part of $p.", FALSE, ch, o, 0, TO_CHAR);
	  ch->addToLifeforce(::number(15,30));
	  if (ch->getLifeforce() < 30) {
	    act("You are too low on lifeforce to continue operating on $p.", FALSE, ch, o, 0, TO_CHAR);
	    act("$n looks pale, and stops operating on $p.", FALSE, ch, o, 0, TO_ROOM);
	    ch->stopTask();
	    return FALSE;
	  }
	}
	if (o->getMaxStructPoints() * 85 / 100 <= o->getStructPoints()) {
	  act("$n finishes operating on $p and smiles triumphantly.", FALSE, ch, o, 0, TO_ROOM);
	  act("You finish operating on $p and smile triumphantly.", FALSE, ch, o, 0, TO_CHAR);
	  act("You remove $p from $P.", FALSE, ch, o, operatingtable, TO_CHAR);
	  act("$n removes $p from $P.", FALSE, ch, o, operatingtable, TO_ROOM);
	  ch->stopTask();
	  return FALSE;
	}
	if ((percent = ::number(1, 101)) != 101)    // 101 is complete failure
	  percent -= ch->getDexReaction() * 3;
	
	if (percent < ch->getSkillValue(SKILL_REPAIR_SHAMAN))
	  o->addToStructPoints(1);
	else
	  o->addToStructPoints(-1);
	
	if (o->getStructPoints() < 1) {
	  act("$n screws up operating on $p and utterly destroys it.", FALSE, ch, o, 0, TO_ROOM);
	  act("You screw up the operation on $p and utterly destroy it.", FALSE, ch, o, 0, TO_CHAR);
	  o->makeScraps();
	  ch->stopTask();
	  delete o;
	  return FALSE;
	}
	// task can continue forever, so don't bother decrementing the timer
      }
      
      if (::number(0,1)) {
	act("$n examines $p carefully.", FALSE, ch, o, 0, TO_ROOM);
	act("You carefully examine $p.", FALSE, ch, o, 0, TO_CHAR);
      }
      return FALSE;
      
    case CMD_ABORT:
    case CMD_STOP:
      act("You stop trying to operate on $p.", FALSE, ch, o, 0, TO_CHAR);
      ch->sendTo("Isn't there a professional around here somewhere?\n\r");
      act("$n stops operating on $p.", FALSE, ch, o, 0, TO_ROOM);
      if (ch->task->status > 0) {
	act("You remove $p from $P.", FALSE, ch, o, operatingtable, TO_CHAR);
	act("$n removes $p from $P.", FALSE, ch, o, operatingtable, TO_ROOM);
      }
      ch->stopTask();
      break;
    case CMD_TASK_FIGHTING:
      ch->sendTo("You are unable to continue the operation while under attack!\n\r");
      ch->stopTask();
      break;
    default:
      if (cmd < MAX_CMD_LIST)
        warn_busy(ch);
      break;                    // eat the command
  }
  return TRUE;
}

// repair organic: wood (5), ebony (105) 
// tools: water (room), a ladel (primary), some rich soil (secondary)

// repair organic: coral (14), dragon scale (53), fish scale (75)
// tools: water (room), a ladel (primary), a vial of plant oils (secondary)

int task_repair_organic(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *)
{

  TThing *t;
  TTool *ladel = NULL, *oils = NULL, *soil = NULL;
  TObj *o = NULL;
  int learning;
  int percent;
  bool didSucceed = FALSE;
 

  for(t=ch->getStuff();t;t=t->nextThing){
    if((o=dynamic_cast<TObj *>(t)) && isname(ch->task->orig_arg, o->name))
      break;
    o=NULL;
  }

  // sanity check
  if (ch->isLinkdead() || (ch->in_room < 0) || !o || !isname(ch->task->orig_arg, o->name)) {
    smythe_stop(ch);
    return FALSE;  // returning FALSE lets command be interpreted
  }
  if(ch->utilityTaskCommand(cmd) || ch->nobrainerTaskCommand(cmd))
    return FALSE;

  switch (cmd) {
    case CMD_TASK_CONTINUE:

      if (!ch->get_shell_tools(&ladel, &oils) || (ch->getPosition() < POSITION_RESTING)
	  || !ch->roomp->isWaterSector()) {
	
	smythe_stop(ch);
	return FALSE;
      }
      
      learning = ch->getSkillValue(SKILL_REPAIR_RANGER);
      didSucceed = bSuccess(ch, learning, SKILL_REPAIR_RANGER);
      ch->task->calcNextUpdate(pulse, 2 * PULSE_MOBACT);
      if (ch->task->status && didSucceed || !ch->task->status) {
	
	if (ch->getRace() == RACE_ELVEN) {
	  ch->addToMove(min(-1, ::number(-5,-15) + ::number(1,((ch->getSkillValue(SKILL_REPAIR_RANGER) / 20))) + 2));
	} else {
	  ch->addToMove(min(-1, ::number(-5,-15) + ::number(1,((ch->getSkillValue(SKILL_REPAIR_RANGER) / 20)))));
	}
	if (ch->getMove() < 10) {
	  act("You are much too tired to continue regenerating $p.", FALSE, ch, o, 0, TO_CHAR);
	  act("$n stops regenerating $p, and wipes sweat from $s brow.", FALSE, ch, o, 0, TO_ROOM);
	  ch->stopTask();
	  return FALSE;
	}
	if (ch->getMana() < 10) {
	  act("You are too low on mana to continue regenerating $p.", FALSE, ch, o, 0, TO_CHAR);
	  act("$n looks faint, and stops regenerating $p.", FALSE, ch, o, 0, TO_ROOM);
	  ch->stopTask();
	  return FALSE;
	}

	if (!ch->task->status) {
	  act("$n holds $p under the water for a moment.", FALSE, ch, o, 0, TO_ROOM);
	  act("You hold $p under the water for a moment.", FALSE, ch, o, 0, TO_CHAR);
	  ch->task->status++;
	} else if (ch->task->status == 1) {
	  act("$n removes $p from the water.", FALSE, ch, o, 0, TO_ROOM);
	  act("You remove $p from the water.", FALSE, ch, o, 0, TO_CHAR);
	  ch->task->status++;
	} else if (::number(0,1)) {
	  if (::number(0,1)) {
	    act("$n pours water over $p with $P.", FALSE, ch, o, ladel, TO_ROOM);
	    act("You pour water over $p with $P.", FALSE, ch, o, ladel, TO_CHAR);
	    ladel->addToToolUses(-1);
	    if (ladel->getToolUses() <= 0) {
	      act("Your $O breaks from overuse!", FALSE, ch, o, ladel, TO_CHAR);
	      act("$n's $O breaks from overuse!", FALSE, ch, o, ladel, TO_ROOM);
	      ladel->makeScraps();
	      ch->stopTask();
	      delete ladel;
	      return FALSE;
	    }
	  } else {
	    
	    act("$n drops oil from $P and rubs it across $p.", FALSE, ch, o, oils, TO_ROOM);
	    act("You tkae soild from $P and rub it across $p.", FALSE, ch, o, oils, TO_CHAR);
	    soil->addToToolUses(-1);
	    if (soil->getToolUses() <= 0) {
	      act("Your $P is all used up, and you discard it.", FALSE, ch, o, oils, TO_CHAR);
	      act("$n's $P is all used up, and $e discards it.", FALSE, ch, o, oils, TO_ROOM);
	      
	      ch->stopTask();
	      delete oils;
	      return FALSE;
              
	    }
	  }
	  ch->task->status++;
	} else {
	  act("$n places a hand over $p and concentrates, regenerating it.", FALSE, ch, o, 0, TO_ROOM);
	  act("You place a hand over $p and concentrate, regenerating it.", FALSE, ch, o, 0, TO_CHAR);
	  ch->addToMana(::number(-3,-8));
	  if (ch->getMana() < 10) {
	    act("You are too low on mana to continue regenerating $p.", FALSE, ch, o, 0, TO_CHAR);
	    act("$n looks faint, and stops regenerating $p.", FALSE, ch, o, 0, TO_ROOM);
	    ch->stopTask();
	    return FALSE;
	  }
	}
	
	if (o->getMaxStructPoints() <= o->getStructPoints()) {
	  act("$n finishes regenerating $p and proudly smiles.", FALSE, ch, o, 0, TO_ROOM);
	  act("You finish regenerating $p and smile triumphantly.", FALSE, ch, o, 0, TO_CHAR);
	  act("You dry $p off.", FALSE, ch, o, 0, TO_CHAR);
	  act("$n dries $p off.", FALSE, ch, o, 0, TO_ROOM);
	  ch->stopTask();
	  return FALSE;
	}
	if ((percent = ::number(1, 101)) != 101)    // 101 is complete failure
	  percent -= ch->getDexReaction() * 3;
	
	if (percent < ch->getSkillValue(SKILL_REPAIR_RANGER))
	  o->addToStructPoints(1);
	else
	  o->addToStructPoints(-1);
	
	if (o->getStructPoints() < 1) {
	  act("$n screws up regenerating $p and utterly destroys it.", FALSE, ch, o, 0, TO_ROOM);
	  act("You screw up regenerating $p and utterly destroy it.", FALSE, ch, o, 0, TO_CHAR);
	  o->makeScraps();
	  ch->stopTask();
	  delete o;
	  return FALSE;
	}
	// task can continue forever, so don't bother decrementing the timer
      }
      
      if (::number(0,1)) {
	act("$n examines $p carefully.", FALSE, ch, o, 0, TO_ROOM);
	act("You carefully examine $p.", FALSE, ch, o, 0, TO_CHAR);
      }
      return FALSE;
  
    case CMD_ABORT:
    case CMD_STOP:
      act("You stop trying to regenerate $p.", FALSE, ch, o, 0, TO_CHAR);
      ch->sendTo("Isn't there a druid around here somewhere?\n\r");
      act("$n stops regenerating $p.", FALSE, ch, o, 0, TO_ROOM);
      if (ch->task->status > 0) {
	act("You dry $p off.", FALSE, ch, o, 0, TO_CHAR);
	act("$n dries $p off.", FALSE, ch, o, 0, TO_ROOM);
      }
      ch->stopTask();
      break;
    case CMD_TASK_FIGHTING:
      ch->sendTo("You are unable to continue regenerating while under attack!\n\r");
      ch->stopTask();
      break;
    default:
      if (cmd < MAX_CMD_LIST)
	warn_busy(ch);
      break;                    // eat the command
  }
  return TRUE;
  
  
}

// repair magical: plasma (12), water (57), fire (58), earth (59), elemental (60), ice (61), lightning (62),
//                 chaos (63), runed (102)
// tools: a pentagram (in room), some binding runes (primary), some globules of energy (secondary)

int task_repair_magical(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *)
{
  TThing *t;
  TTool *pentagram = NULL, *runes = NULL, *energy = NULL;
  TObj *o = NULL;
  int learning;
  int percent;
  bool didSucceed = FALSE;


  for(t=ch->getStuff();t;t=t->nextThing){
    if((o=dynamic_cast<TObj *>(t)) && isname(ch->task->orig_arg, o->name))
      break;
    o=NULL;
  }

  // sanity check
  if (ch->isLinkdead() || (ch->in_room < 0) || !o || !isname(ch->task->orig_arg, o->name)) {
    smythe_stop(ch);
    return FALSE;  // returning FALSE lets command be interpreted
  }
  if(ch->utilityTaskCommand(cmd) || ch->nobrainerTaskCommand(cmd))
    return FALSE;

  switch (cmd) {
    case CMD_TASK_CONTINUE:

      if (!ch->get_magic_tools(&pentagram, &runes, &energy) || (ch->getPosition() < POSITION_RESTING)) {

        smythe_stop(ch);
        return FALSE;
      }

      learning = ch->getSkillValue(SKILL_REPAIR_MAGE);
      didSucceed = bSuccess(ch, learning, SKILL_REPAIR_MAGE);
      ch->task->calcNextUpdate(pulse, 2 * PULSE_MOBACT);
      if (ch->task->status && didSucceed || !ch->task->status) {

        if (ch->getRace() == RACE_ELVEN) {
          ch->addToMove(min(-1, ::number(-5,-10) + ::number(1,((ch->getSkillValue(SKILL_REPAIR_MAGE) / 20))) + 2));
        } else {
          ch->addToMove(min(-1, ::number(-5,-10) + ::number(1,((ch->getSkillValue(SKILL_REPAIR_MAGE) / 20)))));
        }
        if (ch->getMove() < 10) {
          act("You are much too tired to continue refocusing the energy in $p.", FALSE, ch, o, 0, TO_CHAR);
          act("$n stops refocusing the energy in $p, and wipes sweat from $s brow.", FALSE, ch, o, 0, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }
	if (ch->getMana() < 10) {
	  act("You are too low on mana to continue refocusing the energy in $p.", FALSE, ch, o, 0, TO_CHAR);
	  act("$n looks faint, and stops refocusing the energy in $p.", FALSE, ch, o, 0, TO_ROOM);
	  ch->stopTask();
	  return FALSE;
	}

        if (!ch->task->status) {
          act("$n concentrates intensly on $p.", FALSE, ch, o, 0, TO_ROOM);
          act("You concentrate intensly on $p.", FALSE, ch, o, 0, TO_CHAR);
          ch->task->status++;
        } else if (ch->task->status == 1) {
          act("$n focuses on the $o, and places it in the center of $P.", FALSE, ch, o, pentagram, TO_ROOM);
          act("You focus on the $o, and place it in the center of $P.", FALSE, ch, o, pentagram, TO_CHAR);
          ch->task->status++;
        } else if (::number(0,1)) {

	  act("$n channels some energy from the $O into $p.", FALSE, ch, o, energy, TO_ROOM);
	  act("You channel some energy from the $O into $p.", FALSE, ch, o, energy, TO_CHAR);
	  energy->addToToolUses(-1);
	  if (energy->getToolUses() <= 0) {
	    act("Your $O are completely used up and dissolve rapidly!", FALSE, ch, o, energy, TO_CHAR);
	    act("$n's $O are completely used up and dissolve rapidly!", FALSE, ch, o, energy, TO_ROOM);
	    ch->stopTask();
	    delete energy;
	    return FALSE;
	    
          }
	  ch->addToMana(::number(-5,-10));

          ch->task->status++;
        } else {
          act("$n places a rune of binding upon the $o, which quickly fades after a moment.", FALSE, ch, o, 0, TO_ROOM);
          act("You place a rune of binding upon the $o, which quickly fades after a moment.", FALSE, ch, o, 0, TO_CHAR);
          runes->addToToolUses(-1);
          if (runes->getToolUses() <= 0) {
            act("Your $O are runes are completely used up.", FALSE, ch, o, runes, TO_CHAR);
            act("$n's $O are runes are completely used up.", FALSE, ch, o, runes, TO_ROOM);
	    ch->stopTask();
            delete runes;
            return FALSE;

          }
          ch->addToMana(::number(-5,-10));
	  ch->task->status++;
        }

        if (o->getMaxStructPoints() <= o->getStructPoints()) {
          act("$n finishes refocusing the energy in $p and proudly smiles.", FALSE, ch, o, 0, TO_ROOM);
          act("You finish refocusing the energy in $p and smile triumphantly.", FALSE, ch, o, 0, TO_CHAR);
          act("You remove $p from $P.", FALSE, ch, o, pentagram, TO_CHAR);
          act("$n removes $p from $P.", FALSE, ch, o, pentagram, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }
        if ((percent = ::number(1, 101)) != 101)    // 101 is complete failure
          percent -= ch->getDexReaction() * 3;

        if (percent < ch->getSkillValue(SKILL_REPAIR_MAGE))
          o->addToStructPoints(1);
        else
          o->addToStructPoints(-1);

        if (o->getStructPoints() < 1) {
          act("$n screws up while refocusing the energy in $p and utterly destroys it.", FALSE, ch, o, 0, TO_ROOM);
          act("You screw up while refocusing the energy in $p and utterly destroy it.", FALSE, ch, o, 0, TO_CHAR);
          o->makeScraps();
          ch->stopTask();
          delete o;
          return FALSE;
        }
        // task can continue forever, so don't bother decrementing the timer
      }

      if (::number(0,1)) {
        act("$n examines $p carefully.", FALSE, ch, o, 0, TO_ROOM);
        act("You carefully examine $p.", FALSE, ch, o, 0, TO_CHAR);
      }
      return FALSE;

    case CMD_ABORT:
    case CMD_STOP:
      act("You stop trying to refocus the energy in $p.", FALSE, ch, o, 0, TO_CHAR);
      ch->sendTo("Isn't there an artificer around here somewhere?\n\r");
      act("$n stops regenerating $p.", FALSE, ch, o, 0, TO_ROOM);
      if (ch->task->status > 0) {
	act("You remove $p from $P.", FALSE, ch, o, pentagram, TO_CHAR);
	act("$n removes $p from $P.", FALSE, ch, o, pentagram, TO_ROOM);
      }
      ch->stopTask();
      break;
    case CMD_TASK_FIGHTING:
      ch->sendTo("You are unable to continue focusing while under attack!\n\r");
      ch->stopTask();
      break;
    default:
      if (cmd < MAX_CMD_LIST)
        warn_busy(ch);
      break;                    // eat the command
  }
  return TRUE;
}

// repair rock: pumice (18), pearl (67), obsidian (108), marble (113), stone (114), jade (116), amber (117),
//              turquoise (118), malchite (122), granite (123), jet (125)
// tools: pentagram (in mountain/cave room), a fine chisel (primary), some powdered silica

int task_repair_rock(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *)
{

  
  TThing *t;
  TTool *pentagram = NULL, *chisel = NULL, *silica = NULL;
  TObj *o = NULL;
  int learning;
  int percent, maxrepair;
  bool didSucceed = FALSE;


  for(t=ch->getStuff();t;t=t->nextThing){
    if((o=dynamic_cast<TObj *>(t)) && isname(ch->task->orig_arg, o->name))
      break;
    o=NULL;
  }

  // sanity check
  if (ch->isLinkdead() || (ch->in_room < 0) || !o || !isname(ch->task->orig_arg, o->name)) {
    smythe_stop(ch);
    return FALSE;  // returning FALSE lets command be interpreted
  }

  spellNumT skill;
  if (ch->getSkillValue(SKILL_REPAIR_MAGE) > ch->getSkillValue(SKILL_REPAIR_RANGER)) {
    skill = SKILL_REPAIR_MAGE;
    maxrepair = 80;
  } else {
    skill = SKILL_REPAIR_RANGER;
    maxrepair = 66;
  }
  if(ch->utilityTaskCommand(cmd) || ch->nobrainerTaskCommand(cmd))
    return FALSE;

  switch (cmd) {
    case CMD_TASK_CONTINUE:

      if (!ch->get_rock_tools(&pentagram, &chisel, &silica) || (ch->getPosition() < POSITION_RESTING)) {

        smythe_stop(ch);
        return FALSE;
      }

      learning = ch->getSkillValue(skill);
      didSucceed = bSuccess(ch, learning, skill);
      ch->task->calcNextUpdate(pulse, 2 * PULSE_MOBACT);
      if (ch->task->status && didSucceed || !ch->task->status) {

       
        ch->addToMove(min(-1, ::number(-10,-15) + ::number(1,((ch->getSkillValue(skill) / 20)))));
        
        if (ch->getMove() < 10) {
          act("You are much too tired to continue reforming the crystals in $p.", FALSE, ch, o, 0, TO_CHAR);
          act("$n stops reforming the crystals in $p, and wipes sweat from $s brow.", FALSE, ch, o, 0, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }
        if (ch->getMana() < 10) {
          act("You are too low on mana to continue reforming the crystals in $p.", FALSE, ch, o, 0, TO_CHAR);
          act("$n looks faint, and stops reforming the crystals in $p.", FALSE, ch, o, 0, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }

        if (!ch->task->status) {
          act("$n concentrates intensly on $p.", FALSE, ch, o, 0, TO_ROOM);
          act("You concentrate intensly on $p.", FALSE, ch, o, 0, TO_CHAR);
          ch->task->status++;
        } else if (ch->task->status == 1) {
          act("$n focuses on the $o, and places it in the center of $P.", FALSE, ch, o, pentagram, TO_ROOM);
          act("You focus on the $o, and place it in the center of $P.", FALSE, ch, o, pentagram, TO_CHAR);
          ch->task->status++;
        } else if (::number(0,1)) {

          act("$n chips some damaged rock away from $p.", FALSE, ch, o, chisel, TO_ROOM);
          act("You chip some damaged rock away from $p.", FALSE, ch, o, chisel, TO_CHAR);
          chisel->addToToolUses(-1);
          if (chisel->getToolUses() <= 0) {
            act("The tip of your $O shatters, rendering the tool useless!", FALSE, ch, o, chisel, TO_CHAR);
            act("The tip of $n's $O shatters, rendering the tool useless!", FALSE, ch, o, chisel, TO_ROOM);
	    chisel->makeScraps();
            ch->stopTask();
            delete chisel;
            return FALSE;
          }

          ch->task->status++;
        } else {
          act("$n sprinkles the $o with $P, reforming the crystal structures.", FALSE, ch, o, silica, TO_ROOM);
          act("You sprinkle the $o with $P, reforming the crystal structures.", FALSE, ch, o, silica, TO_CHAR);
          silica->addToToolUses(-1);
          ch->addToMana(::number(-5,-10));
          if (silica->getToolUses() <= 0) {
            act("Your $P is empty, and you discard it.", FALSE, ch, o, silica, TO_CHAR);
            act("$n's $P is empty, and $e discards it.", FALSE, ch, o, silica, TO_ROOM);
            ch->stopTask();
            delete silica;
            return FALSE;

          }
          ch->task->status++;
        }

        if (o->getMaxStructPoints() * maxrepair / 100 <= o->getStructPoints()) {
          act("$n finishes reforming the crystals in $p and proudly smiles.", FALSE, ch, o, 0, TO_ROOM);
          act("You finish reforming the crystals in $p and smile triumphantly.", FALSE, ch, o, 0, TO_CHAR);
          act("You remove $p from $P.", FALSE, ch, o, pentagram, TO_CHAR);
          act("$n removes $p from $P.", FALSE, ch, o, pentagram, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }
        if ((percent = ::number(1, 101)) != 101)    // 101 is complete failure
          percent -= ch->getDexReaction() * 3;

        if (percent < ch->getSkillValue(skill))
          o->addToStructPoints(1);
        else
          o->addToStructPoints(-1);

        if (o->getStructPoints() < 1) {
          act("$n screws up while reforming the crystals in $p and utterly destroys it.", FALSE, ch, o, 0, TO_ROOM);
          act("You screw up while reforming the crystals in $p and utterly destroy it.", FALSE, ch, o, 0, TO_CHAR);
          o->makeScraps();
          ch->stopTask();
          delete o;
          return FALSE;
        }
        // task can continue forever, so don't bother decrementing the timer
      }

      if (::number(0,1)) {
        act("$n examines $p carefully.", FALSE, ch, o, 0, TO_ROOM);
        act("You carefully examine $p.", FALSE, ch, o, 0, TO_CHAR);
      }
      return FALSE;

    case CMD_ABORT:
    case CMD_STOP:
      act("You stop trying to reforming the crystals in $p.", FALSE, ch, o, 0, TO_CHAR);
      ch->sendTo("Isn't there an geologist around here somewhere?\n\r");
      act("$n stops reforming the crystals in $p.", FALSE, ch, o, 0, TO_ROOM);
      if (ch->task->status > 0) {
        act("You remove $p from $P.", FALSE, ch, o, pentagram, TO_CHAR);
        act("$n removes $p from $P.", FALSE, ch, o, pentagram, TO_ROOM);
      }
      ch->stopTask();
      break;
    case CMD_TASK_FIGHTING:
      ch->sendTo("You are unable to continue focusing while under attack!\n\r");
      ch->stopTask();
      break;
    default:
      if (cmd < MAX_CMD_LIST)
        warn_busy(ch);
      break;                    // eat the command
  }


  return TRUE;
}

// repair gemmed: jeweled (101), crystal (103), diamond (104), emerald (106), onyx (109), opal (110), 
//                ruby (111), sapphire (112), amethyst (119), mica (120), quartz (124), corundum (126)
// tools: a workbench (room), a loupe (primary), a pair of needle nosed pliers (secondary)

int task_smythe_advanced(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *)
{

  TThing *t;
  TTool *workbench = NULL, *loupe = NULL, *pliers = NULL;
  TObj *o = NULL;
  int learning;
  int percent, maxrepair;
  bool didSucceed = FALSE;


  for(t=ch->getStuff();t;t=t->nextThing){
    if((o=dynamic_cast<TObj *>(t)) && isname(ch->task->orig_arg, o->name))
      break;
    o=NULL;
  }

  // sanity check
  if (ch->isLinkdead() || (ch->in_room < 0) || !o || !isname(ch->task->orig_arg, o->name)) {
    smythe_stop(ch);
    return FALSE;  // returning FALSE lets command be interpreted
  }

  spellNumT skill;
  if (ch->getSkillValue(SKILL_REPAIR_THIEF) > ch->getSkillValue(SKILL_SMYTHE_ADVANCED)) {
    skill = SKILL_REPAIR_THIEF;
    maxrepair = 85;
  } else {
    skill = SKILL_SMYTHE_ADVANCED;
    maxrepair = 70;
  }
  if(ch->utilityTaskCommand(cmd) || ch->nobrainerTaskCommand(cmd))
    return FALSE;

  switch (cmd) {
    case CMD_TASK_CONTINUE:

      if (!ch->get_gemmed_tools(&workbench, &loupe, &pliers) || (ch->getPosition() < POSITION_RESTING)) {

        smythe_stop(ch);
        return FALSE;
      }

      learning = ch->getSkillValue(skill);
      didSucceed = bSuccess(ch, learning, skill);
      ch->task->calcNextUpdate(pulse, 2 * PULSE_MOBACT);
      if (ch->task->status && didSucceed || !ch->task->status) {

       
        ch->addToMove(min(-1, ::number(-15,-25) + ::number(1,((ch->getSkillValue(skill) / 10)))));
        
        if (ch->getMove() < 10) {
          act("You are much too tired to continue repairing $p.", FALSE, ch, o, 0, TO_CHAR);
          act("$n stops fixing $p, and wipes sweat from $s brow.", FALSE, ch, o, 0, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }

        if (!ch->task->status) {
          act("$n carefully inspects $p with $s $O.", FALSE, ch, o, loupe, TO_ROOM);
          act("You carefully inspect $p with your $O.", FALSE, ch, o, loupe, TO_CHAR);
          ch->task->status++;
        } else if (ch->task->status == 1) {
          act("$n delicately places the $o on $P.", FALSE, ch, o, workbench, TO_ROOM);
          act("You delicately place the $o on $P.", FALSE, ch, o, workbench, TO_CHAR);
          ch->task->status++;
        } else if (::number(0,1)) {

          act("$n looks intently through $s $O at $p.", FALSE, ch, o, loupe, TO_ROOM);
          act("You look intently through your $O at $p.", FALSE, ch, o, loupe, TO_CHAR);


          ch->task->status++;
        } else {
          act("$n carefully uses $s $O to rearrange the gems in $p.", FALSE, ch, o, pliers, TO_ROOM);
          act("You carefully use your $O to rearrange the gems in $p.", FALSE, ch, o, pliers, TO_CHAR);
          pliers->addToToolUses(-1);
          if (pliers->getToolUses() <= 0) {
            act("Suddenly, $P break and are rendered useless!", FALSE, ch, o, pliers, TO_CHAR);
            act("Suddenly, $P break and are rendered useless!", FALSE, ch, o, pliers, TO_ROOM);
            ch->stopTask();
	    pliers->makeScraps();
            delete pliers;
            return FALSE;

          }
          ch->task->status++;
        }

        if (o->getMaxStructPoints() * maxrepair / 100 <= o->getStructPoints()) {
          act("$n finishes rearranging the gems in $p and proudly smiles.", FALSE, ch, o, 0, TO_ROOM);
          act("You finish rearranging the gems in $p and smile triumphantly.", FALSE, ch, o, 0, TO_CHAR);
          act("You remove $p from $P.", FALSE, ch, o, workbench, TO_CHAR);
          act("$n removes $p from $P.", FALSE, ch, o, workbench, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }
        if ((percent = ::number(1, 101)) != 101)    // 101 is complete failure
          percent -= ch->getDexReaction() * 3;

        if (percent < ch->getSkillValue(skill))
          o->addToStructPoints(1);
        else
          o->addToStructPoints(-1);

        if (o->getStructPoints() < 1) {
          act("$n screws up while rearranging the gems in $p and utterly destroys it.", FALSE, ch, o, 0, TO_ROOM);
          act("You screw up while rearranging the gems in $p and utterly destroy it.", FALSE, ch, o, 0, TO_CHAR);
          o->makeScraps();
          ch->stopTask();
          delete o;
          return FALSE;
        }
        // task can continue forever, so don't bother decrementing the timer
      }

      if (::number(0,1)) {
        act("$n examines $p carefully.", FALSE, ch, o, 0, TO_ROOM);
        act("You carefully examine $p.", FALSE, ch, o, 0, TO_CHAR);
      }
      return FALSE;

    case CMD_ABORT:
    case CMD_STOP:
      act("You stop trying to rearranging the gems in $p.", FALSE, ch, o, 0, TO_CHAR);
      ch->sendTo("Isn't there an jeweler around here somewhere?\n\r");
      act("$n stops rearranging the gems in $p.", FALSE, ch, o, 0, TO_ROOM);
      if (ch->task->status > 0) {
        act("You remove $p from $P.", FALSE, ch, o, workbench, TO_CHAR);
        act("$n removes $p from $P.", FALSE, ch, o, workbench, TO_ROOM);
      }
      ch->stopTask();
      break;
    case CMD_TASK_FIGHTING:
      ch->sendTo("You are unable to continue rearranging the gems while under attack!\n\r");
      ch->stopTask();
      break;
    default:
      if (cmd < MAX_CMD_LIST)
        warn_busy(ch);
      break;                    // eat the command
  }

  return TRUE;

}

// mend hide: laminate (19), leather (51), toughened leather (52), fur (55), feathered (56), cat fur (69),
//            dog fur (70), rabbit fur (71), dwarven leather (73), soft leather (74)
// tools: a leather punch (primary), some leather cording (secondary) 

int task_mend_hide(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *)
{

  TThing *t;
  TTool *punch = NULL, *cording = NULL;
  TObj *o = NULL;
  int learning;
  int percent, maxrepair;
  bool didSucceed = FALSE;


  for(t=ch->getStuff();t;t=t->nextThing){
    if((o=dynamic_cast<TObj *>(t)) && isname(ch->task->orig_arg, o->name))
      break;
    o=NULL;
  }

  // sanity check
  if (ch->isLinkdead() || (ch->in_room < 0) || !o || !isname(ch->task->orig_arg, o->name)) {
    smythe_stop(ch);
    return FALSE;  // returning FALSE lets command be interpreted
  }

  spellNumT skill;
  if (ch->getSkillValue(SKILL_REPAIR_RANGER) > ch->getSkillValue(SKILL_REPAIR_MONK)) {
    skill = SKILL_REPAIR_RANGER;
    maxrepair = 85;
  } else {
    skill = SKILL_REPAIR_MONK;
    maxrepair = 66;
  }
  if(ch->utilityTaskCommand(cmd) || ch->nobrainerTaskCommand(cmd))
    return FALSE;

  switch (cmd) {
    case CMD_TASK_CONTINUE:

      if (!ch->get_leather_tools(&punch, &cording) || (ch->getPosition() < POSITION_RESTING)) {

        smythe_stop(ch);
        return FALSE;
      }

      learning = ch->getSkillValue(skill);
      didSucceed = bSuccess(ch, learning, skill);
      ch->task->calcNextUpdate(pulse, 2 * PULSE_MOBACT);
      if (ch->task->status && didSucceed || !ch->task->status) {

       
        ch->addToMove(min(-1, ::number(-10,-15) + ::number(1,((ch->getSkillValue(skill) / 20)))));
        
        if (ch->getMove() < 10) {
          act("You are much too tired to continue mending $p.", FALSE, ch, o, 0, TO_CHAR);
          act("$n stops mending $p, and wipes sweat from $s brow.", FALSE, ch, o, 0, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }

        if (!ch->task->status) {
          act("$n carefully inspects $p.", FALSE, ch, o, 0, TO_ROOM);
          act("You carefully inspect $p.", FALSE, ch, o, 0, TO_CHAR);
          ch->task->status++;
        } else if (1 == ch->task->status % 2) {

          act("$n makes a few holes around a tear in $p.", FALSE, ch, o, punch, TO_ROOM);
          act("You make a few holes around a tear in $p.", FALSE, ch, o, punch, TO_CHAR);
	  punch->addToToolUses(-1);
          if (punch->getToolUses() <= 0) {
            act("The tip of $P breaks with a *SNAP*, rendered it useless!", FALSE, ch, o, punch, TO_CHAR);
            act("The tip of $P breaks with a *SNAP*, rendered it useless!", FALSE, ch, o, punch, TO_ROOM);
            ch->stopTask();
	    punch->makeScraps();
            delete punch;
            return FALSE;

          }

          ch->task->status++;
        } else {
          act("$n sews up a tear in the $o with $P.", FALSE, ch, o, cording, TO_ROOM);
          act("You sew up a tear in the $o with $P.", FALSE, ch, o, cording, TO_CHAR);
          cording->addToToolUses(-1);
          if (cording->getToolUses() <= 0) {
            act("$P is all used up.", FALSE, ch, o, cording, TO_CHAR);
            act("$P is all used up.", FALSE, ch, o, cording, TO_ROOM);
            ch->stopTask();
            delete cording;
            return FALSE;

          }
          ch->task->status++;
        }

        if (o->getMaxStructPoints() * maxrepair / 100 <= o->getStructPoints()) {
          act("$n finishes mending $p and proudly smiles.", FALSE, ch, o, 0, TO_ROOM);
          act("You finish mending $p and smile triumphantly.", FALSE, ch, o, 0, TO_CHAR);
          ch->stopTask();
          return FALSE;
        }
        if ((percent = ::number(1, 101)) != 101)    // 101 is complete failure
          percent -= ch->getDexReaction() * 3;

        if (percent < ch->getSkillValue(skill))
          o->addToStructPoints(1);
        else
          o->addToStructPoints(-1);

        if (o->getStructPoints() < 1) {
          act("$n screws up while mending $p and utterly destroys it.", FALSE, ch, o, 0, TO_ROOM);
          act("You screw up while mending $p and utterly destroy it.", FALSE, ch, o, 0, TO_CHAR);
          o->makeScraps();
          ch->stopTask();
          delete o;
          return FALSE;
        }
        // task can continue forever, so don't bother decrementing the timer
      }

      if (::number(0,1)) {
        act("$n examines $p carefully.", FALSE, ch, o, 0, TO_ROOM);
        act("You carefully examine $p.", FALSE, ch, o, 0, TO_CHAR);
      }
      return FALSE;

    case CMD_ABORT:
    case CMD_STOP:
      act("You stop trying to mend $p.", FALSE, ch, o, 0, TO_CHAR);
      ch->sendTo("Isn't there an seamstress around here somewhere?\n\r");
      act("$n stops mending $p.", FALSE, ch, o, 0, TO_ROOM);
      ch->stopTask();
      break;
    case CMD_TASK_FIGHTING:
      ch->sendTo("You are unable to continue mending while under attack!\n\r");
      ch->stopTask();
      break;
    default:
      if (cmd < MAX_CMD_LIST)
        warn_busy(ch);
      break;                    // eat the command
  }

  return TRUE;

}

// mend generic: paper (1), cardboard (10)
// tools: tape (primary)
// mend generic: wax (3), plastic (8), rubber (9)
// tools: a candle (primary)
// mend generic: string (11), hair (16), horsehair (15), straw (66)
// tools: a small needle (primary)
// mend generic: cloth (2), silk (6), wool (54), hemp (77)
// tools: a small needle (primary), a spool of thread (secondary)
// mend generic: porcelain (65), clay (64)
// tools: a tube of glue

int task_mend(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *)
{
  return TRUE;
  ch->sendTo("This skill is not yet implemented.\n\r");
  ch->stopTask();
  return TRUE;
}

// repair spiritual: ghostly (72), foodstuff (7)
// tools: an altar (in room), a small brush (primary), some astral resin (secondary) 

int task_repair_spiritual(TBeing *ch, cmdTypeT cmd, const char *, int pulse, TRoom *, TObj *)
{


  TThing *t;
  TTool *altar = NULL, *brush = NULL, *resin = NULL;
  TObj *o = NULL;
  int learning;
  int percent, maxrepair;
  bool didSucceed = FALSE;


  for(t=ch->getStuff();t;t=t->nextThing){
    if((o=dynamic_cast<TObj *>(t)) && isname(ch->task->orig_arg, o->name))
      break;
    o=NULL;
  }

  // sanity check
  if (ch->isLinkdead() || (ch->in_room < 0) || !o || !isname(ch->task->orig_arg, o->name)) {
    smythe_stop(ch);
    return FALSE;  // returning FALSE lets command be interpreted
  }

  spellNumT skill;
  if (ch->getSkillValue(SKILL_REPAIR_CLERIC) > ch->getSkillValue(SKILL_REPAIR_DEIKHAN)) {
    skill = SKILL_REPAIR_CLERIC;
    maxrepair = 85;
  } else {
    skill = SKILL_REPAIR_DEIKHAN;
    maxrepair = 66;
  }
  if(ch->utilityTaskCommand(cmd) || ch->nobrainerTaskCommand(cmd))
    return FALSE;

  switch (cmd) {
    case CMD_TASK_CONTINUE:

      if (!ch->get_spirit_tools(&altar, &brush, &resin) || (ch->getPosition() < POSITION_RESTING)) {

        smythe_stop(ch);
        return FALSE;
      }

      learning = ch->getSkillValue(skill);
      didSucceed = bSuccess(ch, learning, skill);
      ch->task->calcNextUpdate(pulse, 2 * PULSE_MOBACT);
      if (ch->task->status && didSucceed || !ch->task->status) {

       
        ch->addToMove(min(-1, ::number(-10,-15) + ::number(1,((ch->getSkillValue(skill) / 20)))));
        
        if (ch->getMove() < 10) {
          act("You are much too tired to continue mending $p.", FALSE, ch, o, 0, TO_CHAR);
          act("$n stops mending $p, and wipes sweat from $s brow.", FALSE, ch, o, 0, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }

	if (ch->getPiety() < 10) {
          act("You are much too drained to continue mending $p.", FALSE, ch, o, 0, TO_CHAR);
          act("$n looks faint, and stops mending $p.", FALSE, ch, o, 0, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }

 
        if (!ch->task->status) {
          act("$n carefully inspects $p.", FALSE, ch, o, 0, TO_ROOM);
          act("You carefully inspect $p.", FALSE, ch, o, 0, TO_CHAR);
          ch->task->status++;
        } else if (ch->task->status == 1) {
          act("$n delicately places the $o on $P.", FALSE, ch, o, altar, TO_ROOM);
          act("You delicately place the $o on $P.", FALSE, ch, o, altar, TO_CHAR);
          ch->task->status++;
        } else if (::number(0,1)) {

          act("$n applies some resin to the $o using $s $O.", FALSE, ch, o, brush, TO_ROOM);
          act("You applie some resin to the $o using your $O.", FALSE, ch, o, brush, TO_CHAR);
	  resin->addToToolUses(-1);
          if (resin->getToolUses() <= 0) {
            act("$P is all used up, and you discard it as worthless.", FALSE, ch, o, resin, TO_CHAR);
            act("$P is all used up, and $n discard it as worthless.", FALSE, ch, o, resin, TO_ROOM);
            ch->stopTask();
	    resin->makeScraps();
            delete resin;
            return FALSE;

          }

          ch->task->status++;
        } else {
          act("$n channels the will of $s deity into $p, mending it.", FALSE, ch, o, 0, TO_ROOM);
          act("You channel the will of your deity into $p, mending it.", FALSE, ch, o, 0, TO_CHAR);
          ch->addToPiety(::number(-2, -7));
      
          ch->task->status++;
        }

        if (o->getMaxStructPoints() * maxrepair / 100 <= o->getStructPoints()) {
          act("$n finishes mending $p and proudly smiles.", FALSE, ch, o, 0, TO_ROOM);
          act("You finish mending $p and smile triumphantly.", FALSE, ch, o, 0, TO_CHAR);
          act("You remove $p from $P.", FALSE, ch, o, altar, TO_CHAR);
          act("$n removes $p from $P.", FALSE, ch, o, altar, TO_ROOM);
          ch->stopTask();
          return FALSE;
        }
        if ((percent = ::number(1, 101)) != 101)    // 101 is complete failure
          percent -= ch->getDexReaction() * 3;

        if (percent < ch->getSkillValue(skill))
          o->addToStructPoints(1);
        else
          o->addToStructPoints(-1);

        if (o->getStructPoints() < 1) {
          act("$n screws up while mending $p and utterly destroys it.", FALSE, ch, o, 0, TO_ROOM);
          act("You screw up while mending $p and utterly destroy it.", FALSE, ch, o, 0, TO_CHAR);
          o->makeScraps();
          ch->stopTask();
          delete o;
          return FALSE;
        }
        // task can continue forever, so don't bother decrementing the timer
      }

      if (::number(0,1)) {
        act("$n examines $p carefully.", FALSE, ch, o, 0, TO_ROOM);
        act("You carefully examine $p.", FALSE, ch, o, 0, TO_CHAR);
      }
      return FALSE;

    case CMD_ABORT:
    case CMD_STOP:
      act("You stop trying to mending $p.", FALSE, ch, o, 0, TO_CHAR);
      ch->sendTo("Isn't there an priest around here somewhere?\n\r");
      act("$n stops mending $p.", FALSE, ch, o, 0, TO_ROOM);
      act("You remove $p from $P.", FALSE, ch, o, altar, TO_CHAR);
      act("$n removes $p from $P.", FALSE, ch, o, altar, TO_ROOM);
      ch->stopTask();
      break;
    case CMD_TASK_FIGHTING:
      ch->sendTo("You are unable to continue mending while under attack!\n\r");
      ch->stopTask();
      break;
    default:
      if (cmd < MAX_CMD_LIST)
        warn_busy(ch);
      break;                    // eat the command
  }

  return TRUE;

}

