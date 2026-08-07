# `site/` — openbare Nederlandse ingang

**Live:** <https://menno420.github.io/curious-research/>

De site is statisch en alleen-lezen. Voeg geen tokens, uploadformulier of schrijffunctie toe;
alles in GitHub Pages is publiek. De repositorybestanden blijven de bron van waarheid.

`github-en-ai.html` is de publieksroute om dezelfde werkplaatscontext aan Claude of ChatGPT te
geven. De pagina dupliceert het profiel niet: zij laadt
`docs/workshop-profile.md` rechtstreeks vanaf de `main`-branch en biedt een kopieerbare fallback.

## Bestanden

| Bestand | Functie |
|---|---|
| `index.html` | Gidsen per werkplaatstype, zonder handmatig totaal aantal |
| `projecten.html` | Uitleg, onderdelen, bouwroute en test vóór links naar projectbroncode |
| `kennis.html` | Korte kenniskaarten uit één `KENNIS`-object met vijf bewijsniveaus |
| `style.css` | Gedeelde vormgeving zonder framework of buildstap |

De kaarten in `kennis.html` worden dynamisch geteld. Gidsinventaris wordt beheerd in
`guides/README.md`; kopieer geen totaalaantal naar de site.

## Een gids toevoegen

Voeg aan de juiste sectie van `index.html` een kaart toe:

```html
<a class="kaart" href="guides/<slug>/index.html">
  <span class="icoon">🛠️</span>
  <h3>Nederlandse titel</h3>
  <p>Welk probleem de maker hiermee uitvoert en controleert.</p>
  <span class="merk nl">Uitvoeringsgids</span>
</a>
```

De live site plaatst `guides/` naast `index.html`. Voor een lokale preview die dezelfde structuur
gebruikt:

```bash
preview_dir=$(mktemp -d)
cp -r site/. "$preview_dir/"
cp -r guides "$preview_dir/guides"
python3 -m http.server --directory "$preview_dir" 8000
```

## Publicatie

`.github/workflows/pages.yml` assembleert `site/` en `guides/` en publiceert na wijzigingen op
`main`, via handmatige dispatch of de geplande vangnetrun. Controleer na merge de echte openbare
URL; een groene linkcheck bewijst alleen de repositorystructuur, niet dat de nieuwste Pages-run
al live staat.

De repository moet bij GitHub Pages eenmalig **Settings → Pages → Build and deployment → GitHub
Actions** hebben ingeschakeld. De workflow hoort die beheerdershandeling niet te omzeilen.
