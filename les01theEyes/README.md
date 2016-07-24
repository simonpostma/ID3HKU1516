# Les 01 - Do not look in the eyes.
De vraag luid:  "Hoe kan je de instalatie 'Do not look in the eyes' zelf maken ?"

### Nodige hardware
- De stellage
- het beeld met kanalen voor water er in verwerkt
- een waterpomp/spuit systeem

### Software
1. Het programma start en maakt laad alle nodige variabelen in. Ook word de eye-tracking library ingeladen.
2. Het apparaat pakt de videofeed op van de camera.
3. De afbeelding word met behulp van de eye-tracking library bekeken.
4. Er word door de programma loop gecheckt of de persoon naar de juiste plek kijkt.
5. Is dat het geval, dan worden de water spuiten getriggered.
6. Na een timer stoppen de water spuiten en gaat het programma weer in eye-track modus.
