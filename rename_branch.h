//
// Created by terry on 10/13/20.
//

#ifndef GITME_RENAME_BRANCH_H
#define GITME_RENAME_BRANCH_H

#include <string>
#include <iostream>

#include "gitme_type.h"

int rename_branch(const args_table_type &args_table) {
    arg args[] = {
            {"-old-branch",       "",
                                               "optional parameter:" SP LIGHT_GREEN
                                               "old-branch " NC SP
                                               "the old branch to be renamed <default: " LIGHT_PURPLE"current git branch" NC">",
                    arg::optimistic_validate},
            {"-new-name",         "",
                                               "parameter required:" SP ORANGE
                                               "new-name   " NC SP
                                               "the new branch name"
            },
            {"-force",            "false",
                                               "optional parameter:" SP LIGHT_GREEN
                                               "force      " NC SP
                                               "Should it be forced to rename if a branch with the same name as the new name already exists?"
                                               "(" LIGHT_BLUE"true/false" NC") <default: " LIGHT_PURPLE"false" NC">",
                    arg::bool_validate},
            {HELP,                "not-empty", "",
                    arg::optimistic_validate,
                    true},
            {"-" STRICT_MODE_RAW, "on",
                                               "mode parameter:    " SP LIGHT_RED
                                               STRICT_MODE_RAW NC SP
                                               "if on, all the optional parameters are mandatory"
                                               "(" LIGHT_BLUE"on/off" NC") <default: " LIGHT_PURPLE"on" NC">",
                    arg::mode_validate,
                    true}
    };
    PROCESS(args, args_table, 3, 4)
    // ====== Generate git command
    const char *force_flag;
    if (args[2].value == "true")
        force_flag = "-M";
    else
        force_flag = "-m";
    std::string res;
    res.append("git branch ").append(force_flag).append(" ").append(args[0].value).append(" ").append(args[1].value);
    // ===========================
    EXE_GIT(res)
}

#endif //GITME_RENAME_BRANCH_H
