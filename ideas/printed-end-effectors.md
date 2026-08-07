# Verwisselbaar gereedschap — uitgevoerd idee

**Status:** uitgevoerd als experimentele projectbasis. De actuele bron staat in
[`projects/effector-mount/README.md`](../projects/effector-mount/README.md).

## Waarom dit idee is gekozen

Eén gemeten polsinterface voorkomt dat elke penhouder, magneethouder of grijper een afwijkend
gatenpatroon krijgt. De waarde zit daarom eerst in de standaardplaat en pas daarna in de
verzameling tools.

## Bouwbesluit

1. meet hoorn, gaten, naaf, schroeven en vrije ruimte met de arm uit;
2. print alleen een dun teststuk van de standaardplaat;
3. valideer herhaalbare montage;
4. bouw één passieve tool en test hem op de werkbank;
5. behandel een servo-aangedreven grijper als een afzonderlijk experiment.

## Open punten

- de werkelijke hoornmaten en polsinterface zijn nog niet in het profiel vastgelegd;
- SCAD-geometrie en tandwielwerking zijn nog niet gerenderd of proefgeprint;
- aanwezigheid, exacte variant en voeding van een extra grijperservo zijn onbekend;
- payload en houdkracht moeten met de echte arm, tool en proefmassa worden gemeten.

Een externe servovoeding moet binnen de specificatie van het exacte servomodel blijven en
worden ontworpen op geverifieerde gegevens plus meting. Dit idee bevat bewust geen universele
spanning-, stroom- of zekeringwaarde.
