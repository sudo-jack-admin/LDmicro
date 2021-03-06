#include <htc.h>

// Initialisation avec calcul des predivision I�C
// fcpu : frequence du microcontroleur
// ftwi : frequence souhaitee pour le bus I2C
void I2C_Init(long fcpu, long ftwi);

// Initialisation I�C master
// prescaler : valeur des bits du registre TWSR pour s�lection du prescaler
// ces param�tres d�terminent la fr�quence de l'horloge I�C
void I2C_MasterInit(char prescaler);

// Envoi de la s�quence de start + adresse de l'esclave
// adresse : adresse de l'esclave avec lequel d�marrer la communication
// mode= 1 si lecture et 0 si �criture
int I2C_MasterStart(char adresse, int mode);

// Envoi de la s�quence de restart + adresse de l'esclave
// adresse : adresse de l'esclave avec lequel d�marrer la communication
// mode= 1 si lecture et 0 si �criture
int I2C_MasterRestart(char adresse, int mode);

// Envoi de la s�quence stop
void I2C_MasterStop(void);

// Ecriture d'un octet sur le bus
// donnee : l'octet � �crire
int I2C_MasterWrite(char c);

// Lecture d'un octet sur le bus avec acknowledge � la fin 
// pour indiquer � l'esclave que la lecture n'est pas termin�e
// Renvoie la donn�e lue
char I2C_MasterReadNext(void);

// Lecture d'un octet sur le bus sans acknowledge � la fin
// pour indiquer � l'esclave que la lecture est termin�e
// (doit �tre suivi par un stop)
// Renvoie la donn�e lue
char I2C_MasterReadLast(void);

// Fonction � usage interne
void I2C_MasterWait(void);

// Lecture d'une valeur dans registre (reg) sur peripherique (addr)
char I2C_MasterGetReg(char addr, char reg);

// Ecriture d'une valeur dans registre (reg) sur peripherique (addr)
void I2C_MasterSetReg(char addr, char reg, char val);
void I2C_MasterSetLcdReg(char addr, char reg, char val);

