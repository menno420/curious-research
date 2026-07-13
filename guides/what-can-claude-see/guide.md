# What can Claude actually see? — turn a photo or error into a fix

**Watch it instead:** open [`index.html`](./index.html) in your browser — it animates this whole
page and lets you flip between three real examples. (On GitHub: tap `index.html` → the **⋯** menu →
*Download*, then open the downloaded file. Or open it in any Codespace/preview.)

## The one idea

If it's on your screen, you can show it to Claude — a **photo**, an **error message** (pasted as
text), or a **screenshot** — and get back the same three things every time:

1. **What it sees** — in plain language.
2. **The likely cause.**
3. **One concrete thing to try** next.

Then you change one thing and ask again. That loop is the whole point.

## Three examples, start to finish

### 1. A failed 3D print (a photo)

1. Take a clear, well-lit photo of the print — get the whole failed area in frame.
2. Start a chat with Claude and **drag the photo in** (or tap the attach/📎 button and pick it).
3. Add one line of context: *"PLA, small printer, this stringing between the two towers — why?"*
4. Claude reads the image and answers, e.g.: *"That's stringing — the nozzle oozes while travelling.
   Likely too little retraction or the hot end a bit hot. Try +1 mm retraction and −5 °C."*
5. Change **one** setting, reprint the test, and show the new photo. Repeat until it's clean.

### 2. A slicer error (pasted text)

1. When your slicer (Cura, PrusaSlicer, etc.) shows a red error, select the text and copy it —
   or screenshot it if you can't select it.
2. Paste it into Claude with: *"My slicer says this — what does it mean and how do I fix it?"*
3. Claude translates the jargon, e.g. *"'Not watertight / open edges' means the model has holes in
   its surface. Run it through a free repair tool, then re-slice."*

### 3. An Arduino / code error (a screenshot)

1. Screenshot the red error bar at the bottom of the Arduino editor (include the highlighted line).
2. Paste or attach it with: *"New to this — what's wrong and where do I fix it?"*
3. Claude points to the exact fix, e.g. *"Missing ';'. The real fix is the line **above** the one it
   flags — add the semicolon there and upload again."*

## Good things to show it (your "when to ask" list)

- A print that failed — stringing, warping, gaps, a blob, spaghetti.
- Any red error text — from your slicer, the Arduino editor, or a terminal.
- A screenshot of a setting you're unsure about: *"is this right for PLA?"*
- A photo of your wiring: *"does this look safe?"* — it flags risks, **you verify the power yourself**.

## Honest limits

- It sees a **still image**, not live video — it can't watch a print happen in real time.
- It can't **measure** exact millimetres or temperatures from a photo; it reasons from what's visible.
- Blurry, dark, or cropped shots give a weaker read. Good light, the whole subject, and any error
  text in frame all help a lot.
- It only knows what you **show and tell** it — always mention the material, the printer, and what
  you already tried.
- A photo is never proof. For anything **mains-powered, hot, or load-bearing**, treat Claude's read
  as a helpful second opinion and **check it yourself**.

**Verify:** open [`index.html`](./index.html), click each of the three example tabs, and press
**Replay** — you should see the input card slide into the "eye", a scan sweep, and a plain-language
diagnosis appear on the right for all three. That's the exact experience you'll get in a real chat.

*Simplification note: the animated "eye" is a friendly picture, not how the model literally works
inside. The three diagnoses shown are realistic examples, not fixed scripts — your real answer adapts
to your exact photo and the details you give.*
