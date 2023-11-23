#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "abstract-syntax-tree.h"
#include "../support/shared.h"

boolean symbolExists(char *identifier);

void insertSymbol(char *identifier, DataTypeType type);

void removeSymbol(char *identifier);

void freeSymbolTable();

int getSymbolType(char *identifier);

#endif
