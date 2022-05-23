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
__Windows__: Ctrl+Shift+b - per compilare il progetto.
__MacOS X__: Cmd+Shift+b - per compilare il progetto.

## Screenshot del progetto

![La prima stanza](https://user-images.githubusercontent.com/6473175/169802387-07826974-8774-4fdb-aded-b8a1bcdf7138.png)
