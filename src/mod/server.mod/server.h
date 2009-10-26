/*
 * server.h -- part of server.mod
 *
 */

#ifndef _EGG_MOD_SERVER_SERVER_H
#define _EGG_MOD_SERVER_SERVER_H

#include "src/binds.h"
#include "src/dcc.h"
#include "src/set.h"

#define DO_LOST 1
#define NO_LOST 0

#define fixcolon(x)             do {                                    \
        if ((x)[0] == ':')                                              \
                (x)++;                                                  \
        else                                                            \
                (x) = newsplit(&(x));                                   \
} while (0)
#define write_to_server(x,y) do {                       \
        tputs(serv, (x), (y));                          \
        tputs(serv, "\r\n", 2);                         \
} while (0)

namespace bd {
  class Stream;
}

struct server_list {
  struct server_list	*next;
  char			*name;
  char			*pass;
  port_t		 port;
};

/* Available net types.  */
enum {
	NETT_EFNET		= 0,	/* EfNet except new +e/+I hybrid. */
	NETT_IRCNET		= 1,	/* Ircnet.			  */
	NETT_UNDERNET		= 2,	/* Undernet.			  */
	NETT_DALNET		= 3,	/* Dalnet.			  */
	NETT_HYBRID_EFNET	= 4	/* new +e/+I Efnet hybrid.	  */
};

#endif		/* _EGG_MOD_SERVER_SERVER_H */

extern bind_table_t	*BT_ctcp, *BT_ctcr, *BT_msgc;
extern size_t		nick_len;
extern bool		trigger_on_ignore, floodless, tried_jupenick, keepnick;
extern int 		servidx, ctcp_mode, answer_ctcp, serv, curserv, default_alines;
extern unsigned int     rolls;
extern port_t		default_port, newserverport, curservport;
extern time_t		server_online;
extern interval_t	cycle_time;
extern char		cursrvname[], botrealname[121], botuserhost[], ctcp_reply[1024],
			newserver[], newserverpass[], curnetwork[], botuserip[], altnick_char;
extern struct server_list *serverlist;
extern struct dcc_table SERVER_SOCKET;
extern rate_t		flood_msg, flood_ctcp, flood_g;

int check_bind_ctcpr(char *, char *, struct userrec *, char *, char *, char *, bind_table_t *);

#define check_bind_ctcp(a, b, c, d, e, f) check_bind_ctcpr(a, b, c, d, e, f, BT_ctcp)
#define check_bind_ctcr(a, b, c, d, e, f) check_bind_ctcpr(a, b, c, d, e, f, BT_ctcr)

bool detect_avalanche(char *);
void server_report(int, int);
void server_init();
void queue_server(int, char *, int);
void server_die();
void add_server(char *);
void clearq(struct server_list *);
void nuke_server(const char *);
bool match_my_nick(char *);
void rehash_server(const char *, const char *);
void replay_cache(int, bd::Stream*);
void join_chans();
void check_hostmask();
void next_server(int *, char *, port_t *, char *);
void server_send_ison();
