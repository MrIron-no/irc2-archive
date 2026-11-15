#ifndef GLOBAL_H
#define GLOBAL_H

#include <stddef.h>  /* for size_t */
#include "struct.h"  /* for aClient, aChannel, aConfItem types */

int mycmp(char *str1, char *str2);
int matches(const char *, const char *);
void sendto_one(aClient *, const char *, ...);
void sendto_serv_butone(aClient *, const char *, ...);
int det_confs_butmask(aClient *, int);
int det_I_lines_butfirst(aClient *);
int ExitClient(aClient *, aClient *, aClient *, char *);
void add_client_to_list(aClient *);
void sendto_common_channels(aClient *, const char *, ...);
void delFromClientHashTable(const char *, aClient *);
void addToClientHashTable(const char *, aClient *);
void sendto_channel_butone(aClient *, aChannel *, const char *, ...);
void sendto_match_butone(aClient *, const char *, int, const char *, ...);
aClient *find_person(char *name, aClient *);
aChannel *find_channel(char *, aChannel *);
void sendto_channel_butserv(aChannel *, const char *, ...);
void sendto_ops_butone(aClient *, const char *, ...);
void sendto_ops(const char *, ...);
int det_confs_butone(aClient *, aConfItem *);
int utmp_open(void);
int utmp_read(int, char *, char *, char *);
void utmp_close(int);
void summon(aClient *, char *, char *);
int make_user(aClient *);
void remove_client_from_list(aClient *);
void debug(int, const char *, ...);
void terminate(void);
int count_channels(aClient *);
void sendto_all_butone(aClient *, const char *, ...);
char *date(long);
void rehash(void);
void *MyMalloc(size_t);
void putline(const char *msg);
int myncmp(char *str1, char *str2, int n);
int free_user(anUser *user);
void restart(void);
#endif
