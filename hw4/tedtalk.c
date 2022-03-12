// File: tedtalk.c 
// 
// Description: Representation of a TEDtalk
// @author      RIT CS Instructors
// @author      Omar Ramirez olr8350 
// // // // // // // // // // // // // // // // // // // // // // // // 

//
// Content supplied to the student.
//

#include <stdio.h>
#include <string.h>

#include "EventTime.h"

// TEDtalk structure must be defined before the include is private to the .c.

struct TEDtalk {                 ///< private TEDtalk structure
     char  * speaker;            ///< speaker/presenter of the talk
     char  * title;              ///< title of the talk
     EventTime_t * last_played;  ///< pointer to the last play time of talk
};

// Note: TEDtalk_t typedef defined in the .h file depends on struct TEDtalk

#include "tedtalk.h"

/// Initialize a TEDtalk_t structure with the given values.

TEDtalk_t * new_TEDtalk(char * t, char * a) {

    TEDtalk_t * m = NULL;
 
    m = malloc(sizeof(TEDtalk_t));

    m->speaker = malloc(strlen(a) + 1);
    strcpy(m->speaker, a);

    m->title = malloc(strlen(t) + 1);
    strcpy(m->title, t);

    m->last_played = NULL;

    return m;
}

/// delete the talk

void tedtalk_delete(TEDtalk_t * m) {

    //speaker
    free(m->speaker);
    //title
    free(m->title);
    //time
    if (NULL != m->last_played) {
        time_delete(m->last_played);
    }
}

/// get the talk's speaker

char * tedtalk_get_speaker( const TEDtalk_t * m) {
    char * tmp = NULL;
    tmp = malloc(strlen(m->speaker)+1);
    strcpy(tmp, m->speaker);
    return tmp;
}

/// get the talk's title

char * tedtalk_get_title( const TEDtalk_t * m) {
    char * tmp = NULL;
    tmp = malloc(strlen(m->title)+1);
    strcpy(tmp, m->title);
    return tmp;
}

/// get the talk's last play time

EventTime_t * tedtalk_get_last_played( const TEDtalk_t * m) {
    EventTime_t * tmp = NULL;
    tmp = time_copy(m->last_played);
    return tmp;
}

/// play or show the talk

void tedtalk_play(TEDtalk_t * m, EventTime_t * t) {
    if (NULL != m->last_played) {
        free(m->last_played);
    }
    m->last_played = t;
}

/// compare 2 instances for equivalence (equivalent field values)

bool tedtalk_equals( const TEDtalk_t * m, const TEDtalk_t * o) {
    // Two tedtalks are equal if their titles and speakers are equal
    if ((NULL != m) && (NULL != o)) {
        if ((0 == strcmp(m->speaker, o->speaker)) &&
            (0 == strcmp(m->title, o->title))) {
            return true;
        }
    }
    return false;
}

/// make a complete, deep copy of the talk
/// when making copy, use strlen with malloc
TEDtalk_t * tedtalk_copy( const TEDtalk_t * m) {
    TEDtalk_t * d = NULL;
    EventTime_t * tmp = NULL;

    d = malloc(sizeof(TEDtalk_t));

    //strlen malloc should be used instead of sizeof
    d->speaker = malloc(strlen(m->speaker) + 1);
    strcpy(d->speaker, m->speaker);

    //strlen malloc should be used instead of sizeof
    d->title = malloc(strlen(m->title) + 1);
    strcpy(d->title, m->title);

    if (NULL != m->last_played) {
        // copy the last played
        tmp = time_copy(m->last_played);
        d->last_played = tmp;
    } else {
        // set last_played to NULL
        d->last_played = NULL;
    }

    return d;
}

/// create a string representation

char * tedtalk_to_string( const TEDtalk_t * m) {
    char * sstr = NULL;
    char * st = NULL;
    char * sd = NULL;
    char * tt = NULL;
    int len = 0;

    st = tedtalk_get_title(m);
    sd = tedtalk_get_speaker(m);

    // calculate the total string length needed.
    len = strlen("Title: ") + strlen(st) +
                  strlen("  Speaker: ") + strlen(sd) + 1;

    if (NULL != m->last_played) {
        tt = time_to_string(m->last_played);
        len += strlen(" at ") + strlen(tt);
    }

    // allocate enough space for the tedtalk
    sstr = malloc( len );

    sprintf(sstr, "Title: %s  Speaker: %s", st, sd);

    if (NULL != m->last_played) {
        sstr = strcat(sstr, " at ");
        sstr = strcat(sstr, tt);
    }

    free(sd);
    free(st);
    free(tt);
    return sstr;
}

