# curious-research · inbox

> ORDERS to this Project. **ONE writer: the manager** — never edit this file. Report order
> progress in `control/status.md` (`orders: acked=… done=…`). Protocol: `control/README.md`.

## ORDER 001 · 2026-07-13T10:02Z · status: new
priority: P2
executor: curious-research seat (next wake)
from: NIGHT REPORT REQUEST — owner ask 2026-07-13 (relayed via Fleet Manager)
do: post a THOROUGH night report, window 2026-07-12T22:30Z→now, to control/status.md AND your outbox (manager-addressed; this repo has no control/outbox.md yet — create it per the fleet convention, lane-written append-only, or fold the manager-addressed section into status.md and say so): SHIPPED (merges/PRs, numbers+SHAs) · OPEN PRs + check states (name the green-parked set) · ORDERS served + outstanding · asks pending · STALLS/denials verbatim · wake-chain health · next-3.
why: owner morning review.
done-when: report in both files; Fleet Manager compiles the roll-up.
provenance: filed by Fleet Manager on the owner's live ask 2026-07-13 ~09:55Z; first order in this inbox (header-only at HEAD d847874). Delivered as a parked PR rather than a direct Contents-API append because this repo's main carries a required-check ruleset (status.md: owner fixed the check name ~01:35Z).

## ORDER 002 · 2026-07-13T22:29Z · status: new
priority: P1
executor: curious-research seat (tonight)
from: OWNER LIVE in the coordinator chat, 2026-07-13 ~22:25Z — landed verbatim by the coordinator per the owner-live-turn doctrine (an owner turn is the top ORDER; inbox threads are the durable record). Kickoff text follows verbatim:
> **EAP FINAL NIGHT — OWNER KICKOFF (2026-07-13). This is a live owner turn: start now and run all night.**
> 1. **HARD-SYNC** every repo your seat owns: `git fetch origin main && git reset --hard origin/main` (dirty tree → rescue-branch first). Read `control/inbox.md` at HEAD in FULL.
> 2. **Your NIGHT ORDER is there** — delivered tonight by the Fleet Manager (status: new, provenance: owner directive 2026-07-13, citing fleet-manager `docs/eap-final-night-worklists-2026-07-13.md`). Ack it in your inbox thread, then work the list **top-down, one slice per PR**: claim → born-red card as first commit → PR READY immediately → flip complete last. Open PRs stay open; land on green where automation arms; never hand-merge your own PR.
> 3. **Run CONTINUOUS (Q-0265):** slice done + list remains → start the next slice the same turn. Re-arm your ~15-min pacemaker every working turn; verify your failsafe cron is armed and bound to your live session (worker-relay if walled) so the chain survives to morning.
> 4. **Rails hold:** CI green is the merge floor; deny-wins is terminal per action; no secrets anywhere; your seat's scope rules apply. A genuinely blocked item becomes a six-field owner-queue ask — then move to the next item; never end the night "waiting".
> 5. **Heartbeat per item** in `control/status.md` (coordinator-only, wholesale overwrite) as you go — honest nulls and honest failures are deliverables. If your inbox has NO night ORDER at HEAD, report that as a headline to the fleet-manager outbox and work your seat's standing mission ladder instead.
> **Done-when (by morning):** every list item is shipped, parked green with a cited reason, or honestly reported blocked — with the trail in your heartbeat and session cards. Make it a productive final EAP night.
coordinator-finding: the referenced Fleet-Manager night ORDER was NOT at HEAD when read (2026-07-13T22:29Z, HEAD a9fd5fa), and fleet-manager docs/eap-final-night-worklists-2026-07-13.md (fetched raw, HTTP 200) contains NO curious-research section — proceeding per §5: headline to outbox + standing mission ladder.
