# Session — 2026-07-13 — ritual-sound-lamp (idea ritual)

> **Status:** `complete`
> **📊 Model:** Claude Opus 4 family. **Venue:** Claude Code (remote), running the idea
> ritual on `ideas/sound-reactive-desk-lamp.md` and landing the result against `main`.

## What this session is doing

Running the idea ritual on the sound-reactive-desk-lamp one-liner — grown in place with
cited research, ending in exactly one verdict, and fixing the truncated H1 title.

- **`ideas/sound-reactive-desk-lamp.md` → ritual** — grow the "printed shade + Arduino mic +
  LED ring desk lamp that reacts to sound" one-liner through all 8 questions with real
  sources: microphone module realities (analog MAX4466 / MAX9814 vs the KY-038 comparator —
  which actually works for music), the honest DSP story on an Uno/Nano-class board (amplitude
  and beat detection vs FFT — arduinoFFT exists but expectations matter), WS2812B
  addressable-LED realities (power budget per LED, level shifting, the big-capacitor +
  resistor rules), and the PRINTED diffuser as the printer crossover (thin-wall white PETG/PLA,
  vase mode — cross-linked to the temperature and retraction guides for clean translucent
  prints).
- **Fix the truncated H1** — the file's title is cut mid-word ("…that reac").
- **Power honesty:** the USB 5 V budget math — how many LEDs before an external supply is
  needed, cited; any external supply gets the standing "check this yourself" note.
- **Safety:** low-voltage USB-first; the microphone reads sound *levels* only (no recording);
  a mains adapter, if the LED count grows, gets a check-yourself flag.

## 💡 Session idea

**One printed "light module," many inputs.** The lamp splits cleanly into two halves — a
*light-output* half (the WS2812B ring + printed diffuser + the capacitor/resistor/shared-ground
and power-budget rules) and an *input* half (the microphone). Build the output half once as a
reusable module and almost any sensor can drive it: the drybox's humidity glowing amber when
filament needs drying ([`filament-drybox-logger.md`](../ideas/filament-drybox-logger.md)), the
spool scale's grams-remaining fading green→red ([`spool-weight-scale.md`](../ideas/spool-weight-scale.md)),
or a print-done pulse. The hard, teachable part — LED power budget, the three wiring
non-negotiables, and a clean translucent print — is identical every time; only "what makes it
change" swaps. So the sound lamp isn't one project: it's the first user of a glanceable-light
output layer the whole workshop can share.

## ⟲ Previous-session review

Predecessor: `.sessions/2026-07-13-ritual-keychains.md` (complete) — the multicolor-keychain-factory
ritual (verdict `build`), which flipped its own "tuned to the 3-color printer" premise to "the
two-color layer-change version any single-nozzle printer can do." This session keeps the same
honest-reframe discipline on a different one-liner: "reacts to sound" hides a loudness-vs-notes
fork, and the ritual lands on the loudness version as the real weekend build while labeling the
per-frequency FFT spectrum as the finicky, ESP32-class stretch. It stays in the printer-crossover
lane — the printed translucent diffuser is the sibling skill to the lithophane guide and idea.
