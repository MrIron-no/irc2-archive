# Building the old servers

This branch (`compile-fixes`) carries the smallest set of changes needed to
build selected releases on a current Linux system. Tested with GCC 14.2 on
Debian 13, x86_64. `git diff main compile-fixes -- src/<release>` shows
exactly what was changed relative to the pristine source.

These are decades-old network daemons with known security holes. Build them
for study and nostalgia; do not expose them to the Internet.

## irc2.6.2 (September 1991)

    cd src/irc2.6.2
    $EDITOR include/config.h     # SPATH, CPATH, MPATH, LPATH, PORTNUM, ...
    make

Produces `ircd/ircd` (server) and `irc/irc` (client; needs the curses and
termcap development libraries). The paths compiled in from `config.h`
decide where the server looks for `ircd.conf` and `ircd.motd`;
`doc/example.conf` is the starting point for a configuration.

## irc2.9.5b4 (February 1998)

    cd src/irc2.9.5b4
    ./configure
    cd x86_64-pc-linux-gnu       # the directory name configure reports
    $EDITOR config.h
    make ircd chkconf

Produces `ircd` and `chkconf`. A plain `make` also tries to build the `irc`
client, which does not compile yet. Compressed server links (zlib) are
disabled in this build.
