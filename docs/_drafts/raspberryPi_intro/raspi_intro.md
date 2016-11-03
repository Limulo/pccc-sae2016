## Modelli di rasPi:
* raspberryPi1 mod.A+
* raspberryPi1 mod.B+
* raspberryPi2 mod.B
* raspberryPi3 mod.B
* raspberryPi Zero

-- [pagina su raspberrypi.org](https://www.raspberrypi.org/products/)

## Power Supply
Secondo le specifiche ogni scheda raspberryPi viene alimentata con un trasformatore capace di fornire una _tensione_ di 5V DC.
La _corrente_ richiesta varia da scheda a scheda e dall'uso che se ne deve fare (e.g. se si connette un WiFi dongle, la richiesta di corrente aumenta). Sono richiesti almeno 700mA.

**NB**
Se si conosce il wattaggio del trasformatore si può ottenere la corrente supportata:

**Watt/5V = mA**

## Sistema Operativo
Ad oggi (ottobre 2016) dal sito raspberrypi.org risultano disponibili questi OS:
* Raspbian
* Ubuntu Mate
* Snappy Ubuntu Core
* windows 10 IOTCore
* OSMC
* LibreElec
* PiNet
* RISC OS
* NOOBS -> utility per installare il SO sul raspberryPi utilizzando l'SD card

-- [pagina su raspberrypi.org](https://www.raspberrypi.org/downloads/)

## SD Card

L'SD Card deve essere _class 10_ formattata in _Fat32_.
L'SD Card va formattata usando un tool specifico. Se si desidera ovviare alla linea di comando (tool `dd` su sistemi UNIX -- da maneggiare **CON MOLTA CURA**) si può usare uno strumento software con GUI come _SD Formatter_ 

## Procedura di preparazione della SD card e del SO per l'installazione

+ assicurarsi che l'SD Card sia **class 10**
+ formattare l'SD Card in **Fat32**
+ scaricare **NOOBS** (o qualsiasi altro OS desiderato) dal [sito](https://www.raspberrypi.org/)
+ scompattare l'archivio e trascinare i file estratti (i _files_ **NON** la _cartella_) nell'SD Card appena formattata
+ estrarre l'SD Card dal computer e caricarla sul raspberryPi

Per ciarimenti ed ulteriori opzioni e/o soluzioni, seguire le [istruzioni](https://www.raspberrypi.org/learning/software-guide/)

## Primo avvio

Al primo avvio NOOBS chiederà di scegliere il SO che si desidera installare sul raspberryPi. Selezionare quello desiderato tra quelli presenti e  dare l'avvio al procedimento di installazione (che sovrascriverà l'SD Card -> QUINDI, per avere più OS da poetr provare bisogna avere una SD Card dedicata a ciascun OS)

Una volta installato il sistema operativo, aprire LXTerm e digitare

`sudo apt-get update`
`sudo apt-get upgrade`

**NB**
L'_utente_ base è `pi`, la _password_ è `raspberry`

## Monitor non HDMI

Se si utilizza l'uscita video _composit_, possono verificarsi problemi di visualizzazione a causa delle dimensioni dello schermo.
Per sistemare la problematica si deve accedere al file _/boot/config.txt_ digitando 
`sudo nano /boot/config.txt`
Conoscendo la risoluzione del proprio schermo (wxh), cercare nel file le linee
`#framebuffer_width=1280`
`#framebuffer_height=720`
Rimuovere il simbolo di commento _#_ e inserire la larghezza e l'altezza del proprio schermo.

Un [tutorial](https://learn.adafruit.com/using-a-mini-pal-ntsc-display-with-a-raspberry-pi) sull'argomento.

## Regolare la dimensione dell'immagine a schermo

Se l'immagine a schermo eccede la dimensione dell'area visibile, si deve spegnere la funzione _overscan_.
Lanciare il tool _raspi-config_ da terminale:
`sudo rasppi-config`
Seezionare quindi _Advanced Options_ e ancora _Overscan_

Se il problema di visualizzazione consiste in una banda nera attorno alla figura, si può ridurre o eliminare l'effetto editando il file _/boot/config.txt_:
`sudo nano /boot/config.txt`
Cercare la sezione relativa all'overscan:
`#overscan_left=16`
`#overscan_right=16`
`#overscan_top=16`
`#overscan_bottom=16`
Togliere il simbolo di commento e cambiare il valore usando valori negativi. Provare con -20.

## Overclock

Se la performance del raspberryPi è troppo lenta, si può overclockare la scheda:
`sudo raspi-config`
selezionare _Overclock_ e scegliere una delle opzioni.

**NB**
L'overclock può danneggiare la scheda. **Fare MOLTA attenzione**.

## Gestione dell'utente

Di default si utilizza raspberryPi tramite l'utente creato al momento dell'installazione dal sistema stesso.
L'utente di default è **pi** e la password associata è **raspberry**
Per cambiare la password  usare il tool _raspi-config_
`sudo raspi-config`
Scegliere l'opzione _change___pass_ ed inserire la nuova passeord.

**NB**
si può cambiare la password anche da terminale:
`passwd`
si inserisce la password attuale e quella con la quale si vuole fare cambio. 

## Avvio in Windowing System

Può capitare che in alcune distro per raspberryPi di default è richiesto all'utente di fare log in e lanciare manualmente il desktop.
Se si vuole automatizzare queste operazioni, utilizzare il tool _raspi-config_:
`sudo raspi-config`
Selezionare le opzioni di boot e scegliere la soluzione desiderata.

# NETWORKING 

Per connettere il raspberryPi alla rete, semplicemente connettere con cavo RJ45 il router di casa con la scheda. 
Assicurarsi che il router abbia abilitato l'opzione _DHCP server_. Nel caso, abilitarla.

## Trovare l'indirizzi IP

Per vedere quale indirizzo ip è assegnato al raspberryPi digitare a terminale:

`hostname -I`

questo comando ritorna l'ip locale del raspberryPi.
Per vedere gli indirizzi e le impostazioni per **tutte** le connessioni di cui si dispone (o almeno per le quali c'è dell'hardware predisposto), digitare a terminale

`sudo ifconfig`

## Impostare un ip statico

Per impostare un indirizzo ip fisso si deve ediate il file _/etc/network/interfaces_. Si può visualizzare il contenuto del file digitando

`more /etc/network/interfaces`

Per editare il file

`sudo nano /etc/network/interfaces`

Modificare la voce _dhcp_ in **static** e aggiungere le righe:

`address 192.168.1.10`	l'indirizzo ip che si vuole impostare (in questo caso, come esempio, 192, 168.1.10) 
`netmask 255.255.255.0`	la maschera di sottorete (non cambiare)
`gateway 192.168.1.1`	l'indirizzo del router (in questo caso, come esempio, 192.168.1.1)

Dopo aver scritto le modifiche sul file, rimuovere i DHCP leases, con il comando

`sudo rm /var/lib/dhcp/*`

e quindi riavviare il raspberryPi:

`sudo reboot`.

## Impostare il nome della propria rete

Per cambiare il nome della propria rete dal nome di default _raspberrypi_ si devono modificare due file:

* /etc/hostname
* /etc/hosts

Per prima cosa, editare il file _/etc/hostname_:

`sudo nano /etc/hostname`

e sostituire _raspberrypi_ con il nome di propria scelta (un'unica parola, senza segni d'interpunzione o caratteri non alfanumerici).
Quindi, modificare il file _/etc/hosts_:

`sudo nano /etc/hosts`

Modificare l'ultima riga, dove compare _raspberrypi_ e sostituire con il nome inserito nel file precedente.
Fare un reboot della scheda.

## Impostare una rete wireless

Se si dispone della versione aggiornata di _raspbian_ selezionare il bottone relativo alle interfacce di rete nella barra in alto a destra. Selezionare il propro network e quindi inserire la password.
Se si dispone di una versione non recente di raspbian, utilizzare il tool **WiFi Config**. Tale tool è indispensabile anche se la scheda non è una revision 3, e quindi si deve inserire un WiFi dongle. Il tool si trova nella sezione _Preferences_ del menu _Start_.

Si può creare una rete wireless dal terminale. Per farlo, accedere al file _/etc/network/interfaces_ e trovare la sezione relatina al **wlan0**.
Questa dovrebbe corrispondere a:

	allow-hotplug wlan0
	iface wlan0 inet dhcp
	wpa-roam /etc/wpa___supplicant/wpa_supplicant.conf

La prima riga dice alla scheda di stabilire subito una connessione wifi non appena un WiFi dongle è inserito. 
La seconda riga indica al raspberryPi di allocare un indirizzo ip usando il dhcp. Se si preferisce un indirizzo statico, cambiare _dhcp_ in _static_.  
La terza riga indica dove si trova il file supplicant.

Il file supplicant contiene l' SSID (nome del network) e l'SPK (password) della rete.
Quindi, editare il file /etc/wpa___supplicant/wpa_supplicant.conf:

`sudo nano  /etc/wpa_supplicant/wpa_supplicant.conf`

Modificare i campi _ssid_ e _spk_ del file, quindi fare un reboot della scheda.

## Usare un console cable

In assenza di rete si può utilizzare un console cable per connettere il computer al raspberryPi.
Maggiori informazioni presso il [sito di Adafruit](https://www.adafruit.com/products/954)

**NB**:
Si devono leggere BENE i tutorial e la reference sul sito per capire come utilizzare il cavo e come avviene la comunicazione (TTL - USB).
Ci si dovrà impratichire anche con PuTTY.

## Controllare il raspberryPi con SSH

Per prima cosa, la comunicazione SSH va abilitata sul raspberryPi.
Questo si fa con il tool _raspi-config_:

`sudo raspi-config`

Abilitare la voce **SSH**.

Dal computer (Linux o Mac OS X), digitare

`ssh 192.168.1.10 -l pi`

dove 192,168.1.10 è l'ip assegnato al raspberryPi.
Inserire la password una volta richiesto, e la connessione è stabilita.
Vedi anche questo [tutorial](https://learn.adafruit.com/adafruits-raspberry-pi-lesson-6-using-ssh) sul sito di Adafruit.

## Controllare il raspberryPi con VNC

VNC sta per Virtula Server Connection.
Per usare VNC, si deve installare un server sul raspberryPi e un client su ciascun computer che si vuole utilizzare per la connessione.

Per installare il server su raspberryPi:

	`sudo apt-get update`
	`sudo apt-get install tightvncserver`

Per avviare il server:

`vncserver :1`

La prima volta che il comando viene eseguito, sarà richiesta la creazione di una password per la connessione. 
Per quanto riguarda il client, invece, si può scegliere fra varie opzioni.
**RealVNC** si connette bene con tightvnc ed è disponibile per Linux, OS X e Windows.
Quando richiesto, dal client, l'ip del server a cui connettersi, digitare ":1" dopo l'indirizzo (:1 = mi connetto al display numero 1).
Inserire la password (quella impostata con _vncserver_, **non** quella di login della scheda raspberryPi!).

## RaspberryPi e Mac OS X: file sharing e screen sharing

Per condividere file tra un raspberryPi e Mac OS X, si deve installare sul raspberryPi netatalk:

`sudo apt-get install netatalk`

Nel Mac, nel menu del Finder, segliere GO -> Connect To Server e digitare:

`afp://192.168.1.10` 

e clickare su Connect.
Fare un reboot del raspberryPi.
Viene richiesto il login (**con le credenziali di accesso a raspberryPi, quindi pi come utente e reaspberry come password di default**).
Nel raspberryPi, installare alcune utilities:

`sudo apt.get install avahi-daemon`
`sudo update-rc.d avahi-daemon defaults`

Quindi editare il file /etc/avahi/services/afpd.service

`sudo nano /etc/avahi/services/afpd.service`

e scrivere il seguente codice:

```
<?xml version="1.0" standalone='no'?><!--*-nxml-*-->
<!DOCTYPE service-group SYSTEM "avahi-service.dtd">
<service-group>
	<name replace-wildcards="yes">%h</name>
	<service>
		<type>_afpovertcp._tcp</type>
		<port>548</port>
	</service>
</service-group>
```

Per avviare il demone:

`sudo /etc/init.d/avahi-daemon restart`

---------------------------------------------------------------------------

Per condividere lo schermo del raspberryPi con il Mac, una volta installato VNC, e impostata la condivisione file, editare il file _/etc/avahi/services/rfb.service_

`sudo nano _/etc/avahi/services/rfb.service_`

Inserire nel file il seguente codice:

<?xml version="1.0" standalone='no'?>
<!DOCTYPE service-group SYSTEM "avahi-service.dtd">
<service-group>
	<name replace-wildcards="yes">%h</name>
	<service>
		<type>_rfb._tcp</type>
		<port>5901</port>
	</service>
</service-group>

Quindi avviare il demone:

`sudo /etc/init.d/avahi-daemon restart`

Da Mac è quindi possibile vedere lo schermo del raspberryPi. Quando richiesta la password, utilizzare la password impostata con VNC, **non** quella di login dell'utente du raspberryPi. 
