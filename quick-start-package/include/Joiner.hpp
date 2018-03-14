#pragma once
#include <vector>
#include <cstdint>
#include <sys/time.h>
#include "Relation.hpp"
#include "Parser.hpp"
#include "table_t.hpp"

/*
 * Prints a column
 * Arguments : A @column of column_t type
 */
void PrintColumn(column_t *column);


class Joiner {

    std::vector<Relation> relations;  // The relations that might be joined

    public:
    /* do the checksum */
    uint64_t check_sum(SelectInfo &sel_info, table_t *table);

    /* Initialize the row_id Array */
    void RowIdArrayInit(QueryInfo &query_info);

    // Add relation
    void addRelation(const char* fileName);

    // Get relation
    Relation& getRelation(unsigned id);

    // Get the total number of relations
    int getRelationsCount();

    table_t*  CreateTableTFromId(unsigned rel_id, unsigned rel_binding);
    column_t* CreateColumn(SelectInfo& sel_info);
    void      construct(table_t *table, column_t *column);
    table_t*  low_join(table_t *table_r, column_t *c_r, table_t *table_s, column_t *c_s);

    // The select functions
    void Select(FilterInfo &sel_info, table_t *table);
    void SelectEqual(table_t *table, column_t *column, int filter);
    void SelectGreater(table_t *table, column_t *column, int filter);
    void SelectLess(table_t *table, column_t *column, int filter);

    // Joins a given set of relations
    void join(QueryInfo& i);
    table_t* join(table_t *table_r, table_t *table_s, PredicateInfo * pred_info);
    table_t* SelfJoin(table_t *table, PredicateInfo *pred_info);

    //table_t* radix_join(table_t *table_left, column_t *column_left, table_t *table_right, column_t *column_right);

};
