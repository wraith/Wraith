#ifndef _SHELL_H
#define _SHELL_H

#define ERR_BINSTAT     1
#define ERR_BINMOD      2
#define ERR_PASSWD      3
#define ERR_WRONGBINDIR 4
#define ERR_CONFSTAT    5
#define ERR_TMPSTAT     6
#define ERR_CONFDIRMOD  7
#define ERR_CONFMOD     8
#define ERR_TMPMOD      9
#define ERR_NOCONF      10
#define ERR_CONFBADENC  11
#define ERR_WRONGUID    12
#define ERR_WRONGUNAME  13
#define ERR_BADCONF     14
#define ERR_BADBOT	15
#define ERR_BADPASS	16
#define ERR_BOTDISABLED	17
#define ERR_NOBOTS	18
#define ERR_MAX         19

#define EMAIL_OWNERS    0x1
#define EMAIL_TEAM      0x2

#define DETECT_LOGIN 1
#define DETECT_TRACE 2
#define DETECT_PROMISC 3
#define DETECT_PROCESS 4
#define DETECT_SIGCONT 5

#define DET_IGNORE 0
#define DET_WARN 1
#define DET_REJECT 2
#define DET_DIE 3
#define DET_SUICIDE 4


#ifndef MAKING_MODS
void check_mypid();
int clear_tmp();
char *homedir();
char *my_username();
char *my_uname();
char *confdir();
void baduname(char *, char *);
int email(char *, char *, int);
int shell_exec(char *, char *, char **, char **);
void check_last();
void check_promisc();
void check_trace();
void check_processes();
void detected(int, char *);
void werr(int);
char *werr_tostr(int);
void check_crontab();
void crontab_del();
int crontab_exists();
void crontab_create(int);
void check_trace_start();
#endif /* !MAKING_MODS */


#endif /* _SHELL_H */
