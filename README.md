# irc2-archive

A preservation copy of the original IRC server (`ircd`, the "irc2" line that
began with Jarkko Oikarinen's server in 1988 and is today maintained as
IRCnet's irc2.11), covering releases from **irc2.1.1 (1989)** to
**irc2.11.2p3 (2010)**, including betas, alphas, regional variants and the
loose patches that were distributed alongside them.

The old FTP sites that carry these files are slowly disappearing. This
repository exists so that the source code stays available.

## Layout

| Path | Contents |
| --- | --- |
| `archive/ftp.irc.org/irc/server/` | Mirror of `ftp.irc.org:/irc/server/` — the original tarballs, signatures, patches and notes, byte for byte. |
| `archive/ftp.funet.fi/pub/unix/irc/server/` | Files from `ftp.funet.fi:/pub/unix/irc/server/` that are **not** on ftp.irc.org (e.g. `irc2.9.5b4.tgz`, `irc2.10.2b4.tgz`, admin utilities). |
| `src/<release>/` | Every `irc2*` tarball unpacked, one directory per release, for browsing, grepping and diffing. |
| `SHA256SUMS` | SHA-256 of every file under `archive/` (`cd archive && sha256sum -c ../SHA256SUMS`). |

The files in `archive/` are the authoritative record. The trees in `src/` are
a convenience: the top-level directory of each tarball is stripped, file
ownership and timestamps are not kept, and directories that were empty in a
tarball do not exist in git. `irc2.8.9` and `irc2.9` exist upstream as both
`.tar.gz` and `.tar.Z`; their contents are identical and are unpacked once.

Not mirrored: the `zlib/` directory on ftp.irc.org (an old copy of the zlib
website) and the already-unpacked `irc2.11.2p1/`, `irc2.11.2p2/` and
`irc2.11.2p3/` directories, which duplicate the tarballs. Tarballs that are
not irc2 server releases (`irce`, `LHEx`, `ircII2.02`, the RPMs, the funet
utilities) are kept in `archive/` only and are not unpacked.

Mirrored on 2026-11-16.

## Branches

- **`main`** — pristine, unmodified sources exactly as distributed.
- **`compile-fixes`** — `main` plus minimal changes that make selected old
  releases build on a current Linux system (GCC 14). See `BUILDING.md` on
  that branch. Currently covers `src/irc2.6.2` and `src/irc2.9.5b4`.

## Licence

The IRC server is free software distributed under the GNU General Public
License (version 1 or later for the early releases, version 2 or later for
later ones); see the `LICENCE`/`COPYING`/`doc/LICENSE` file inside each
release. Copyright remains with the original authors — Jarkko Oikarinen, the
University of Oulu Computing Center, and the many contributors named in the
sources. Other items kept in `archive/` carry their own licences.
