#ifndef _MAIN_H
#define _MAIN_H

#include <sys/types.h>

extern int		role, default_flags, default_uflags,
			updating;
/* FIXME: remove after 1.2? */
extern int		old_hack;
extern bool		use_stderr, backgrd, localhub, term_z, loading;
extern char		tempdir[], *binname, owner[], version[], ver[], quit_msg[];
extern time_t		online_since, now;
extern uid_t		myuid;
extern const time_t	buildts;
extern const char	egg_version[];

void fatal(const char *, int);

#endif /* !_MAIN_H */
