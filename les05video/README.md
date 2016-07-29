# Les 05 - Video.

De vraag luid:  "Hoe kan je de instalatie 'Swarm' zelf maken ?"

### Nodige hardware
- De opstelling van hangende lamp bollen
- Met in deze bollen LED lichten, het lieft NeoPixels
- Welke op een arduino zit aangesloten. Deze arduino staat in contact met OpenFrameworks.
- Een Kinect of dergelijk apparaat voor de registratie van gebruikers

### Software
Als ik mij niet vergis is het zo dat, ookal lijkt het geheel een verzameling losse bollen, dat de individuele bollen bij wijze van spreken een enkele gekleurde pixel zouen kunnen representeren in een pixel raster. Door het programma op deze manier op te zetten denk ik dat het mogelijk is om op een intuitievere manier de vele bollen te benaderen en samen te laten werken om een patroon te genereren. Zodoende zou de installatie kleur animaties kunnen afspelen op basis van video/beeld input, maar ook door de software gegenreerde patronen en effecten. 

1. De software speelt de 'idle' programmering af, een stuk code wat diverse mooie kleurpatronen laat zien.
2. De kinect neemt de omgeving van de opstelling waar en speelt deze informatie door naar OF.
3. OF analyseert het beeld en herkent eventuele personen, en indien zij aanwezig zijn, waar zij zich bevinden ten opzichte van de installatie.
4. OF beinvloed de kleurpatronen, binnen een bepaalde radius treed er verandering van het licht op, met de lokatie van de geregistreerde gebruiker(s) als oorsprong(en)
5. Waneer er geen gebruiker meer opgepikt word door de Kinect gaat de installatie terug naar het afspelen van de idle programering, totdat de Kinect weer iemand ziet.
