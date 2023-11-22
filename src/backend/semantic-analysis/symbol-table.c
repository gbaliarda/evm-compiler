#include <stdlib.h>
#include "./symbol-table.h"
#include "../support/shared.h"

boolean symbolExists(char *identifier) {
    boolean res = false;
    SymbolTableEntry *symbol;

    HASH_FIND_STR(state.symbolTable, identifier, symbol);

    if (symbol != NULL) res = true;

    return res;
}

void insertSymbol(char *identifier) {
    SymbolTableEntry *symbol = calloc(1, sizeof(SymbolTableEntry));
    symbol->identifier = identifier;
    HASH_ADD_KEYPTR(hh, state.symbolTable, symbol->identifier, strlen(identifier), symbol);
}

void freeSymbolTable() {
    SymbolTableEntry *symbol, *tmp;

    HASH_ITER(hh, state.symbolTable, symbol, tmp) {
        HASH_DEL(state.symbolTable, symbol);
        free(symbol);
    }
}