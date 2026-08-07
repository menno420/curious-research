# ============================================================================
#  teststrip.py  --  een Fusion 360-script dat een pas-teststrip maakt
#  Onderdeel van: curious-research / guides/fusion-python
# ----------------------------------------------------------------------------
#  WAT DIT MAAKT
#  Een plat strookje met een rij gaten erin. Elk gat is een beetje ruimer dan
#  het vorige. Print het, duw er een pennetje van 5 mm doorheen, en kijk welk
#  gat lekker past. Dat getal is de speling die JOUW printer nodig heeft -- en
#  vanaf dan passen al je onderdelen in een keer goed.
#
#  WAAROM DIT EEN GOED EERSTE SCRIPT IS
#  Zes gaten met steeds 0,05 mm verschil teken je met de muis in een kwartier,
#  en dan wil je het nog aanpassen ook. Hier verander je een getal en druk je op
#  Run. Dat is het hele punt van scripten: niet moeilijker doen, maar het saaie
#  werk wegnemen.
#
#  HOE JE HEM DRAAIT: zie guide.md in deze map. Kort:
#      Utilities -> ADD-INS -> Scripts and Add-Ins -> + -> Script + Python
#      -> "Edit in code editor" -> deze code erin plakken -> opslaan -> Run
# ============================================================================

import adsk.core
import adsk.fusion
import traceback


# ---------------------------------------------------------------------------
#  DRAAI HIER AAN. Alles in millimeters -- zoals je gewend bent.
# ---------------------------------------------------------------------------

BREEDTE_MM = 78.0      # lengte van het strookje
HOOGTE_MM  = 20.0      # breedte van het strookje
DIKTE_MM   = 3.0       # hoe dik het geprint wordt

PEN_MM = 5.0           # de maat van het pennetje dat erdoorheen moet

# De spelingen die je wilt uitproberen, in millimeters. Gat 1 is het krapst.
# Voeg er gerust een toe of haal er een weg -- het strookje past zich aan.
SPELINGEN_MM = [0.10, 0.15, 0.20, 0.25, 0.30, 0.40]


# ---------------------------------------------------------------------------
#  DE VALKUIL WAAR IEDEREEN IN TRAPT
#
#  Fusion rekent van binnen in CENTIMETERS. Niet in millimeters, ook al staat
#  je scherm op mm. Zeg je in een script "10", dan bedoelt Fusion 10 cm.
#
#  Daarom staat overal `* MM` achter een maat: dat rekent jouw millimeters om
#  naar wat Fusion verwacht. Vergeet je dat een keer, dan komt er een object
#  uit dat tien keer te groot is. Dat is niet stuk -- dat is deze regel.
# ---------------------------------------------------------------------------
MM = 0.1               # 1 mm = 0,1 cm


def run(context):
    ui = None
    try:
        app = adsk.core.Application.get()
        ui = app.userInterface

        design = adsk.fusion.Design.cast(app.activeProduct)
        if not design:
            ui.messageBox(
                'Dit script wil een Design om in te tekenen.\n\n'
                'Maak eerst een nieuw bestand (File -> New Design) en draai het dan opnieuw.'
            )
            return

        root = design.rootComponent

        # -- 1 - het strookje zelf ------------------------------------------
        # Een schets op het platte vlak, daarin een rechthoek, en die omhoog
        # trekken tot een echt blokje. Precies wat je met de muis ook zou doen.
        schets = root.sketches.add(root.xYConstructionPlane)
        schets.name = 'omtrek'

        schets.sketchCurves.sketchLines.addTwoPointRectangle(
            adsk.core.Point3D.create(0, 0, 0),
            adsk.core.Point3D.create(BREEDTE_MM * MM, HOOGTE_MM * MM, 0)
        )

        extrudes = root.features.extrudeFeatures
        invoer = extrudes.createInput(
            schets.profiles.item(0),
            adsk.fusion.FeatureOperations.NewBodyFeatureOperation
        )
        invoer.setDistanceExtent(
            False, adsk.core.ValueInput.createByReal(DIKTE_MM * MM)
        )
        extrudes.add(invoer)

        # -- 2 - de gaten ----------------------------------------------------
        # Een tweede schets met alle cirkels erin, en die er in een keer
        # doorheen snijden. Alle gaten in een enkele bewerking: sneller, en je
        # boom in Fusion blijft overzichtelijk.
        gaten = root.sketches.add(root.xYConstructionPlane)
        gaten.name = 'gaten'

        aantal = len(SPELINGEN_MM)
        vak = BREEDTE_MM / aantal          # elk gat krijgt een even breed vak
        midden_y = HOOGTE_MM / 2.0

        for i, speling in enumerate(SPELINGEN_MM):
            # Het gat is de pen plus de speling. Speling zit rondom, dus de
            # diameter groeit met de hele speling, niet met de helft.
            diameter = PEN_MM + speling
            x = (i + 0.5) * vak

            gaten.sketchCurves.sketchCircles.addByCenterRadius(
                adsk.core.Point3D.create(x * MM, midden_y * MM, 0),
                (diameter / 2.0) * MM
            )

        # Alle cirkelprofielen verzamelen en in een keer wegsnijden.
        profielen = adsk.core.ObjectCollection.create()
        for i in range(gaten.profiles.count):
            profielen.add(gaten.profiles.item(i))

        snij = extrudes.createInput(
            profielen, adsk.fusion.FeatureOperations.CutFeatureOperation
        )
        # "Helemaal doorheen", zodat het klopt ook als je DIKTE_MM aanpast.
        snij.setAllExtent(adsk.fusion.ExtentDirections.PositiveExtentDirection)
        extrudes.add(snij)

        # -- 3 - vertel wat er gemaakt is ------------------------------------
        regels = ['Teststrip klaar. Gaten van links naar rechts:', '']
        for i, speling in enumerate(SPELINGEN_MM):
            regels.append(
                '  {}.  speling {:.2f} mm   ->  gat {:.2f} mm'.format(
                    i + 1, speling, PEN_MM + speling
                )
            )
        regels.append('')
        regels.append('Print hem plat, en duw er een pen van {:.1f} mm doorheen.'.format(PEN_MM))
        regels.append('Het eerste gat dat soepel past is jouw speling.')
        ui.messageBox('\n'.join(regels))

    except:  # noqa: E722  -- Fusion wil alles vangen, anders zie je niets
        if ui:
            ui.messageBox('Er ging iets mis:\n{}'.format(traceback.format_exc()))
