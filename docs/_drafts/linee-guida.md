# Lezione 1

* IDE
* panoramica schede: Arduino, RasPI, BeagleBone, Panda board, Tensy, 
* tour delle schede (UNO, Mega, YUN, RasPi);

* soldering

sensori
* button --> bounce / LED (accensione spegnimento) --> I/O digitale
* fotoresistore o POT --> partitore resistivo --> I/O analogico --> ADC 10bit
* PIR / IR / US --> distanze e linearizzazione / triangolazione
* accelerometro / compass
* temperatura/umidità (ad esempio LM35, SHT15)
* Flex-bend / force
* mic
* touch --> protocollo I2C / wire Library

I2C per far comunicare più Arduino / calcolo distribuito

comunicazione seriale
* monitor seriale (IDE Arduino)
* terminale
* altri software (Processing/PureData/Node-RED)
* Firmata

Software Serial
* MIDI
* OSC

Protocollo SPI / TTL

da provare
* Raspberry come master --> comunica con I2C --> Arduino come Slave

## TEST da EFFETTUARE
* temperatura e umidità
* LCD
* Bluetooth
* più Arduini che comunicano tra loro usando TX/RX oppure attraverso I2C.

## Appunti per le lezioni

* _Tenere sempre a mente un'impostazione votata al networking delle risorse_
* _

### LEZIONE 1
* Intro: chi siamo, cosa facciamo, cosa vogliamo
* Il progetto di Andrea (cosa? è già definito? è già avviato? quali obiettivi?)
* perchè cominciare con Arduino (citazioni da Upton, Simon Monk ...). 
* Arduino è free software. 
* panoramica scheda e schede. Cenni a Wiring...
* panoramica dei tool di base: breadboard, Jumpers, resistenze (codice colore), LED.
* Arduino IDE (basato su Processing): Text + pulsanti + console. Pulsante serial monitor da tralasciare per ora. Sketch Sketchbook
* linguaggio: libreria di C, usa linguaggio C. REFERENCE on line. Ogni nuovo progetto include due funzioni elencate di default nel teso SETUP & LOOP, ogni pregetto deve usarle. SETUP: condizioni iniziali, di partenza; eseguito una sola volta. LOOP: contiene codice che viene eseguito ciclicamente.
* funzione _delay_ e _delayMicroseconds_.
* cenno a Fritzing (per documentare e condividere, prendere spunto e risolvere problematiche) disegnare e schematizzare.
* Led onboard sul pin 13: metodi _pinMode_, _digitalWrite_. eventuale definizione di costante _const_ o direttiva _#define_. 
* Led esterno, come scegliere la resistenza --> LED (legge di kirkoff, _forward voltage/current_) e datasheet
* primi esperimenti con breadboard, circuito base _LED + resistore in serie_.
* code blocks, variabili, variable scope, 
* push button: eseprimenti per accendere e spegnere un LED. il **mode** dovrà essere _INPUT_, il bottone invierà info sulla tensione cui si trova il punto di prelievo. funzione _pinMode( [...], INPUT)_, _digitalRead_.
* circuito con solo il pushbutton premuto --> lettura **LOW**
* PROBLEMA: se rilascio non leggo sempre **HIGH**, quello che mi aspetterei --> dovuto al cosidetto **floating**
* SOLUZIONE: utilizzare una configurazione circuitale di **PULL UP** oppure di **PULL DOWN**. 
* ripetere l'esercizio con la nuova configurazione.
* debounce (utilizzo di un tempo di attesa _delay_)
* sensore Tilt: altro tipo di interruttore.
* **PAUSA CAFFE'**
* Firmata: cos'è (ref. http://www.firmata.org/wiki/Main_Page , https://github.com/firmata/protocol)
* protocollo di comunicazione tra microcontrollers e software su computer/tablet/... . I messaggi si basano sullo standard MIDI. Uso prevalente di sysex perchè non limitati in numero di bytes per il messaggio.
* Librerie Client per tanti software (max, PD)
* Funzionamento di Firmata: loading della libreria su Arduino (come fosse uno sketch) e connessione tramite client apposito sul software con cui comunicare.
* Sketch di esempio: Arduino2PureData e Arduino2Processing

### LEZIONE 2
* riferimenti a standard OSI
* Comunicazione Seriale + lettura di un sensore analogico (potenziometro / fotoresistore / accelerometro) su monitor seriale
* scrittura analogica LED e PWM
* esercizio di potenziometro che regola la luminosità di un LED via PWM
* comunicazione seriale avanzata: Arduino in comunicazione con altri programmi senza l'utilizzo del protocollo Firmata
* Lettura e scrittura su sensori avanzati
* Accelerometro
* US e range definition
* IR + linearizzazione
* i2c: accenni alla comunicazione i2c 
* i2c: esempio1: capboard
* i2c: esempio2: display LED

### LEZIONE 3
* RasPi: panoramica del sistema
* RasPi: quale versione e quale modello?
* terminale: comandi base
* shell scripting base (shebang)
* python: quale versione?
* IDLE vs Terminale vs editor
* pip
* libreria RPi.GPIO
* primi programmini in python (hello world, LED, bottone,...)
* tipologie di comunicazione viste in Arduino trasportate su RasPi

### LEZIONE 4
* replica degli esperimenti fatti nella lezione 1/2 su RasPi
* pianificazione di operazioni definite per il progetto

 --- 

## links
* https://circuits.io/lab/
