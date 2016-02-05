#include "commandscollection.h"
#include <iostream>
#include <QString>
#include "commands/draw.h"
#include "commands/skip.h"
#include "commands/background.h"
#include "commands/table.h"

CommandsCollection::CommandsCollection(){
	registr(new CommandDraw());
	registr(new CommandSkip());
	registr(new CommandBackground());
	registr(new CommandTable());
};

bool CommandsCollection::contains(QString name){
	return m_mapCommands.contains(name);
};

ICommand *CommandsCollection::create(QString name){
	if(m_mapCommands.contains(name)){
		return m_mapCommands[name]->create();
	}
	return NULL;
};

bool CommandsCollection::isMultiLine(QString name){
	if(m_mapCommands.contains(name)){
		return m_mapCommands[name]->isMultiLine();
	}
	return false;
};

void CommandsCollection::registr(ICommand* pCommand){
	m_mapCommands[pCommand->name()] = pCommand;
};


