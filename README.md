# Project Sagittarius

Repository per la base di un gioco a visuale dall'alto (simil Pokémon o Zelda).
Il linguaggio usato è C++ con le librerie [SDL2](https://www.libsdl.org/download-2.0.php), [TinyXML](https://www.grinninglizard.com/tinyxml2/index.html) (per il caricamento delle mappe), e il software [Tiled](https://www.mapeditor.org) per creare le mappe.

Il progetto è stato creato con l'editor [Visual Studio Code](https://code.visualstudio.com).

### Windows
Per compilare il progetto con Windows è necessario solo il toolchain di compilazione MinGW (g++), tutte le risorse e le librerie dipendenti al progetto sono già inclusi all'interno della cartella

### Mac OS X 
Per compilare il progetto con MacOs X è necessare che gli strumenti sviluppatore di XCode siano installati sulla macchina.
Scaricare le varie dipendenze tramite [homebrew](https://brew.sh)
SDL2:
```bash
brew install SDL2
```
SDL2_image:
```bash
brew install SDL2_image
```

Una volta scaricate tutte le dipendenze basterà semplicemente usare le shortcut di Visual Studio Code per compilare ed eseguire il progetto. (I tasks JSON di Visual Studio sono stati già impostati per entrambi i sistemi).

F5 - per eseguire il progetto.

_Windows_: Ctrl+Shift+b - per compilare il progetto.

_MacOS X_: Cmd+Shift+b - per compilare il progetto.

## Recuperare il progetto con Visual Studio Code
1. Copiare il link del progetto:
![LinkProgetto](https://user-images.githubusercontent.com/6473175/169806672-3b186dbf-e59b-405d-aa3c-089aefe2429b.png)

2. Avviare Visual Studio Code e cliccare su _Clona Repository_:
![ClonaRepository](https://user-images.githubusercontent.com/6473175/169806732-282657fd-a658-4c68-aae4-bc616eae2cab.png)

3. Incollare il link del progetto:
![LinkCopiato](https://user-images.githubusercontent.com/6473175/169808151-8274dfc1-dd81-4c34-9b1a-19cb3d163bb1.png)

4. Selezionare la posizione dove Visual Studio Code salverà il progetto:
![SalvaProgetto](https://user-images.githubusercontent.com/6473175/169808088-adb5a413-cff5-46ac-b628-89fae5684eef.png)

## Screenshot del progetto

![La prima stanza](https://user-images.githubusercontent.com/6473175/169802387-07826974-8774-4fdb-aded-b8a1bcdf7138.png)
_Gli uffici sembrano molto fighi in 2D_

![Tiled](https://user-images.githubusercontent.com/6473175/169808323-cca0e54a-c2e4-470d-832a-a84470b1fa3b.png)
_Tiled è uno strumento fondamentale per la creazione delle mappe_
